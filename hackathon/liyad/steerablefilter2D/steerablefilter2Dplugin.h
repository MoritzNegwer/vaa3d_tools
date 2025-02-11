/* gaussianfilter.h
 * 2009-06-03: create this program by Yang Yu
 * 2009-08-14: change into plugin by Yang Yu
 */


#ifndef __GAUSSIANFILTER_H__
#define __GAUSSIANFILTER_H__

//     3D ANISOTROPIC GAUSSIAN FILTERING
//
//     pImage  - input & output
//     N       - width of the image
//     M       - height of the image
//     P       - slice of the image
//     Order      - order_of ST
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <v3d_interface.h>

class SteerableFilter2DPlugin : public QObject, public V3DPluginInterface2_1
{
     Q_OBJECT
    Q_INTERFACES(V3DPluginInterface2_1);

public:
    float getPluginVersion() const {return 1.1f;}

	QStringList menulist() const;
	void domenu(const QString &menu_name, V3DPluginCallback2 &callback, QWidget *parent);

	QStringList funclist() const;
     bool dofunc(const QString &func_name, const V3DPluginArgList &input, V3DPluginArgList &output, V3DPluginCallback2 &callback, QWidget *parent);
};

//define a simple dialog for choose Steerable Filter 2D parameters
class SteerableFilter2DDialog : public QDialog
    {
        Q_OBJECT

    public:
        SteerableFilter2DDialog(V3DPluginCallback2 &cb, QWidget *parent)
        {
            //initialization of variables
            image = 0;
            gridLayout = 0;

            //

            v3dhandleList win_list = cb.getImageWindowList();

            if(win_list.size()<1)
            {
                QMessageBox::information(0, "Steerable Filter 2D", QObject::tr("No image is open."));
                return;
            }

            //create a dialog
            gridLayout = new QGridLayout();

            image = cb.getImage(cb.currentImageWindow());

            if (!image || !image->valid())
            {
                v3d_msg("The image is not valid yet. Check your data.");
                return;
            }

            pRoiList=cb.getROI(cb.currentImageWindow());
            int chn_num = image->getCDim();

            order_editor = new QLineEdit(QString("").setNum(4));            
            sigma_editor = new QLineEdit(QString("").setNum(3));
            channel_spinbox = new QSpinBox();
            channel_spinbox->setRange(1,chn_num);


            gridLayout->addWidget(new QLabel("order"),0,0);
            gridLayout->addWidget(order_editor, 0,1,1,5);
            gridLayout->addWidget(new QLabel("Sigma value"),1,0);
            gridLayout->addWidget(sigma_editor, 1,1,1,5);
            gridLayout->addWidget(new QLabel("Channel"),2,0);
            gridLayout->addWidget(channel_spinbox, 2,1,1,5);

            ok     = new QPushButton("OK");
            cancel = new QPushButton("Cancel");
            gridLayout->addWidget(cancel, 3,0);
            gridLayout->addWidget(ok,     3,1,1,5);;

            setLayout(gridLayout);
            setWindowTitle(QString("Steerable Filter 2D"));

            //slot interface
            connect(ok,     SIGNAL(clicked()), this, SLOT(accept()));
            connect(cancel, SIGNAL(clicked()), this, SLOT(reject()));
            update();
        }

        ~SteerableFilter2DDialog(){}

        public slots:
        void update()
        {
            order = atof(order_editor->text().toStdString().c_str());
            sigma = atof(sigma_editor->text().toStdString().c_str());
            ch = channel_spinbox->text().toInt();
        }

    public:
        int order,ch;
        double sigma;
        Image4DSimple* image;
        ROIList pRoiList;
        QGridLayout *gridLayout;
        QPushButton* ok;
        QPushButton* cancel;
        QLineEdit * order_editor;
        QLineEdit * sigma_editor;
        QSpinBox * channel_spinbox;

    };


#endif



