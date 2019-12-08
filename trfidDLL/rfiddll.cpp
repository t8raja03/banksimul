#include "rfiddll.h"
#include <QDebug>
RfidDLL::RfidDLL()
{
}

void RfidDLL::palautaPankkikortinNumeroKomponentti()
{
    serial = new QSerialPort(this);
    serial->setPortName("com3");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    // serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->setFlowControl(QSerialPort::HardwareControl);

    if (serial->open(QIODevice::ReadWrite))
    {
        qDebug() << serial->portName();
    }else {
        qDebug() << "Portin avaaminen ei onnistunut!";
    }
    connect(serial,SIGNAL(readyRead()),this,SLOT(tulostus()));

}

void RfidDLL::rajapintaSignaali()
{
    emit signaaliRpSignaali();
}

QString RfidDLL::tulostus()
{
    char data[20];
    int bytesread;
    bytesread= serial->read(data,20);
    data[bytesread] = '\0';
    if (bytesread>10)
    {
        for (int i=0;i<=9;i++)
        {
            cardSerialNumber = data;
        }
        cardSerialNumber.remove(0, 3);
        cardSerialNumber.remove(10,5);
        //cardSerialNumber.chop(3);

        qDebug() << "Kortin numero: " << cardSerialNumber << endl;
        emit SignaaliRFID(cardSerialNumber);
    }
    else
        qDebug()<<"Virhe korttia luettaessa!";

    return "palautettavaArvo";
}
