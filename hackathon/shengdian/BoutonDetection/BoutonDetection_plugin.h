/* BoutonDetection_plugin.h
 * designed by shengdian
 * 2020-7-29 : by SD-Jiang
 */
 
#ifndef __BOUTONDETECTION_PLUGIN_H__
#define __BOUTONDETECTION_PLUGIN_H__

#include <QtGui>
#include <v3d_interface.h>
#include "basic_surf_objs.h"
#include "neuron_format_converter.h"
#include "v_neuronswc.h"
#include <QHash>
#include "volimg_proc.h"
#include <fstream>
class BoutonDetectionPlugin : public QObject, public V3DPluginInterface2_1
{
	Q_OBJECT
	Q_INTERFACES(V3DPluginInterface2_1);

public:
	float getPluginVersion() const {return 1.1f;}

	QStringList menulist() const;
	void domenu(const QString &menu_name, V3DPluginCallback2 &callback, QWidget *parent);

	QStringList funclist() const ;
	bool dofunc(const QString &func_name, const V3DPluginArgList &input, V3DPluginArgList &output, V3DPluginCallback2 &callback, QWidget *parent);
};
#endif

