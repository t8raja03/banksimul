#ifndef BANKSIMUL_DATABASELIB_H
#define BANKSIMUL_DATABASELIB_H

#include "banksimul_databaseLIB_global.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QString>
#include <QStringList>


class Banksimul_database
{
public:
    bool BANKSIMUL_DATABASELIB_EXPORT connect();                                    //yhdistää myslin tietokantaan
    bool BANKSIMUL_DATABASELIB_EXPORT checkPIN(int inputpin, QString rfid);         //palauttaa TRUE, jos RFID:hen liitetty PIN on oikein, FALSE jos ei
    float BANKSIMUL_DATABASELIB_EXPORT checkBalance(QString rfid);                  //palauttaa RFID:hen liitetyn tilin saldon (float)
    int BANKSIMUL_DATABASELIB_EXPORT withdraw(QString rfid, int sum);               //palauttaa 0 jos ei rahaa, 1 jos onnistui, 2 jos jotain meni pieleen
    QString BANKSIMUL_DATABASELIB_EXPORT transactions(QString rfid, int count);     //palauttaa tekstinä COUNT määrän tapahtumia
};

#endif // BANKSIMUL_DATABASELIB_H
