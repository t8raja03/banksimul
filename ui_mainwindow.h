/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_TEST;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_A;
    QPushButton *pushButton_B;
    QPushButton *pushButton_C;
    QPushButton *pushButton_D;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_E;
    QPushButton *pushButton_F;
    QPushButton *pushButton_G;
    QPushButton *pushButton_H;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(600, 800);
        MainWindow->setMinimumSize(QSize(600, 800));
        MainWindow->setMaximumSize(QSize(600, 800));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(130, 50, 341, 281));
        textBrowser->setMinimumSize(QSize(341, 281));
        textBrowser->setMaximumSize(QSize(341, 281));
        QPalette palette;
        QBrush brush(QColor(85, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush1(QColor(0, 0, 127, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush2(QColor(85, 255, 255, 128));
        brush2.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        QBrush brush3(QColor(120, 120, 120, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        QBrush brush4(QColor(240, 240, 240, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        QBrush brush5(QColor(0, 0, 0, 128));
        brush5.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        textBrowser->setPalette(palette);
        QFont font;
        font.setPointSize(16);
        textBrowser->setFont(font);
        pushButton_TEST = new QPushButton(centralwidget);
        pushButton_TEST->setObjectName(QStringLiteral("pushButton_TEST"));
        pushButton_TEST->setGeometry(QRect(470, 410, 91, 71));
        pushButton_TEST->setAutoFillBackground(false);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 40, 77, 310));
        layoutWidget->setMinimumSize(QSize(77, 310));
        layoutWidget->setMaximumSize(QSize(77, 310));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_A = new QPushButton(layoutWidget);
        pushButton_A->setObjectName(QStringLiteral("pushButton_A"));
        pushButton_A->setMinimumSize(QSize(75, 50));
        pushButton_A->setMaximumSize(QSize(75, 50));

        verticalLayout->addWidget(pushButton_A);

        pushButton_B = new QPushButton(layoutWidget);
        pushButton_B->setObjectName(QStringLiteral("pushButton_B"));
        pushButton_B->setMinimumSize(QSize(75, 50));
        pushButton_B->setMaximumSize(QSize(75, 50));

        verticalLayout->addWidget(pushButton_B);

        pushButton_C = new QPushButton(layoutWidget);
        pushButton_C->setObjectName(QStringLiteral("pushButton_C"));
        pushButton_C->setMinimumSize(QSize(75, 50));
        pushButton_C->setMaximumSize(QSize(75, 50));

        verticalLayout->addWidget(pushButton_C);

        pushButton_D = new QPushButton(layoutWidget);
        pushButton_D->setObjectName(QStringLiteral("pushButton_D"));
        pushButton_D->setMinimumSize(QSize(75, 50));
        pushButton_D->setMaximumSize(QSize(75, 50));

        verticalLayout->addWidget(pushButton_D);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(510, 40, 77, 310));
        layoutWidget1->setMinimumSize(QSize(77, 310));
        layoutWidget1->setMaximumSize(QSize(77, 310));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_E = new QPushButton(layoutWidget1);
        pushButton_E->setObjectName(QStringLiteral("pushButton_E"));
        pushButton_E->setMinimumSize(QSize(75, 50));
        pushButton_E->setMaximumSize(QSize(75, 50));

        verticalLayout_2->addWidget(pushButton_E);

        pushButton_F = new QPushButton(layoutWidget1);
        pushButton_F->setObjectName(QStringLiteral("pushButton_F"));
        pushButton_F->setMinimumSize(QSize(75, 50));
        pushButton_F->setMaximumSize(QSize(75, 50));

        verticalLayout_2->addWidget(pushButton_F);

        pushButton_G = new QPushButton(layoutWidget1);
        pushButton_G->setObjectName(QStringLiteral("pushButton_G"));
        pushButton_G->setMinimumSize(QSize(75, 50));
        pushButton_G->setMaximumSize(QSize(75, 50));

        verticalLayout_2->addWidget(pushButton_G);

        pushButton_H = new QPushButton(layoutWidget1);
        pushButton_H->setObjectName(QStringLiteral("pushButton_H"));
        pushButton_H->setMinimumSize(QSize(75, 50));
        pushButton_H->setMaximumSize(QSize(75, 50));

        verticalLayout_2->addWidget(pushButton_H);

        pushButton_ok = new QPushButton(centralwidget);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(470, 560, 91, 50));
        pushButton_ok->setMinimumSize(QSize(50, 50));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(470, 490, 91, 50));
        pushButton_9->setMinimumSize(QSize(50, 50));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "L-OTTO", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:16pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt;\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2';\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2';\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph"
                        "-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2';\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">Tervetuloa,</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">sy\303\266t\303\244 kortti</span></p></body></html>", Q_NULLPTR));
        pushButton_TEST->setText(QApplication::translate("MainWindow", "KORTTI", Q_NULLPTR));
        pushButton_A->setText(QString());
        pushButton_B->setText(QString());
        pushButton_C->setText(QString());
        pushButton_D->setText(QString());
        pushButton_E->setText(QString());
        pushButton_F->setText(QString());
        pushButton_G->setText(QString());
        pushButton_H->setText(QString());
        pushButton_ok->setText(QApplication::translate("MainWindow", "oikea pin", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("MainWindow", "v\303\244\303\244r\303\244 pin", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
