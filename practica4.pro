TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        database.cpp \
        funciones.cpp \
        main.cpp \
        red.cpp \
        router.cpp

HEADERS += \
    database.h \
    funciones.h \
    red.h \
    router.h
