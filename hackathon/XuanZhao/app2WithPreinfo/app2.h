#ifndef APP2_H
#define APP2_H


#include <v3d_interface.h>

#include "imgpreprocess.h"

struct paraApp2
{
    Image4DSimple * p4dImage;
    int xc0, xc1, yc0, yc1, zc0, zc1; //the six bounding box boundaries
    LandmarkList landmarks;

    bool is_gsdt;
    bool is_coverage_prune;
    bool is_break_accept;
    int  bkg_thresh;
    double length_thresh;
    int  cnn_type;
    int  channel;
    double SR_ratio;
    int  b_256cube;
    bool b_RadiusFrom2D; //how to estimate radius of each reconstruction node, from 2D plane (for anisotropic case) or 3D (for isotropic case)
    int b_resample;
    int b_intensity;
    int b_brightfiled;
    bool s2Mode;

    bool b_menu;

    NeuronTree result;

    paraApp2() {

        p4dImage = NULL;
        xc0 = xc1 = yc0 = yc1 = zc0 = zc1 = 0;
        landmarks.clear();

        is_gsdt = false; //true; change to false by PHC, 2012-10-11. as there is clear GSDT artifacts
        is_coverage_prune = true;
        is_break_accept = false;
        bkg_thresh = 10; //30; change to 10 by PHC 2012-10-11
        length_thresh = 5; // 1.0; change to 5 by PHC 2012-10-11
        cnn_type = 2; // default connection type 2
        channel = 0;
        SR_ratio = 3.0/9.0;
        b_256cube = 1; //whether or not preprocessing to downsample to a 256xYxZ cube UINT8 for tracing
        b_RadiusFrom2D = true;
        b_resample = 1;
        b_intensity = 0;
        b_brightfiled = 0;
        b_menu = true;
    }

    bool initialize(V3DPluginCallback2 &callback)
    {
        v3dhandle curwin = callback.currentImageWindow();
        p4dImage = callback.getImage(curwin);
        if (!p4dImage)
        {
            v3d_msg("The input image is NULL. Do nothing.");
            return false;
        }
        landmarks = callback.getLandmark(curwin);
        V3DLONG in_sz0[4] = {p4dImage->getXDim(), p4dImage->getYDim(), p4dImage->getZDim(), p4dImage->getCDim()};

        V3DLONG view3d_datasz0, view3d_datasz1, view3d_datasz2;
        View3DControl * view3d = callback.getView3DControl(curwin);
        if (!view3d)
        {
            v3d_msg("The view3d pointer is NULL which indicates there is no 3D viewer window open, thus set the cut-box as max.",0);

            xc0 = 0;
            xc1 = in_sz0[0]-1;

            yc0 = 0;
            yc1 = in_sz0[1]-1;

            zc0 = 0;
            zc1 = in_sz0[2]-1;
        }
        else
        {
            view3d_datasz0 = view3d->dataDim1();
            view3d_datasz1 = view3d->dataDim2();
            view3d_datasz2 = view3d->dataDim3();

            xc0 = int(double(view3d->xCut0()) * in_sz0[0] / view3d_datasz0 + 0.5);
            xc1 = int(double(view3d->xCut1()) * in_sz0[0] / view3d_datasz0 + 0.5);
            if (xc1>in_sz0[0]-1) xc1 = in_sz0[0]-1;
            //xc1 = in_sz0[0]-1;//for debug purpose. 130102

            yc0 = int(double(view3d->yCut0()) * in_sz0[1] / view3d_datasz1 + 0.5);
            yc1 = int(double(view3d->yCut1()) * in_sz0[1] / view3d_datasz1 + 0.5);
            if (yc1>in_sz0[1]-1) yc1 = in_sz0[1]-1;

            zc0 = int(double(view3d->zCut0()) * in_sz0[2] / view3d_datasz2 + 0.5);
            zc1 = int(double(view3d->zCut1()) * in_sz0[2] / view3d_datasz2 + 0.5);
            if (zc1>in_sz0[2]-1) zc1 = in_sz0[2]-1;

            //printf("%5.3f, %5.3f, %5.3f\n", float(view3d->xCut1()), float(in_sz0[0]), float(view3d_datasz0));
        }

        if(landmarks.size()>0)
        {
            LocationSimple t;
            for(int i = 0; i < landmarks.size(); i++)
            {
                t.x = landmarks[i].x;
                t.y = landmarks[i].y;
                t.z = landmarks[i].z;

                if(t.x<xc0+1 || t.x>xc1+1 || t.y<yc0+1 || t.y>yc1+1 || t.z<zc0+1 || t.z>zc1+1)
                {


                    if(i==0)
                    {
                        v3d_msg("The first marker is invalid.");
                        return false;
                    }
                    else
                        landmarks.removeAt(i);
                }
            }


        }
        return true;
    }

};

bool proc_app2(paraApp2 &p);

bool proc_multiApp2(paraApp2 &p);

#endif // APP2_H
