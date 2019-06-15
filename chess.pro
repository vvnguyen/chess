#-------------------------------------------------
#
# Project created by QtCreator 2019-06-04T18:20:06
#
#-------------------------------------------------

QT       += core gui
QT += svg
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chess
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
        chessboard.cpp \
        chessview.cpp \
        gamealgorithm.cpp \
        main.cpp \
        mainwindow.cpp \
        piece.cpp

HEADERS += \
        chessboard.h \
        chessview.h \
        gamealgorithm.h \
        mainwindow.h \
        piece.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    pieces/black_bishop.png \
    pieces/black_king.png \
    pieces/black_knight.png \
    pieces/black_pawn.png \
    pieces/black_queen.png \
    pieces/black_rook.png \
    pieces/white_bishop.png \
    pieces/white_king.png \
    pieces/white_knight.png \
    pieces/white_pawn.png \
    pieces/white_queen.png \
    pieces/white_rook.png

RESOURCES += \
    pieces/pieces.qrc
