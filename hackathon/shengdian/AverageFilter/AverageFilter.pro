
TEMPLATE	= lib
CONFIG	+= qt plugin warn_off
#CONFIG	+= x86_64
VAA3DPATH = ../../../../v3d_external
V3DMAINPATH=$$VAA3DPATH/v3d_main
INCLUDEPATH	+= $$VAA3DPATH/v3d_main/basic_c_fun

HEADERS	+= AverageFilter_plugin.h
SOURCES	+= AverageFilter_plugin.cpp
SOURCES	+= $$VAA3DPATH/v3d_main/basic_c_fun/v3d_message.cpp

TARGET	= $$qtLibraryTarget(AverageFilter)
DESTDIR	= $$V3DMAINPATH/../bin/plugins/image_filters/AverageFilter
