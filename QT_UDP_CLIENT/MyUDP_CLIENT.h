#pragma once

#include <QObject>
#include <QString>
#include <QStringList>
#include <QList>
#include <QVector>
#include <QTest>
#include <QDebug>

#include <QByteArray>
#include <QHostAddress>
#include <QUdpSocket>
#include <QObjectUserData>

class MyUDP_CLIENT : public QObject
{
	Q_OBJECT

public:
	QUdpSocket* udp_client;
	QObjectUserData* udp_data;

public:
	void initUdp();
	void processDatagram(QByteArray datagram);
public:
	MyUDP_CLIENT(QObject *parent = nullptr);
	~MyUDP_CLIENT();

signals:
	void readyRead();
public slots:
	void readPendingDatagrams();
};
