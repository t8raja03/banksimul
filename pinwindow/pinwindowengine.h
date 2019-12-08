#ifndef PINWINDOWENGINE_H
#define PINWINDOWENGINE_H

#include <QDialog>

namespace Ui {
    class pinWindowEngine;
}

class pinWindowEngine : public QDialog
{
    Q_OBJECT

public:
    explicit pinWindowEngine(QWidget *parent = nullptr);
    ~pinWindowEngine();

private slots:

    void on_pushButton_clicked();

private:
    Ui::pinWindowEngine *pinUi;
};

#endif // PINWINDOWENGINE_H
