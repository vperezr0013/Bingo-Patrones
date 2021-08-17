QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BaseEntity.cpp \
    Cola.cpp \
    ColaFactory.cpp \
    Gestor.cpp \
    IAbstractFactoryStruct.cpp \
    IStruct.cpp \
    List.cpp \
    ListFactory.cpp \
    Nodo.cpp \
    Pila.cpp \
    PilaFactory.cpp \
    Premios.cpp \
    carton.cpp \
    cartoncontroller.cpp \
    main.cpp \
    bingo.cpp

HEADERS += \
    BaseEntity.h \
    Cola.h \
    ColaFactory.h \
    Gestor.h \
    IAbstractFactoryStruct.h \
    IStruct.h \
    List.h \
    ListFactory.h \
    Nodo.h \
    Pila.h \
    PilaFactory.h \
    Premios.h \
    SistemaPremios.h \
    bingo.h \
    carton.h \
    cartoncontroller.h

FORMS += \
    bingo.ui

ABSTRACFACTORY +=\

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
