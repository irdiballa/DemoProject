QT       += core gui
QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Models/modellinearregression.cpp \
    UI/widgetalgorithm.cpp \
    UI/widgetchart.cpp \
    UI/widgettable.cpp \
    Workers/loaddataworker.cpp \
    main.cpp \
    mainwindow.cpp \


HEADERS += \
    Models/modellinearregression.h \
    UI/widgetalgorithm.h \
    UI/widgetchart.h \
    UI/widgettable.h \
    Workers/loaddataworker.h \
    mainwindow.h \

FORMS += \
    UI/widgetalgorithm.ui \
    UI/widgetchart.ui \
    UI/widgettable.ui \
    mainwindow.ui \


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Images/edit.png \
    Images/load.png \
    Images/run.png \
    Images/save.png \
    Resources/Images/edit.png \
    Resources/Images/load.png \
    Resources/Images/run.png \
    Resources/Images/save.png

RESOURCES += \
    Images.qrc

unix|win32: LIBS += -L$$PWD/External/lib_win64/ -llibopenblas

INCLUDEPATH += $$PWD/External/lib_win64 \
                $$PWD/External/include \

DEPENDPATH += $$PWD/External/lib_win64
