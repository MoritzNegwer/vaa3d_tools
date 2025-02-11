#ifndef JACE_PROXY_LOCI_FORMATS_ENUMS_ACQUISITIONMODE_H
#define JACE_PROXY_LOCI_FORMATS_ENUMS_ACQUISITIONMODE_H

#ifndef JACE_OS_DEP_H
#include "jace/os_dep.h"
#endif

#ifndef JACE_NAMESPACE_H
#include "jace/namespace.h"
#endif

#ifndef JACE_JOBJECT_H
#include "jace/proxy/JObject.h"
#endif

#ifndef JACE_JARRAY_H
#include "jace/JArray.h"
#endif

#ifndef JACE_JFIELD_PROXY_H
#include "jace/JFieldProxy.h"
#endif

#ifndef JACE_JCLASSIMPL_H
#include "jace/JClassImpl.h"
#endif

/**
 * The super class for this class.
 *
 */
#ifndef JACE_PROXY_JAVA_LANG_ENUM_H
#include "jace/proxy/java/lang/Enum.h"
#endif

/**
 * The interfaces implemented by this class.
 *
 */
#ifndef JACE_PROXY_LOCI_FORMATS_ENUMS_ENUMERATION_H
#include "jace/proxy/loci/formats/enums/Enumeration.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class String;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_5( jace, proxy, loci, formats, enums )
class EnumerationException;
END_NAMESPACE_5( jace, proxy, loci, formats, enums )

BEGIN_NAMESPACE_5( jace, proxy, loci, formats, enums )

/**
 * The Jace C++ proxy class for loci.formats.enums.AcquisitionMode.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class AcquisitionMode : public ::jace::proxy::java::lang::Enum, public virtual ::jace::proxy::loci::formats::enums::Enumeration
{
public: 

/**
 * values
 *
 */
static ::jace::JArray< ::jace::proxy::loci::formats::enums::AcquisitionMode > values();

/**
 * valueOf
 *
 */
static ::jace::proxy::loci::formats::enums::AcquisitionMode valueOf( ::jace::proxy::java::lang::String p0 );

/**
 * fromString
 *
 */
static ::jace::proxy::loci::formats::enums::AcquisitionMode fromString( ::jace::proxy::java::lang::String p0 );

/**
 * getValue
 *
 */
::jace::proxy::java::lang::String getValue();

/**
 * toString
 *
 */
::jace::proxy::java::lang::String toString();

/**
 * public static final enum WIDEFIELD
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::loci::formats::enums::AcquisitionMode > WIDEFIELD();

/**
 * public static final enum LASERSCANNINGMICROSCOPY
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::loci::formats::enums::AcquisitionMode > LASERSCANNINGMICROSCOPY();

/**
 * public static final enum LASERSCANNINGCONFOCAL
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::loci::formats::enums::AcquisitionMode > LASERSCANNINGCONFOCAL();

/**
 * public static final enum SPINNINGDISKCONFOCAL
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::loci::formats::enums::AcquisitionMode > SPINNINGDISKCONFOCAL();

/**
 * public static final enum SLITSCANCONFOCAL
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::loci::formats::enums::AcquisitionMode > SLITSCANCONFOCAL();

/**
 * public static final enum MULTIPHOTONMICROSCOPY
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::loci::formats::enums::AcquisitionMode > MULTIPHOTONMICROSCOPY();

/**
 * public static final enum STRUCTUREDILLUMINATION
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::loci::formats::enums::AcquisitionMode > STRUCTUREDILLUMINATION();

/**
 * public static final enum SINGLEMOLECULEIMAGING
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::loci::formats::enums::AcquisitionMode > SINGLEMOLECULEIMAGING();

/**
 * public static final enum TOTALINTERNALREFLECTION
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::loci::formats::enums::AcquisitionMode > TOTALINTERNALREFLECTION();

/**
 * public static final enum FLUORESCENCELIFETIME
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::loci::formats::enums::AcquisitionMode > FLUORESCENCELIFETIME();

/**
 * public static final enum SPECTRALIMAGING
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::loci::formats::enums::AcquisitionMode > SPECTRALIMAGING();

/**
 * public static final enum FLUORESCENCECORRELATIONSPECTROSCOPY
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::loci::formats::enums::AcquisitionMode > FLUORESCENCECORRELATIONSPECTROSCOPY();

/**
 * public static final enum NEARFIELDSCANNINGOPTICALMICROSCOPY
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::loci::formats::enums::AcquisitionMode > NEARFIELDSCANNINGOPTICALMICROSCOPY();

/**
 * public static final enum SECONDHARMONICGENERATIONIMAGING
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::loci::formats::enums::AcquisitionMode > SECONDHARMONICGENERATIONIMAGING();

/**
 * public static final enum OTHER
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::loci::formats::enums::AcquisitionMode > OTHER();

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
AcquisitionMode( jvalue value );
AcquisitionMode( jobject object );
AcquisitionMode( const AcquisitionMode& object );
AcquisitionMode( const NoOp& noOp );
virtual const JClass& getJavaJniClass() const throw ( ::jace::JNIException );
static const JClass& staticGetJavaJniClass() throw ( ::jace::JNIException );
};

END_NAMESPACE_5( jace, proxy, loci, formats, enums )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::loci::formats::enums::AcquisitionMode>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::loci::formats::enums::AcquisitionMode>::ElementProxy( const jace::ElementProxy< ::jace::proxy::loci::formats::enums::AcquisitionMode>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::loci::formats::enums::AcquisitionMode>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::loci::formats::enums::AcquisitionMode( element ), Object( NO_OP ), mIndex( index )
  {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::loci::formats::enums::AcquisitionMode>::ElementProxy( const jace::ElementProxy< ::jace::proxy::loci::formats::enums::AcquisitionMode>& proxy ) : 
    ::jace::proxy::loci::formats::enums::AcquisitionMode( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex )
  {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::loci::formats::enums::AcquisitionMode>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::loci::formats::enums::AcquisitionMode>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::loci::formats::enums::AcquisitionMode>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::loci::formats::enums::AcquisitionMode>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::loci::formats::enums::AcquisitionMode>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::loci::formats::enums::AcquisitionMode( value ), Object( NO_OP ), fieldID( fieldID_ )
  {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ )
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    else
      parent = parent_;

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::loci::formats::enums::AcquisitionMode>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::loci::formats::enums::AcquisitionMode( value ), Object( NO_OP ), fieldID( fieldID_ )
  {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::loci::formats::enums::AcquisitionMode>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::loci::formats::enums::AcquisitionMode>& object ) : 
    ::jace::proxy::loci::formats::enums::AcquisitionMode( object.getJavaJniValue() ), Object( NO_OP )
  {
    fieldID = object.fieldID; 

    if ( object.parent )
    {
      JNIEnv* env = ::jace::helper::attach();
      parent = ::jace::helper::newGlobalRef( env, object.parent );
    }
    else
      parent = 0;

    if ( object.parentClass )
    {
      JNIEnv* env = ::jace::helper::attach();
      parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, object.parentClass ) );
    }
    else
      parentClass = 0;
  }
#endif

END_NAMESPACE( jace )

#endif // #ifndef JACE_PROXY_LOCI_FORMATS_ENUMS_ACQUISITIONMODE_H

