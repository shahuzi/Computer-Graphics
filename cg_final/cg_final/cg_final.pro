#-------------------------------------------------
#
# Project created by QtCreator 2017-11-05T10:36:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cg_final
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    line.cpp \
    circle.cpp \
    ellipse.cpp \
    fill.cpp \
    bezier.cpp \
    bspline.cpp \
    koch.cpp \
    mandelbrot.cpp \
    julia.cpp \
    fern.cpp

HEADERS  += mainwindow.h \
    line.h \
    circle.h \
    ellipse.h \
    fill.h \
    bezier.h \
    bspline.h \
    koch.h \
    mandelbrot.h \
    julia.h \
    fern.h

FORMS    += mainwindow.ui \
    line.ui \
    circle.ui \
    ellipse.ui \
    fill.ui \
    bezier.ui \
    bspline.ui \
    koch.ui \
    mandelbrot.ui \
    julia.ui \
    fern.ui

RESOURCES += \
    icon.qrc
RC_FILE += cg_final.rc
