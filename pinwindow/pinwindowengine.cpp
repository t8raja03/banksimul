#include "pinwindowengine.h"
#include "ui_pinwindowengine.h"

pinWindowEngine::pinWindowEngine(QWidget *parent) :
    QDialog(parent),
    pinUi(new Ui::pinWindowEngine)
{
    pinUi->setupUi(this);
}

pinWindowEngine::~pinWindowEngine()
{
    delete pinUi;
}

void pinWindowEngine::on_pushButton_clicked()
{
    this->close();
}
