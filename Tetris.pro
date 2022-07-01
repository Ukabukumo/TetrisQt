QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Block.cpp \
    Figure.cpp \
    FigureLeftL.cpp \
    FigureLeftZ.cpp \
    FigureRightL.cpp \
    FigureRightZ.cpp \
    FigureT.cpp \
    InfoField.cpp \
    Stick.cpp \
    Tile.cpp \
    TileHeap.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    Block.hpp \
    Figure.hpp \
    FigureLeftL.hpp \
    FigureLeftZ.hpp \
    FigureRightL.hpp \
    FigureRightZ.hpp \
    FigureT.hpp \
    GlobalParams.h \
    InfoField.hpp \
    MainWindow.hpp \
    Stick.hpp \
    Tile.hpp \
    TileHeap.hpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
