#ifndef PINWINDOW_GLOBAL_H
#define PINWINDOW_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PINWINDOW_LIBRARY)
#  define PINWINDOW_EXPORT Q_DECL_EXPORT
#else
#  define PINWINDOW_EXPORT Q_DECL_IMPORT
#endif

#endif // PINWINDOW_GLOBAL_H
