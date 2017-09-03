#pragma once

#include <QObject>
#include <QString>
#include <QStringList>
#include <QList>
#include <QVector>
#include <QTest>
#include <QDebug>
#include <QTime>
#include <QTimer>
#include <QTimerEvent>
#include <QDateTime>
#include <QUdpSocket>
#include <QObjectUserData>
#include <QtMath>

struct MyStruct
{
	char a[15];
	char b[15];
};

class MyClass : public QObject
{
public:
	unsigned short int a[15];
	unsigned short int b[15];
};



class MyUDP_SERVER : public QObject
{
	Q_OBJECT

public:
	quint16 timerId_sendMsg;
	QUdpSocket *udp_server;
public:
	void initUdp();
public:
	MyUDP_SERVER(QObject *parent = nullptr);
	~MyUDP_SERVER();

protected:
	void timerEvent(QTimerEvent *event);
};
