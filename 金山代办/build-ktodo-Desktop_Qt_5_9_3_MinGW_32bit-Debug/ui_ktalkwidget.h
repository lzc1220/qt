/********************************************************************************
** Form generated from reading UI file 'ktalkwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KTALKWIDGET_H
#define UI_KTALKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KTalkWidget
{
public:
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_7;

    void setupUi(QWidget *KTalkWidget)
    {
        if (KTalkWidget->objectName().isEmpty())
            KTalkWidget->setObjectName(QStringLiteral("KTalkWidget"));
        KTalkWidget->resize(249, 320);
        label_5 = new QLabel(KTalkWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(80, 140, 121, 21));
        label_5->setStyleSheet(QLatin1String("font: 14pt \"Arial\";\n"
"font: 75 9pt \"Arial\";"));
        label_4 = new QLabel(KTalkWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(80, 60, 131, 21));
        label_4->setStyleSheet(QLatin1String("font: 14pt \"Arial\";\n"
"font: 75 9pt \"Arial\";"));
        label_2 = new QLabel(KTalkWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 20, 221, 271));
        label_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_2->setFrameShape(QFrame::Box);
        label_2->setFrameShadow(QFrame::Plain);
        label_2->setTextFormat(Qt::AutoText);
        label_2->setIndent(-1);
        label_7 = new QLabel(KTalkWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(80, 220, 131, 21));
        label_7->setStyleSheet(QLatin1String("font: 14pt \"Arial\";\n"
"font: 75 9pt \"Arial\";"));
        label_2->raise();
        label_5->raise();
        label_4->raise();
        label_7->raise();

        retranslateUi(KTalkWidget);

        QMetaObject::connectSlotsByName(KTalkWidget);
    } // setupUi

    void retranslateUi(QWidget *KTalkWidget)
    {
        KTalkWidget->setWindowTitle(QApplication::translate("KTalkWidget", "Form", Q_NULLPTR));
        label_5->setText(QApplication::translate("KTalkWidget", "\346\226\260\347\232\204\350\201\224\347\263\273\344\272\272", Q_NULLPTR));
        label_4->setText(QApplication::translate("KTalkWidget", "\345\212\236\345\205\254\344\270\216\345\215\217\344\275\234", Q_NULLPTR));
        label_2->setText(QString());
        label_7->setText(QApplication::translate("KTalkWidget", "\346\227\245\347\250\213\344\270\216\346\266\210\346\201\257", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class KTalkWidget: public Ui_KTalkWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KTALKWIDGET_H
