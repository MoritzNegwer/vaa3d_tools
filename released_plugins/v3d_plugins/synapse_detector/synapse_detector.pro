
TEMPLATE	= lib
CONFIG	+= qt plugin warn_off
#CONFIG	+= x86_64
VAA3DPATH = ../../../../v3d_external
V3DMAINPATH = ../../../v3d_main
INCLUDEPATH += $$VAA3DPATH/v3d_main/basic_c_fun
INCLUDEPATH += $$VAA3DPATH/v3d_main/common_lib/include
INCLUDEPATH += $$VDMAINPATH/jba/newmat11
INCLUDEPATH += ../../../released_plugins/v3d_plugins/neurontracing_vn2
INCLUDEPATH += ../../../released_plugins/v3d_plugins/neurontracing_vn2/app2

macx{
    LIBS += -L$$VAA3DPATH/v3d_main/common_lib/lib_mac64 -lv3dtiff
    LIBS += -L$$V3DMAINPATH/jba/c++ -lv3dnewmat
    CONFIG += x86_64
}

win32 {
    contains(QMAKE_HOST.arch, x86_64) {
    LIBS     += -L$$VAA3DPATH/v3d_main/common_lib/winlib64 -llibtiff
    } else {
    LIBS     += -L$$VAA3DPATH/v3d_main/common_lib/winlib -llibtiff
    }
}

unix:!macx {
    LIBS += -L$$VAA3DPATH/v3d_main/common_lib/lib -ltiff
    LIBS += -L$$V3DMAINPATH/jba/c++ -lv3dnewmat
    QMAKE_CXXFLAGS += -fopenmp
    LIBS += -fopenmp
}

HEADERS += $$V3DMAINPATH/basic_c_fun/stackutil.h \
    file_io_dialog.h \
    manual_proofread_dialog.h \
    common.h \
    is_analysis_fun.h \
    combiner.h \
    manual_proof_is.h

HEADERS	+= spine_detector_plugin.h \
    #spine_detector_dialog.h \
    #detect_fun.h \
    spine_extr_template.h \
    ../../../released_plugins/v3d_plugins/neurontracing_vn2/app2/heap.h \
    ../../../released_plugins/v3d_plugins/neurontracing_vn2/app2/fastmarching_dt.h \
    ../../../released_plugins/v3d_plugins/neurontracing_vn2/app2/fastmarching_tree.h \
    spine_fun.h \
    manual_correct_dialog.h \
    read_raw_file.h

SOURCES	+= spine_detector_plugin.cpp \
    #spine_detector_dialog.cpp \
    #detect_fun.cpp \
    spine_fun.cpp \
    manual_correct_dialog.cpp \
    read_raw_file.cpp \
    file_io_dialog.cpp \
    manual_proofread_dialog.cpp \
    common.cpp \
    is_analysis_fun.cpp \
    combiner.cpp \
    manual_proof_is.cpp
SOURCES	+= $$VAA3DPATH/v3d_main/basic_c_fun/v3d_message.cpp \
           $$VAA3DPATH/v3d_main/basic_c_fun/basic_4dimage_create.cpp \
           $$VAA3DPATH/v3d_main/basic_c_fun/basic_surf_objs.cpp \
           $$VAA3DPATH/v3d_main/basic_c_fun/stackutil.cpp \
           $$VAA3DPATH/v3d_main/basic_c_fun/mg_utilities.cpp \
           $$VAA3DPATH/v3d_main/basic_c_fun/mg_image_lib.cpp

TARGET	= $$qtLibraryTarget(synapse_detector)
DESTDIR	= $$VAA3DPATH/bin/plugins/synapse_detector/
