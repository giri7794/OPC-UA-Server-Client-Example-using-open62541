QT = core

CONFIG += c++17 cmdline

# Output object files into .build/
OBJECTS_DIR = $$PWD/.build

# Output the final executable into ./executable/
DESTDIR = $$PWD/executable

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        includes/opcua_client_wrapper.cpp \
        includes/open62541.c \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    includes/opcua_client_wrapper.h \
    includes/open62541.h

LIBS += -lws2_32 -liphlpapi
