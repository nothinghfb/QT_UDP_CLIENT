#include "MyUDP_CLIENT.h"

#include <QtCore/QCoreApplication>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	MyUDP_CLIENT client;
	return a.exec();
}
