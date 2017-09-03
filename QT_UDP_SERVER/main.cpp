#include "MyUDP_SERVER.h"

#include <QtCore/QCoreApplication>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	MyUDP_SERVER server;
	return a.exec();
}
