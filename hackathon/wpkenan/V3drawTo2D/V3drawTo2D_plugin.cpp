/*
V3drawTo2D_plugin.cpp
Wed Jan 16 20:17:15 2019 by wp
*/

#include "v3d_message.h"
#include <vector>
#include "V3drawTo2D_plugin.h"
#include<iostream>
#include <QString>
#include <QtCore/QFile>
using namespace std;

Q_EXPORT_PLUGIN2(V3drawTo2D,V3drawTo2DPlugin);
void function(V3DPluginCallback2 &callback,QWidget *parent);
bool function(V3DPluginCallback2 &callback,const V3DPluginArgList &input,V3DPluginArgList &output,QWidget *parent);
const QString title = QObject::tr("V3drawTo2D");

QStringList V3drawTo2DPlugin::menulist() const{
   return QStringList()
       << tr("function")
       << tr("about");
}

QStringList V3drawTo2DPlugin::funclist() const{
   return QStringList()
       << tr("function")
       << tr("help");
}

void V3drawTo2DPlugin::domenu(const QString &menu_name,V3DPluginCallback2 &callback,QWidget *parent){
   if(menu_name==tr("function")){
       function(callback,parent);
   }
   else{
       v3d_msg(tr("developing...Wed Jan 16 20:17:15 2019 by wp"));
   }
}

bool V3drawTo2DPlugin::dofunc(const QString &func_name,const V3DPluginArgList &input,V3DPluginArgList &output,V3DPluginCallback2 &callback,QWidget *parent){
   if(func_name==tr("function")){
       return function(callback,input,output,parent);
   }
   else if(func_name==tr("help")){
       return true;
   }
   return false;
}

void function(V3DPluginCallback2 &callback,QWidget *parent){

}

bool function(V3DPluginCallback2 &callback,const V3DPluginArgList &input,V3DPluginArgList &output,QWidget *parent){
   vector<char*> *pinfiles=(input.size()>=1)?(vector<char*> *) input[0].p : 0;
   vector<char*> * poutfiles = (output.size() >= 1) ? (vector<char*> *) output[0].p : 0;
   vector<char*> * pparas = (input.size() >= 2) ? (vector<char*> *) input[1].p : 0;
   vector<char*> infiles = (pinfiles != 0) ? * pinfiles : vector<char*>();
   vector<char*> outfiles = (poutfiles != 0) ? * poutfiles : vector<char*>();
   vector<char*> paras = (pparas != 0) ? * pparas : vector<char*>();
   return true;
}

