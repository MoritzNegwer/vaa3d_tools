/* detect_type_plugin.cpp
 * This is a test plugin, you can use it as a demo.
 * 2018-9-12 : by OY
 */
 
#include "v3d_message.h"
#include <vector>
#include "detect_type_plugin.h"
#include "main.h"

using namespace std;

Q_EXPORT_PLUGIN2(detect_type, type);
 
QStringList type::menulist() const
{
	return QStringList() 
        <<tr("detect_type")
		<<tr("about");
}

QStringList type::funclist() const
{
	return QStringList()
        <<tr("detection_type")
		<<tr("func2")
		<<tr("help");
}

void type::domenu(const QString &menu_name, V3DPluginCallback2 &callback, QWidget *parent)
{
    //if (menu_name == tr("detect_type_distance"))
    //{
    //    detect_type_distance(callback,parent);
    //}
    if (menu_name == tr("detect_type"))
    {
        detect_type(callback,parent);
    }
	else
	{
		v3d_msg(tr("This is a test plugin, you can use it as a demo.. "
			"Developed by OY, 2018-9-12"));
	}
}

bool type::dofunc(const QString & func_name, const V3DPluginArgList & input, V3DPluginArgList & output, V3DPluginCallback2 & callback,  QWidget * parent)
{
	vector<char*> infiles, inparas, outfiles;
	if(input.size() >= 1) infiles = *((vector<char*> *)input.at(0).p);
	if(input.size() >= 2) inparas = *((vector<char*> *)input.at(1).p);
	if(output.size() >= 1) outfiles = *((vector<char*> *)output.at(0).p);

    if (func_name == tr("detection_type"))
	{
        detect_type_func(input,output,callback);
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

