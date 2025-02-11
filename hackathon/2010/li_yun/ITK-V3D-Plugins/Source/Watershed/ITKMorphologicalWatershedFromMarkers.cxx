/* ITKMorphologicalWatershedFromMarkers.cxx
 * 2010-06-04: create this program by Yang Yu
 */

#include <QtGui>

#include <math.h>
#include <stdlib.h>

#include "ITKMorphologicalWatershedFromMarkers.h"
#include "V3DITKFilterDualImage.h"

// ITK Header Files
#include "itkImage.h"

#include "itkImportImageFilter.h"
#include "itkCastImageFilter.h"
#include "itkRelabelComponentImageFilter.h"

#include "itkMorphologicalWatershedFromMarkersImageFilter.h"

// Q_EXPORT_PLUGIN2 ( PluginName, ClassName )
// The value of PluginName should correspond to the TARGET specified in the
// plugin's project file.
Q_EXPORT_PLUGIN2(ITKMorphologicalWatershedFromMarkers, ITKMorphologicalWatershedFromMarkersPlugin)

//plugin funcs
QStringList ITKMorphologicalWatershedFromMarkersPlugin::menulist() const
{
	return QStringList() << QObject::tr("ITK MorphologicalWatershedFromMarkers")
						 << QObject::tr("about this plugin");
}

QStringList ITKMorphologicalWatershedFromMarkersPlugin::funclist() const
{
    return QStringList();
}

void ITKMorphologicalWatershedFromMarkersPlugin::dofunc(const QString & func_name,
		const V3DPluginArgList & input, V3DPluginArgList & output, QWidget * parent)
{
	// empty by now
}

template <typename TInputPixelType, typename TOutputPixelType>
class ITKMorphologicalWatershedFromMarkersSpecializaed  : public V3DITKFilterDualImage< TInputPixelType, TOutputPixelType >
{
	typedef V3DITKFilterDualImage< TInputPixelType, TOutputPixelType >    				Superclass;
	typedef itk::Image< TInputPixelType, 3 > 							InputImageType;
	typedef itk::Image< TOutputPixelType, 3 > 							OutputImageType;
	typedef itk::CastImageFilter< InputImageType, OutputImageType> 					CastImageFilterType;
	typedef itk::MorphologicalWatershedFromMarkersImageFilter< OutputImageType, OutputImageType >   MorphologicalWatershedFromMarkersType;
	typedef typename MorphologicalWatershedFromMarkersType::LabelImageType  			LabeledImageType;
	typedef itk::RelabelComponentImageFilter< LabeledImageType, OutputImageType > 			RelabelComponentImageFilterType;
			
public:	
ITKMorphologicalWatershedFromMarkersSpecializaed( V3DPluginCallback * callback ): Superclass(callback) 
{
	this->castImageFilter1 = CastImageFilterType::New();
	this->castImageFilter2 = CastImageFilterType::New();
	this->watershedFilter = MorphologicalWatershedFromMarkersType::New();
	this->relabelComponent = RelabelComponentImageFilterType::New();
	
	this->RegisterInternalFilter( this->castImageFilter1, 0.1 );
	this->RegisterInternalFilter( this->castImageFilter2, 0.1 );
	this->RegisterInternalFilter( this->watershedFilter, 0.2 );
	this->RegisterInternalFilter( this->relabelComponent, 0.6 );	
}

virtual ~ITKMorphologicalWatershedFromMarkersSpecializaed() {};
	
void Execute(V3DPluginCallback &callback, QWidget *parent)
{
    this->SetImageSelectionDialogTitle("Input Images");
    this->AddImageSelectionLabel("Image 1");
    this->AddImageSelectionLabel("Image 2");
    this->m_ImageSelectionDialog.SetCallback(this->m_V3DPluginCallback);
    this->Compute();	
}

virtual void ComputeOneRegion()
{
	castImageFilter1->SetInput( this->GetInput3DImage1() );
	castImageFilter2->SetInput( this->GetInput3DImage2() );

	try
	{
		castImageFilter1->Update();
		castImageFilter2->Update();
	}
	catch( itk::ExceptionObject & excp)
	{
		std::cerr << "Error run this filter." << std::endl;
		std::cerr << excp << std::endl;
		return;
	}

	//watershed segmentation algorithm
	watershedFilter->SetInput( castImageFilter1->GetOutput() );
	watershedFilter->SetMarkerImage( castImageFilter2->GetOutput() );
	watershedFilter->SetMarkWatershedLine( false ); // true: Meyer, false: Beucher.
	watershedFilter->SetFullyConnected( true ); // true: 26-conn, false: 6-conn

	relabelComponent->SetInput( watershedFilter->GetOutput() );

	try
	{
		relabelComponent->Update();
	}
	catch( itk::ExceptionObject & excp)
	{
		std::cerr << "Error run this filter." << std::endl;
		std::cerr << excp << std::endl;
		return;
	}
	this->SetOutputImage( this->relabelComponent->GetOutput() );

}

private:
	typename CastImageFilterType::Pointer castImageFilter1;
	typename CastImageFilterType::Pointer castImageFilter2;
	typename MorphologicalWatershedFromMarkersType::Pointer watershedFilter;
	typename RelabelComponentImageFilterType::Pointer relabelComponent;
};

#define EXECUTE( v3d_pixel_type, input_pixel_type, output_pixel_type ) \
	case v3d_pixel_type: \
	{ \
		ITKMorphologicalWatershedFromMarkersSpecializaed< input_pixel_type, output_pixel_type > runner(&callback); \
		runner.Execute( callback, parent ); \
		break; \
	} 

#define EXECUTE_ALL_PIXEL_TYPES \
	ImagePixelType pixelType = p4DImage->getDatatype(); \
	switch( pixelType )  \
	{  \
		EXECUTE( V3D_UINT8, unsigned char, float );  \
		EXECUTE( V3D_UINT16, unsigned short int, float );  \
		EXECUTE( V3D_FLOAT32, float, float );  \
		case V3D_UNKNOWN:  \
		{  \
		}  \
	}  

void ITKMorphologicalWatershedFromMarkersPlugin::domenu(const QString & menu_name, V3DPluginCallback & callback, QWidget * parent)
{
	if (menu_name == QObject::tr("ITK MorphologicalWatershedFromMarkers"))
	{
		v3dhandle curwin = callback.currentImageWindow();
		if (!curwin)
		{
			v3d_msg(QObject::tr("You don't have any image open in the main window."));
			return;
		}
	
		Image4DSimple *p4DImage = callback.getImage(curwin);
		if (! p4DImage)
		{
			v3d_msg(QObject::tr("The input image is null."));
			return;
		}	
	
		EXECUTE_ALL_PIXEL_TYPES;
	}
	else if (menu_name == QObject::tr("about this plugin"))
	{
		QMessageBox::information(parent, "Version info", "ITK Morphological Watershed From Markers 1.0 (2010-June-04): this plugin is developed by Yang Yu.");
	}
}



