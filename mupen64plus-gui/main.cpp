#include "mainwindow.h"
#include <QApplication>
#include <QStyleFactory>
#include <QPalette>
#include <QCommandLineParser>
#include <QString>
#include <QSettings>

MainWindow *w = nullptr;
int main(int argc, char *argv[])
{
    srand (time(NULL));

    QApplication a(argc, argv);

    a.setStyle(QStyleFactory::create("Fusion"));

    #ifdef Q_OS_LINUX
        // Enable dark mode if user is on Linux (looks kind of ugly on Windows 10).
        // Feel free to change this for dark mode on other platforms.
        QPalette darkPalette;
        darkPalette.setColor(QPalette::Window, QColor(53,53,53));
        darkPalette.setColor(QPalette::WindowText, Qt::white);
        darkPalette.setColor(QPalette::Base, QColor(25,25,25));
        darkPalette.setColor(QPalette::AlternateBase, QColor(53,53,53));
        darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
        darkPalette.setColor(QPalette::ToolTipText, Qt::white);
        darkPalette.setColor(QPalette::Text, Qt::white);
        darkPalette.setColor(QPalette::Button, QColor(53,53,53));
        darkPalette.setColor(QPalette::ButtonText, Qt::white);
        darkPalette.setColor(QPalette::BrightText, Qt::red);
        darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));

        darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
        darkPalette.setColor(QPalette::HighlightedText, Qt::black);
    
        a.setPalette(darkPalette);

        a.setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");
    #endif

    QCoreApplication::setApplicationName("M64Core");

    QCommandLineParser parser;
    parser.addHelpOption();
    QCommandLineOption verboseOption({"v", "verbose"}, "Verbose mode. Prints out more information to log.");
    QCommandLineOption noGUIOption("nogui", "Disable GUI elements.");
    QCommandLineOption GLESOption("gles", "Request an OpenGL ES Context.");
    parser.addOption(verboseOption);
    parser.addOption(noGUIOption);
    parser.addOption(GLESOption);
    parser.addPositionalArgument("ROM", QCoreApplication::translate("main", "ROM to open."));
    parser.process(a);
    const QStringList args = parser.positionalArguments();

    w = new MainWindow();
    w->show();
    if (parser.isSet(verboseOption))
        w->setVerbose();
    if (parser.isSet(noGUIOption))
        w->setNoGUI();
    if (parser.isSet(GLESOption))
        w->setGLES();
    if (args.size() > 0)
#ifndef SINGLE_THREAD
        w->openROM(args.at(0), "", 0, 0);
#else
        w->singleThreadLaunch(args.at(0), "", 0, 0);
#endif
    else
        w->updateApp();

    return a.exec();
}
