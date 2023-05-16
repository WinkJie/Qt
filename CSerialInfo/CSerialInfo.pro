#-------------------------------------------------
#
# Project created by QtCreator 2022-12-31T14:20:18
#
#-------------------------------------------------

QT       += core gui opengl charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CSerialInfo
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        CSerialInfo.cpp \
    search_box.cpp \
    DrawDemo.cpp \
    form.cpp \
    QToolTipsNew.cpp \
    mygraphicrectitem.cpp \
    Widget.cpp \
    WidgetPlus.cpp \
    CustomMessage.cpp \
    PainterTest.cpp

HEADERS += \
        CSerialInfo.h \
    search_box.h \
    DrawDemo.h \
    form.h \
    QToolTipsNew.h \
    mygraphicrectitem.h \
    Widget.h \
    WidgetPlus.h \
    CustomMessage.h \
    PainterTest.h


#INCLUDEPATH += D:\opencv\opencv\opencv-build\install\include\opencv2 \
#        D:\opencv\opencv\opencv-build\install\include
#LIBS += D:\opencv\opencv\opencv-build\install\x64\mingw\lib\libopencv*.a


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    public.qrc

FORMS += \
    form.ui \

