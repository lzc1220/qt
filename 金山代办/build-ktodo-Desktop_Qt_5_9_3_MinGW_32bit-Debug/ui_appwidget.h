/********************************************************************************
** Form generated from reading UI file 'appwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPWIDGET_H
#define UI_APPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AppWidget
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;

    void setupUi(QWidget *AppWidget)
    {
        if (AppWidget->objectName().isEmpty())
            AppWidget->setObjectName(QStringLiteral("AppWidget"));
        AppWidget->resize(305, 519);
        label = new QLabel(AppWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 81, 21));
        label->setStyleSheet(QLatin1String("font: 14pt \"Arial\";\n"
"font: 75 9pt \"Arial\";"));
        label_2 = new QLabel(AppWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 10, 281, 471));
        label_2->setFrameShape(QFrame::Box);
        label_2->setTextFormat(Qt::AutoText);
        label_2->setIndent(-1);
        label_3 = new QLabel(AppWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 70, 51, 61));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/res/doc.png")));
        label_4 = new QLabel(AppWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(90, 70, 81, 21));
        label_4->setStyleSheet(QLatin1String("font: 14pt \"Arial\";\n"
"font: 75 9pt \"Arial\";"));
        label_5 = new QLabel(AppWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(90, 150, 81, 21));
        label_5->setStyleSheet(QLatin1String("font: 14pt \"Arial\";\n"
"font: 75 9pt \"Arial\";"));
        label_6 = new QLabel(AppWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 150, 51, 61));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/res/doc.png")));
        label_7 = new QLabel(AppWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(90, 230, 81, 21));
        label_7->setStyleSheet(QLatin1String("font: 14pt \"Arial\";\n"
"font: 75 9pt \"Arial\";"));
        label_8 = new QLabel(AppWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 230, 51, 61));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/res/doc.png")));
        label_9 = new QLabel(AppWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(90, 310, 81, 21));
        label_9->setStyleSheet(QLatin1String("font: 14pt \"Arial\";\n"
"font: 75 9pt \"Arial\";"));
        label_10 = new QLabel(AppWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 310, 51, 61));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/res/doc.png")));
        label_11 = new QLabel(AppWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(90, 390, 81, 21));
        label_11->setStyleSheet(QLatin1String("font: 14pt \"Arial\";\n"
"font: 75 9pt \"Arial\";"));
        label_12 = new QLabel(AppWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 390, 51, 61));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/res/doc.png")));
        label_2->raise();
        label->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();
        label_9->raise();
        label_10->raise();
        label_11->raise();
        label_12->raise();

        retranslateUi(AppWidget);

        QMetaObject::connectSlotsByName(AppWidget);
    } // setupUi

    void retranslateUi(QWidget *AppWidget)
    {
        AppWidget->setWindowTitle(QApplication::translate("AppWidget", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("AppWidget", "\345\272\224\347\224\250\344\270\255\345\277\203", Q_NULLPTR));
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QApplication::translate("AppWidget", "\346\226\207\346\241\243", Q_NULLPTR));
        label_5->setText(QApplication::translate("AppWidget", "\346\226\207\346\241\243", Q_NULLPTR));
        label_6->setText(QString());
        label_7->setText(QApplication::translate("AppWidget", "\346\226\207\346\241\243", Q_NULLPTR));
        label_8->setText(QString());
        label_9->setText(QApplication::translate("AppWidget", "\346\226\207\346\241\243", Q_NULLPTR));
        label_10->setText(QString());
        label_11->setText(QApplication::translate("AppWidget", "\346\226\207\346\241\243", Q_NULLPTR));
        label_12->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AppWidget: public Ui_AppWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPWIDGET_H
