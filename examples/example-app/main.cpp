#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QFileInfo>
#include <QDir>

namespace  {

// Helper function for handling OS specific path structures
QString getImportDirPath(const QString &importDirName)
{
#ifdef Q_OS_MACOS
    const QFileInfo result(QGuiApplication::applicationDirPath(), "../../../" + importDirName);
#else
    const QFileInfo result(QDir(QGuiApplication::applicationDirPath()), importDirName);
#endif
    qInfo() << "import path:" << result.absoluteFilePath();
    Q_ASSERT(result.exists() && result.isDir());

    return result.absoluteFilePath();
}

}

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    // add our own plugin's location to the QML engine's plugin search paths
    const QString importsDirPath = getImportDirPath("modules");
    engine.addImportPath(importsDirPath);
    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
