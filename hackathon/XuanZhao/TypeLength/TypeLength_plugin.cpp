/* TypeLength_plugin.cpp
 * This is a test plugin, you can use it as a demo.
 * 2020-6-23 : by YourName
 */
 
#include "v3d_message.h"
#include <vector>
#include "TypeLength_plugin.h"

#include "typelengthfunction.h"

using namespace std;
Q_EXPORT_PLUGIN2(TypeLength, TypeLengthPlugin);
 
QStringList TypeLengthPlugin::menulist() const
{
	return QStringList() 
        <<tr("TypeLength")
		<<tr("menu2")
		<<tr("about");
}

QStringList TypeLengthPlugin::funclist() const
{
	return QStringList()
		<<tr("func1")
		<<tr("func2")
		<<tr("help");
}

void TypeLengthPlugin::domenu(const QString &menu_name, V3DPluginCallback2 &callback, QWidget *parent)
{
    if (menu_name == tr("TypeLength"))
	{
        typeLength(callback);
	}
	else if (menu_name == tr("menu2"))
	{
		v3d_msg("To be implemented.");
	}
	else
	{
		v3d_msg(tr("This is a test plugin, you can use it as a demo.. "
			"Developed by YourName, 2020-6-23"));
	}
}

bool TypeLengthPlugin::dofunc(const QString & func_name, const V3DPluginArgList & input, V3DPluginArgList & output, V3DPluginCallback2 & callback,  QWidget * parent)
{
	vector<char*> infiles, inparas, outfiles;
	if(input.size() >= 1) infiles = *((vector<char*> *)input.at(0).p);
	if(input.size() >= 2) inparas = *((vector<char*> *)input.at(1).p);
	if(output.size() >= 1) outfiles = *((vector<char*> *)output.at(0).p);

	if (func_name == tr("func1"))
	{
		v3d_msg("To be implemented.");
	}
	else if (func_name == tr("func2"))
	{
		v3d_msg("To be implemented.");
	}
	else if (func_name == tr("help"))
	{
		v3d_msg("To be implemented.");
	}
	else return false;

	return true;
}

