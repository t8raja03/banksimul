#include "pinwindow.h"

Pinwindow::Pinwindow()
{
    pinDialog = new pinWindowEngine;
}

void Pinwindow::showPinWindowAPI()
{
    pinDialog->show();
    pinDialog->exec();
}
