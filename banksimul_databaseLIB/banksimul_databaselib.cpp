#include "banksimul_databaselib.h"


bool Banksimul_database::connect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("mysli.oamk.fi");
    db.setDatabaseName("opisk_t8raja03");
    db.setUserName("t8raja03");
    db.setPassword("bnym6iR");
    bool ok = db.open();
    return ok;
}

bool Banksimul_database::checkPIN(int inputpin, QString rfid)
{
    QString query = "SELECT PIN FROM banksimul_card WHERE RFID='" + rfid + "'";
    QSqlQuery pin;
    pin.exec(query);
    pin.next();
    if (pin.value(0)==inputpin) return true;
    else return false;
}

float Banksimul_database::checkBalance(QString rfid)
{
    QString query = "SELECT balance FROM banksimul_balances WHERE RFID='" + rfid + "'";
    QSqlQuery checkbal;
    checkbal.exec(query);
    checkbal.next();
    float balance = checkbal.value(0).toFloat();
    return balance;
}

int Banksimul_database::withdraw(QString rfid, int sum)
{
    float balance = checkBalance(rfid);
    if (balance < sum)
        return 0;
    else {
        QString query = "CALL banksimul_transfer('" + rfid + "','Automaattinosto','" + QString::number(-sum) + "')";
        QSqlQuery withdraw;
        if (!withdraw.exec(query))
            return 2;
        return 1;
    }
}

QString Banksimul_database::transactions(QString rfid, int count)
{
    QString list = "<p align=left>";
    QString query = "CALL banksimul_transactions('" + rfid + "','" + QString::number(count) + "')";
    QSqlQuery trans;
    trans.exec(query);
    while (trans.next()) {
        QString sumstring = trans.value(0).toString();
        QString descr = trans.value(1).toString();
        QString time = trans.value(2).toString();
        time.remove(10,10);
        list.append(time);
        list.append(": ");
        list.append(descr);
        list.append(" ");
        list.append(sumstring);
        list.append("<br>");
    }
    list.append("<br><br><br><br>Paluu</p>");
    return list;
}
