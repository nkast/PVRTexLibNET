#############################################################################
# Makefile for building: libPVRTexLibWrapper.so
#############################################################################

####### Compiler, tools and options

ARCH          = x64
CC            = gcc
CXX           = g++
DEFINES       = 
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT -fPIC -fvisibility=hidden -fvisibility-inlines-hidden $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT -fPIC -fvisibility=hidden -fvisibility-inlines-hidden $(DEFINES)
INCPATH       = -I/usr/include -I../.. -I../../PVRTexTool/Library/Include
LINK          = g++
LFLAGS        = -m64 -Wl,-O1 -shared -Wl,-soname,libPVRTexLibWrapper.so
LIBS          = $(SUBLIBS) -lpthread -L../../PVRTexTool/Library/Linux_x86_64/Static/ -lPVRTexLib
AR            = ar cqs
RANLIB        = 
STRIP         = strip
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ../../obj/Linux/Release/$(ARCH)
BIN_DIR       = ../../bin/Linux/Release/$(ARCH)

####### Files

SOURCES       = ../../PVRTexLibWrapper.cpp 
OBJECTS       = $(OBJECTS_DIR)/PVRTexLibWrapper.o
TARGETA       = $(BIN_DIR)/libPVRTexLibWrapper.a
TARGET        = $(BIN_DIR)/libPVRTexLibWrapper.so


first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: $(TARGET)

$(TARGET):  $(OBJECTS) $(SUBLIBS) $(OBJCOMP)
	-$(DEL_FILE) $(TARGET)
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(LIBS) $(OBJCOMP)

staticlib: $(TARGETA)

$(TARGETA):  $(OBJECTS) $(OBJCOMP) 
	$(CHK_DIR_EXISTS) $(OBJECTS_DIR) || $(MKDIR) $(OBJECTS_DIR)  
	$(CHK_DIR_EXISTS) $(BIN_DIR) || $(MKDIR) $(BIN_DIR)  
	-$(DEL_FILE) $(TARGETA) 
	$(AR) $(TARGETA) $(OBJECTS)

clean:
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Compile

$(OBJECTS): $(SOURCES) ../../Stdafx.h \
		../../PVRTexLibWrapper.h \
		../../PVRTexTool/Library/Include/PVRTGlobal.h \
		../../PVRTexTool/Library/Include/PVRTextureDefines.h \
		../../PVRTexTool/Library/Include/PVRTTexture.h \
		../../PVRTexTool/Library/Include/PVRTextureFormat.h \
		../../PVRTexTool/Library/Include/PVRTString.h \
		../../PVRTexTool/Library/Include/PVRTexture.h \
		../../PVRTexTool/Library/Include/PVRTextureHeader.h \
		../../PVRTexTool/Library/Include/PVRTMap.h \
		../../PVRTexTool/Library/Include/PVRTArray.h \
		../../PVRTexTool/Library/Include/PVRTError.h \
		../../PVRTexTool/Library/Include/PVRTextureUtilities.h
	$(CHK_DIR_EXISTS) $(OBJECTS_DIR) || $(MKDIR) $(OBJECTS_DIR)  
	$(CHK_DIR_EXISTS) $(BIN_DIR) || $(MKDIR) $(BIN_DIR)  
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJECTS) $(SOURCES)




