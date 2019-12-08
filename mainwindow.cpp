#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer;

    kortti = new RfidDLL;
    kortti->palautaPankkikortinNumeroKomponentti();

    pinkysely = new Pinwindow;

    Idle();

    this->connect(this, SIGNAL(signal_card_read(QString)), this, SLOT(card_read(QString)));
    this->connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    this->connect(kortti, SIGNAL(SignaaliRFID(QString)), this, SLOT(card_read(QString)));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
    delete db;
    delete kortti;
    delete pinkysely;
}

void MainWindow::card_read(QString id)
{
    if (mode==1) {
        cur_rfid = id;
        db = new Banksimul_database;
        db->connect();
        qDebug() << cur_rfid;
        ui->textBrowser->setText("<p align=center><br><br><br>Syötä pin-koodi</p>");
        pinkysely->showPinWindowAPI();
        Timer(10);
    }
}

void MainWindow::updateTime()
{
    timeleft--;
    if (timeleft==0) {
        //emit signal_screenTimeOut();
        timer->stop();
        TimeOut();
    }
    else
        qDebug() << "Timeout in: " << timeleft;
}

void MainWindow::Timer(unsigned int time)
{
    if (timer->isActive()) {
        timer->stop();
    }

    timeleft = time;
    timer->setInterval(1000);
    timer->start();
    qDebug() << "timer start";
}

void MainWindow::TimeOut()
{
    qDebug() << "TimeOut()";
    switch (mode){

    case 1:         //Aloitustila
        Idle();
        break;

    case 12:        //Väärä pin
        Idle();
        break;

    case 2:         //Oikea pin
        MainMenu();
        break;

    case 21:        //Main menu
        Idle();
        break;

    case 3:         //Näytä saldo
        MainMenu();
        break;

    case 4:         //Nosta rahaa
        MainMenu();
        break;

    case 5:
        MainMenu();
        break;

    case 6:
        MainMenu();
        break;
    }
}

void MainWindow::pinOK(QString rfid, int pin)
{
    if (db->checkPIN(pin,rfid)==true){                                                 //TODO: Tänne syötetty pin ja luettu RFID
        correct_pin = true;
        ui->textBrowser->setText("<p align=center><br><br><br>PIN OK</p>");
        mode = 2;
        Timer(2);
    }
    else {
        ui->textBrowser->setText("<p align=center><br><br><br>VÄÄRÄ PIN</p>");
        correct_pin = false;
        mode = 12;
        Timer(2);
    }
}

void MainWindow::MainMenu()
{
    qDebug() << "MainMenu()";
    ui->textBrowser->setText("<p align=center><br>Hei<br>Valitse toiminto:<br></p>"
                             "<p align=left><br><br>"
                             "Näytä saldo . . . . . . . Nosta rahaa<br><br><br>"
                             "Selaa tilitapahtumia . . . . . Lopeta</p>");
    mode = 21;
    Timer(30);
}

void MainWindow::Idle()
{
    timer->stop();
    mode = 1;
    correct_pin = false;
    cur_rfid = "0";
    qDebug() << "Idle()";
    delete db;
    correct_pin = false;
    ui->textBrowser->setText("<p align=center><br><br><br>Tervetuloa,<br>syötä kortti</p>");
}

void MainWindow::withdraw(int amount)
{
    int success = db->withdraw(cur_rfid, amount);
    QString balance;
    mode = 5;
    switch (success) {
        case 0:
            ui->textBrowser->setText("<p align=center><br><br><br>Varat eivät riitä</p>"
                                     "<p align=left><br><br><br><br><br>"
                                     "Paluu</p>");
            Timer(3);
            break;
        case 1:
            balance = QString::number(db->checkBalance(cur_rfid));
            ui->textBrowser->setText("<p align=center><br><br><br>Ota rahat</p>"
                                     "<p align=left><br><br><br>"
                                     "Tililtä nostettavissa: " + balance + " eur<br><br>"
                                     "Paluu</p>");
            Timer(10);
            break;
        case 2:
            ui->textBrowser->setText("<p align=center><br><br><br>Jotain meni pieleen</p>"
                                     "<p align=left><br><br><br><br><br>"
                                     "Paluu</p>");
            Timer(3);
            break;
    }
}

void MainWindow::on_pushButton_TEST_clicked()       //TESTIKÄYTTÖÄ VARTEN, KORTIN SYÖTTÖ
{
        emit signal_card_read("0B00320D2B");
}

void MainWindow::on_pushButton_ok_clicked()     //TESTIKÄYTTÖÄ VARTEN, OIKEA PIN
{
    if (mode==1)
        pinOK(cur_rfid, 9876);
}

void MainWindow::on_pushButton_9_clicked()      //TESTIKÄYTTÖÄ VARTEN, VÄÄRÄ PIN
{
    if(mode==1)
        pinOK(cur_rfid, 9875);
}

void MainWindow::on_pushButton_C_clicked()
{
    switch (mode) {

    case 4:
        withdraw(50);
        break;

    case 21:
        mode = 3;
        if(correct_pin) {
            QString balance = QString::number(db->checkBalance(cur_rfid));
            ui->textBrowser->setText("<p align=center><br><br><br>Tililtä nostettavissa: <br>" + balance + " eur</p>"
                                     "<p align= left><br><br><br><br>"
                                     "Paluu . . . . . . . . . . . . . . . . Lopeta");
            Timer(10);
        }
        break;
    }

}

void MainWindow::on_pushButton_D_clicked()
{
    QString transactions = db->transactions(cur_rfid, 5);
    switch (mode) {
    case 21:
        mode = 6;
        Timer(10);
        ui->textBrowser->setText(transactions);
        break;
    case 3:
        MainMenu();
        break;
    case 4:
        MainMenu();
        break;
    case 5:
        MainMenu();
        break;
    case 6:
        MainMenu();
        break;
    }
}

void MainWindow::on_pushButton_H_clicked()
{
    Idle();
}

void MainWindow::on_pushButton_G_clicked()
{
    switch (mode) {
    case 4:
        withdraw(100);
        break;
    case 21:
        mode = 4;
        ui->textBrowser->setText("<p align=center><br>Valitse summa:<br></p>"
                                 "<p align=left>"
                                 "20€ . . . . . . . . . . . . . . . . . .40€<br><br><br>"
                                 "50€ . . . . . . . . . . . . . . . . . 100€<br><br><br>"
                                 "Paluu . . . . . . . . . . . . . . . Lopeta</p>");
        Timer(10);
        break;
    }
}

void MainWindow::on_pushButton_B_clicked()
{
    if (mode == 4)
        withdraw(20);

}

void MainWindow::on_pushButton_F_clicked()
{
    switch (mode) {
    case 4:
        withdraw(40);
        break;
    }
}
