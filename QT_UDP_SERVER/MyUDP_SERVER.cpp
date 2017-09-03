#include "MyUDP_SERVER.h"

void MyUDP_SERVER::initUdp()
{

}

MyUDP_SERVER::MyUDP_SERVER(QObject *parent)
	: QObject(parent)
{
	timerId_sendMsg = startTimer(100);
	udp_server = new QUdpSocket;
}

MyUDP_SERVER::~MyUDP_SERVER()
{
	delete udp_server;
}

void MyUDP_SERVER::timerEvent(QTimerEvent *event)
{
	if (event->timerId() == timerId_sendMsg)
	{
		
		int number = rand();
// 		char dst[100];
// 		gcvt(number, 10, dst);
// 		

// 		MyStruct dst;
// 		dst.a = number % 256;
// 		number = rand();
// 		dst.b = number % 256;

		MyStruct dst;
		strcpy_s(dst.a, "I Love You");
		strcpy_s(dst.b, "You Love Me");
		unsigned short int * dstt = (unsigned short int*)&dst;
		unsigned char tem[30];
		memcpy((void*)tem, (void*)&dst, sizeof(char) * 30);
		QString str((char*)&dst);
		QByteArray data(dst.a);
		data.append(QByteArray(dst.b));
		
		char* dataPtr = data.data();
		qDebug() << QDateTime::currentDateTime() << "QByteArray : " << data << endl;
		qDebug() << QDateTime::currentDateTime() << "QString    : " << str << endl;
		QHostAddress host(QHostAddress::LocalHost);
		quint16 port = 7755;
		quint64 rt = this->udp_server->writeDatagram(data,host,port);
		rt = this->udp_server->writeDatagram((char*)dstt, host, port);
		qDebug() << QDateTime::currentDateTime() << "udp_server : " << rt << endl;
	}
}
