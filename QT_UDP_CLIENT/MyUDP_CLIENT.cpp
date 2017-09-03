#include "MyUDP_CLIENT.h"

void MyUDP_CLIENT::initUdp()
{
	this->udp_client->bind(QHostAddress::LocalHost,7755);
	this->connect(this->udp_client, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
}

void MyUDP_CLIENT::processDatagram(QByteArray datagram)
{
	qDebug() << datagram << endl;
}

MyUDP_CLIENT::MyUDP_CLIENT(QObject *parent)
	: QObject(parent),udp_client(nullptr),udp_data(nullptr)
{
	udp_client = new QUdpSocket(this);
	udp_data = new QObjectUserData;
	this->initUdp();
}

MyUDP_CLIENT::~MyUDP_CLIENT()
{
	delete[] udp_client;
	delete[] udp_data;
}

void MyUDP_CLIENT::readPendingDatagrams()
{
	while (this->udp_client->hasPendingDatagrams())
	{
		QByteArray datagram;
		datagram.resize(this->udp_client->pendingDatagramSize());
		QHostAddress sender;
		quint16 port;
		this->udp_client->readDatagram(datagram.data(), datagram.size(), &sender, &port);
		qDebug() << QDateTime::currentDateTime() << "udp_client : " << datagram << " from " << sender << " port : " << port << endl;
	}
}
