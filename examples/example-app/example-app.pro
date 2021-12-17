QT += quick

DESTDIR = $$OUT_PWD

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

RESOURCES += \
    resources.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# copy qmldir file into target directory as well
extraFiles.files += $$PWD/../../build/lib/qml/Aqt/StyleSheets/qmldir
extraFiles.files += $$PWD/../../build/lib/qml/Aqt/StyleSheets/libStylePlugin.so
extraFiles.files += $$PWD/../../build/lib/qml/Aqt/StyleSheets/StyleDebugMouseArea.qml
extraFiles.files += $$PWD/../../build/lib/qml/Aqt/StyleSheets/styleUtils.js
extraFiles.path = $$DESTDIR/modules/Aqt/StyleSheets
CONFIG += copies
COPIES += extraFiles
