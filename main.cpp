
#include <QWidget>
#include <QDir>
#include <QUrl>
#include <QHostAddress>
#include <QFileInfo>
#include <QWebChannel>
#include <QWebSocketServer>
#include <QtWidgets/QApplication>

#include "websocketclientwrapper.h"
#include "brige.h"
#include "widget.h"
#include "websockettransport.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
    QFileInfo jsFile(QDir::currentPath() + "/qwebchannel.js");

    if (!jsFile.exists())
    {
        QFile::copy(":/qtwebchannel.qwebchannel.js", jsFile.absoluteFilePath());
    }

    //set websocketserver
    QWebSocketServer server(QStringLiteral("myServer"), QWebSocketServer::NonSecureMode);
    if (!server.listen(QHostAddress::LocalHost, 12345))
    {
        qFatal("Failed to open web socket server.");
        return 1;
    }

    WebSocketClientWrapper clientWrapper(&server);

    QWebChannel channel;
    QObject::connect(&clientWrapper, &WebSocketClientWrapper::clientConnected,
                    &channel, &QWebChannel::connectTo);

    Widget w;

    Brige brige(&w);
    channel.registerObject(QStringLiteral("brige"), &brige);

    w.showMinimized();
    return a.exec();
}
