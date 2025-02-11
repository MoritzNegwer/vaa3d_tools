/* typeset_func.cpp
 * This is a plugin to set segment type based on marker location
 * 2014-06-27 : by Surobhi Ganguly
 */

#include <v3d_interface.h>
#include "v3d_message.h"
#include "my_surf_objs.h"
#include "openSWCDialog.h"
#include "typeset.h"
#include "typeset_func.h"
#include "typeset_plugin.h"
#include "customary_structs/vaa3d_neurontoolbox_para.h"
#include <vector>
#include <iostream>
//using namespace std;

//const QString title = QObject::tr("typeset Neuron");


bool export_list2file_v2(QList<NeuronSWC> & lN, QString fileSaveName, QString FileSWCOpenName)
{
    QFile file(fileSaveName);
    if (!file.open(QIODevice::WriteOnly|QIODevice::Text))
        return false;
    QTextStream myfile(&file);
    myfile<<"# generated by Vaa3D Plugin typeset"<<endl;
    myfile<<"# source file(s): "<<FileSWCOpenName<<endl;
    myfile<<"# id,type,x,y,z,r,pid"<<endl;
    for (V3DLONG i=0;i<lN.size();i++)
        myfile << lN.at(i).n <<" " << lN.at(i).type << " "<< lN.at(i).x <<" "<<lN.at(i).y << " "<< lN.at(i).z << " "<< lN.at(i).r << " " <<lN.at(i).pn << "\n";
    file.close();
    cout<<"swc file "<<fileSaveName.toStdString()<<" has been generated, size: "<<lN.size()<<endl;
    return true;
}

static int file_count = 0;
static QString last_save_name;
static QString FileSWCOpenName;
static QList <NeuronSWC> nt_list_tosave;
static int cur_window = -1, cur_neuron = -1;

int typeset_swc_func(V3DPluginCallback2 &callback, double settype, QList<ImageMarker> tmp_list_in)
{
    v3d_msg("Be sure to open the correct the sorted swc file");

    //QString FileSWCOpenName;
    NeuronTree nt;

    OpenSWCDialog * openDlg = new OpenSWCDialog(0, &callback);
    if (!openDlg->exec())
        return 0;

    FileSWCOpenName = openDlg->file_name;

    nt = openDlg->nt;

    cur_window = -1;
    cur_neuron = -1;
    QList<V3dR_MainWindow*> list_windows = callback.getListAll3DViewers();
    for(int i = 0; i<list_windows.size();i++)
    {
           QList<NeuronTree> * treeList = callback.getHandleNeuronTrees_Any3DViewer(list_windows.at(i));
           for(int j = 0; j < treeList->size();j++)
           {
               if(treeList->at(j).file == FileSWCOpenName)
               {
                   cur_window = i;
                   cur_neuron = j;
                   break;
               }

           }

    }

    QList<ImageMarker> tmp_list;
    NeuronTree result = nt;

    if (tmp_list_in.size() != 1)
    {
        tmp_list = get_markers(callback);
    }
    else
    {
        tmp_list = tmp_list_in;
    }

    if (tmp_list.size() < 1)//this probably won't happen...
    {
        v3d_msg("no markers in 3D window; plugin not run");
        return 0;
    }
    else
    {
        result = typeset_marker(nt, tmp_list, settype);
        //nt_shared = result;

        QString fileDefaultName;
        if (file_count==0)
        {
            //FileSWCOpenName.chop(4);
            fileDefaultName = FileSWCOpenName+QString("_%1_typeset.swc").arg(file_count);
        }
        if (file_count>0)
        {
            FileSWCOpenName.chop(14);
            fileDefaultName = FileSWCOpenName+QString("_%1_typeset.swc").arg(file_count);
        }

        nt_list_tosave = result.listNeuron;

        if(list_windows.size()<1 || cur_window == -1 || cur_neuron ==-1)
        {
            //write new SWC to file
            QString fileSaveName = QFileDialog::getSaveFileName(0, QObject::tr("Save File"),
                    fileDefaultName,
                    QObject::tr("Supported file (*.swc)"
                        ";;Neuron structure	(*.swc)"
                        ));
            last_save_name = fileSaveName;
            if (!export_list2file_v2(nt_list_tosave,fileSaveName,FileSWCOpenName))
            {
                v3d_msg("fail to write the output swc file.");
                return 0;
            }
            file_count++;
            reload_SWC(callback);
        }
        else
        {
            QList<NeuronTree> * new_treeList = callback.getHandleNeuronTrees_Any3DViewer(list_windows.at(cur_window));
            NeuronTree  resultTree;
            QList <NeuronSWC> listNeuron;
            QHash <int, int>  hashNeuron;
            listNeuron.clear();
            hashNeuron.clear();
             for(int j = 0; j < result.listNeuron.size(); j++)
            {
                listNeuron.append(result.listNeuron.at(j));
                hashNeuron.insert(result.listNeuron.at(j).n, listNeuron.size()-1);
            }
            resultTree.listNeuron = listNeuron;
            resultTree.hashNeuron = hashNeuron;
            nt_list_tosave = result.listNeuron;
            last_save_name = fileDefaultName;

            new_treeList->clear();
            resultTree.color.r = 0;
            resultTree.color.g = 0;
            resultTree.color.b = 0;
            resultTree.color.a = 0;
            resultTree.file = fileDefaultName;
            new_treeList->push_back(resultTree);
          //  callback.setWindowDataTitle(list_windows.at(0), fileDefaultName);
            callback.update_NeuronBoundingBox(list_windows.at(0));

        }
        return 1;
    }
}

void final_typeset_save()
{
    QString final_save_name = last_save_name+QString("_finaltypeset.swc");
    QString fileSaveName = QFileDialog::getSaveFileName(0, QObject::tr("Save File"),
            final_save_name,
            QObject::tr("Supported file (*.swc)"
                ";;Neuron structure	(*.swc)"
                ));
    if (!export_list2file_v2(nt_list_tosave,fileSaveName,FileSWCOpenName))
    {
        v3d_msg("fail to write the output swc file.");
        return;
    }
    return;
}

void reload_SWC(V3DPluginCallback2 &callback) //pushes most recent swc file onto image if image is open
{
    v3dhandle current_window = callback.currentImageWindow();

    NeuronTree nt = readSWC_file(last_save_name);
    callback.setSWC(current_window, nt);

    callback.updateImageWindow(current_window);
    //v3d_msg("reloaded");
}

QList<ImageMarker> get_markers(V3DPluginCallback2 &callback)
{

    QList<ImageMarker> tmp_list;
    LandmarkList* current_3Dview_markers;


   // v3dhandleList list_windows = callback.getImageWindowList();
    QList<V3dR_MainWindow*> list_windows = callback.getListAll3DViewers();

    if (list_windows.size() < 1 || cur_window == -1 || cur_neuron ==-1)
    {
        v3d_msg("No window open. Must load marker file.");

        QString FileMarkerOpenName;
        FileMarkerOpenName = QFileDialog::getOpenFileName(0, QObject::tr("Open Marker File"),
                "",
                    QObject::tr("Supported file (*.marker)"));
        if (FileMarkerOpenName.isEmpty())
            return tmp_list;
        else if (FileMarkerOpenName.toUpper().endsWith(".MARKER"))
        {
            tmp_list = readMarker_file(FileMarkerOpenName);
        }
    }
    else
    {
//        v3dhandle current_window = callback.currentImageWindow();
//       current_3Dview_markers = callback.getLandmark(current_window); //gives list of markers drawn

        current_3Dview_markers = callback.getHandleLandmarkList_Any3DViewer(list_windows.at(cur_window));
        for (V3DLONG i=0;i<current_3Dview_markers->size();i++)//translate marker info from landmark list to tmp_list
        {
            LocationSimple t = current_3Dview_markers->at(i);

            ImageMarker pt;
            pt.n = i+1; //marker number
            pt.x = t.x;
            pt.y = t.y;
            pt.z = t.z;
            tmp_list.push_back(pt);
        }
    }
    return tmp_list;

}

//bool typeset_swc(const V3DPluginArgList & input, V3DPluginArgList & output)
//{
//    cout<<"Welcome to typeset_swc"<<endl;
//    vector<char*>* inlist = (vector<char*>*)(input.at(0).p);
//    vector<char*>* outlist = NULL;
//    vector<char*>* paralist = NULL;

//    if(input.size() != 2)
//    {
//        printf("Please specify both input file and segment type.\n");
//        return false;
//    }
//    paralist = (vector<char*>*)(input.at(1).p);
//    if (paralist->size()!=1)
//    {
//        printf("Please specify only one parameter - the resampling step length.\n");
//        return false;
//    }

//    QString FileSWCOpenName = QString(inlist->at(0));
//    QString FileMarkerOpenName;
//    QString fileSaveName;

//    if (output.size()==0)
//    {
//        printf("No outputfile specified.\n");
//        fileSaveName = FileSWCOpenName + "_typeset.swc";
//    }
//    else if (output.size()==1)
//    {
//        outlist = (vector<char*>*)(output.at(0).p);
//        fileSaveName = QString(outlist->at(0));
//    }
//    else
//    {
//        printf("You have specified more than 1 output file.\n");
//        return false;
//    }

//    NeuronTree nt;
//    QList<ImageMarker> tmp_list;

//    if (FileSWCOpenName.toUpper().endsWith(".SWC") || FileSWCOpenName.toUpper().endsWith(".ESWC"))
//        nt = readSWC_file(FileSWCOpenName);

//    double settype = 0;

//    if (FileMarkerOpenName.toUpper().endsWith(".marker"))
//    {
//        bool ok;
//        tmp_list = readMarker_file(FileMarkerOpenName);
//        if (!ok)
//            return 0;
//    }

//    NeuronTree result = typeset_marker(nt,tmp_list,settype);

//    if (!export_list2file_v2(result.listNeuron, fileSaveName, FileSWCOpenName))
//    {
//        printf("fail to write the output swc file.\n");
//        return false;
//    }

//    return true;
//}

bool typeset_swc_toolbox(const V3DPluginArgList & input)
{
    vaa3d_neurontoolbox_paras * paras = (vaa3d_neurontoolbox_paras *)(input.at(0).p);
    NeuronTree nt = paras->nt;
    QString FileSWCOpenName = nt.file;
    QString FileMarkerOpenName;


    bool ok;
    double settype = 0;
    QList<ImageMarker> tmp_list;
    tmp_list = readMarker_file(FileMarkerOpenName);

    if (!ok)
        return true;

    NeuronTree result = typeset_marker(nt,tmp_list,settype);

    QString fileDefaultName = FileSWCOpenName+QString("_")+FileMarkerOpenName+QString("_typeset.swc");
    //write new SWC to file
    QString fileSaveName = QFileDialog::getSaveFileName(0, QObject::tr("Save File"),
            fileDefaultName,
            QObject::tr("Supported file (*.swc)"
                ";;Neuron structure	(*.swc)"
                ));
    if (!export_list2file_v2(result.listNeuron,fileSaveName,FileSWCOpenName))
    {
        v3d_msg("fail to write the output swc file.");
        return false;
    }

    return true;

}
