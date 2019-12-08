#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QString>
#include "banksimul_databaseLIB/banksimul_databaselib.h"
#include "trfidDLL/rfiddll.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void signal_card_read(QString card_id);

private slots:
    void on_pushButton_TEST_clicked();
    void card_read(QString id);
    void updateTime();
    void TimeOut();
    void pinOK(QString rfid, int pin);
    void withdraw(int amount);

    void on_pushButton_ok_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_C_clicked();

    void on_pushButton_D_clicked();

    void on_pushButton_H_clicked();

    void on_pushButton_G_clicked();

    void on_pushButton_B_clicked();

    void on_pushButton_F_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    unsigned int timeleft;
    QString cur_rfid;
    bool correct_pin;
    Banksimul_database *db;
    unsigned int mode;

    RfidDLL *kortti;

    void Timer(unsigned int time);
    void MainMenu();
    void Idle();
};
#endif // MAINWINDOW_H
