#ifndef PINWINDOW_H
#define PINWINDOW_H

#include "pinwindow_global.h"
#include "pinwindowengine.h"

#include <QObject>

class PINWINDOW_EXPORT Pinwindow:public QObject
{

    Q_OBJECT

private:
    pinWindowEngine *pinDialog;

public:
    Pinwindow();
    void showPinWindowAPI();
};

#endif // PINWINDOW_H
