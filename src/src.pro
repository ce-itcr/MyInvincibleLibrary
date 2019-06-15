#-------------------------------------------------
#
# Project created by QtCreator 2019-05-29T16:56:26
#
#-------------------------------------------------
include(../defaults.pri)

QT       -= gui
QT += network
QT += core

TARGET = mylib
TEMPLATE = lib
CONFIG += staticlib

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        client/client.cpp \
        client/clientinterface.cpp \
        src.cpp \
    gallery/foldermanager.cpp \
    gallery/folder.cpp \
    gallery/image.cpp \
    json/jsonserializer.cpp \
    json/jsonconverter.cpp \
    Huffman/BinaryTree.cpp \
    Huffman/BinaryTreeNode.cpp \
    Huffman/HuffmanCompression.cpp \
    Huffman/List.cpp \
    Huffman/ListNode.cpp

HEADERS += \
        client/client.h \
        client/clientinterface.h \
        src.h \
    gallery/foldermanager.h \
    gallery/folder.h \
    gallery/image.h \
    json/jsonserializer.h \
    json/jsonserializable.h \
    json/jsonconverter.h \
    Huffman/BinaryTree.h \
    Huffman/BinaryTreeNode.h \
    Huffman/HuffmanCompression.h \
    Huffman/List.h \
    Huffman/ListNode.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \
    util/logger.txt

RESOURCES += \
    utilresources.qrc
