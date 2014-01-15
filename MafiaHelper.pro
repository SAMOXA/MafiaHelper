# Add more folders to ship with the application, here
folder_01.source = qml/MafiaHelper
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    player.cpp \
    roles/regularrole.cpp \
    roles/policemanrole.cpp \
    roles/mafiarole.cpp \
    roles/prostituterole.cpp \
    roles/doctorrole.cpp \
    roles/immortalrole.cpp \
    roles/witchrole.cpp \
    roles/sleepwalkerrole.cpp \
    pagestack.cpp

# Installation path
# target.path =

# Please do not modify the following two lines. Required for deployment.
include(qtquick2applicationviewer/qtquick2applicationviewer.pri)
qtcAddDeployment()

HEADERS += \
    abstractrole.h \
    player.h \
    roles/regularrole.h \
    roles/policemanrole.h \
    roles/mafiarole.h \
    roles/prostituterole.h \
    roles/doctorrole.h \
    roles/immortalrole.h \
    roles/witchrole.h \
    roles/sleepwalkerrole.h \
    pagestack.h

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

OTHER_FILES += \
    qml/MafiaHelper/PageStack.qml
