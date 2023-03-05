/********************************************************************************
** Form generated from reading UI file 'ktodo.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KTODO_H
#define UI_KTODO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KTodo
{
public:
    QLabel *logo_label;
    QLabel *label;
    QScrollArea *groupScrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *groupLabel;
    QLineEdit *addTodoItemLineEdit;
    QScrollArea *itemScrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QCheckBox *checkBox;
    QComboBox *comboBox;
    QPushButton *addGroupSaveBtn;
    QLineEdit *addGroupLineEdit;
    QCalendarWidget *addItemCalendarWidget;
    QPushButton *addItemBtn;
    QPushButton *addItemSetDateBtn;
    QCheckBox *isRepeatCheckbox;
    QLineEdit *descriLinedit;
    QLineEdit *noteLinedit;
    QLineEdit *locLineedit;
    QLineEdit *setActiLinedit;
    QPushButton *updateActBtn;
    QDateEdit *ringDateEdit;
    QDateEdit *dueDateEdit;
    QPushButton *updateActBtn1;
    QPushButton *updateActBtn2;
    QLabel *hidLabel;
    QPushButton *deleteButton;
    QPushButton *createTimeSortBtn;
    QPushButton *prioritySortBtn;
    QPushButton *duetimeSortBtn;
    QLabel *setDueLabel;
    QLabel *setRemLabel;

    void setupUi(QWidget *KTodo)
    {
        if (KTodo->objectName().isEmpty())
            KTodo->setObjectName(QStringLiteral("KTodo"));
        KTodo->resize(1908, 1087);
        logo_label = new QLabel(KTodo);
        logo_label->setObjectName(QStringLiteral("logo_label"));
        logo_label->setGeometry(QRect(140, 70, 171, 31));
        logo_label->setStyleSheet(QStringLiteral("font: 16pt \"Arial\";"));
        logo_label->setFrameShape(QFrame::NoFrame);
        logo_label->setFrameShadow(QFrame::Plain);
        logo_label->setMidLineWidth(0);
        logo_label->setTextFormat(Qt::AutoText);
        label = new QLabel(KTodo);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 60, 61, 51));
        label->setPixmap(QPixmap(QString::fromUtf8(":/res/logo.png")));
        groupScrollArea = new QScrollArea(KTodo);
        groupScrollArea->setObjectName(QStringLiteral("groupScrollArea"));
        groupScrollArea->setGeometry(QRect(60, 160, 350, 600));
        groupScrollArea->setMinimumSize(QSize(350, 600));
        groupScrollArea->setMaximumSize(QSize(400, 600));
        groupScrollArea->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        groupScrollArea->setFrameShape(QFrame::NoFrame);
        groupScrollArea->setFrameShadow(QFrame::Sunken);
        groupScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 350, 600));
        groupScrollArea->setWidget(scrollAreaWidgetContents);
        groupLabel = new QLabel(KTodo);
        groupLabel->setObjectName(QStringLiteral("groupLabel"));
        groupLabel->setGeometry(QRect(500, 170, 171, 71));
        groupLabel->setStyleSheet(QStringLiteral("font: 87 16pt \"Arial Black\";"));
        addTodoItemLineEdit = new QLineEdit(KTodo);
        addTodoItemLineEdit->setObjectName(QStringLiteral("addTodoItemLineEdit"));
        addTodoItemLineEdit->setGeometry(QRect(500, 250, 641, 41));
        addTodoItemLineEdit->setStyleSheet(QStringLiteral(""));
        itemScrollArea = new QScrollArea(KTodo);
        itemScrollArea->setObjectName(QStringLiteral("itemScrollArea"));
        itemScrollArea->setGeometry(QRect(490, 340, 821, 631));
        itemScrollArea->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        itemScrollArea->setFrameShape(QFrame::NoFrame);
        itemScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 821, 631));
        itemScrollArea->setWidget(scrollAreaWidgetContents_2);
        checkBox = new QCheckBox(KTodo);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(1460, 190, 361, 31));
        comboBox = new QComboBox(KTodo);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(1460, 290, 121, 31));
        comboBox->setIconSize(QSize(16, 16));
        addGroupSaveBtn = new QPushButton(KTodo);
        addGroupSaveBtn->setObjectName(QStringLiteral("addGroupSaveBtn"));
        addGroupSaveBtn->setGeometry(QRect(390, 770, 41, 31));
        addGroupLineEdit = new QLineEdit(KTodo);
        addGroupLineEdit->setObjectName(QStringLiteral("addGroupLineEdit"));
        addGroupLineEdit->setGeometry(QRect(110, 770, 281, 31));
        addGroupLineEdit->setStyleSheet(QStringLiteral("font: 10pt \"Arial\";"));
        addItemCalendarWidget = new QCalendarWidget(KTodo);
        addItemCalendarWidget->setObjectName(QStringLiteral("addItemCalendarWidget"));
        addItemCalendarWidget->setGeometry(QRect(1310, 250, 300, 300));
        addItemCalendarWidget->setMinimumSize(QSize(300, 300));
        addItemCalendarWidget->setMaximumSize(QSize(300, 300));
        addItemBtn = new QPushButton(KTodo);
        addItemBtn->setObjectName(QStringLiteral("addItemBtn"));
        addItemBtn->setGeometry(QRect(1240, 250, 71, 41));
        addItemBtn->setStyleSheet(QStringLiteral("background-color: rgb(240, 240, 240);"));
        addItemBtn->setFlat(false);
        addItemSetDateBtn = new QPushButton(KTodo);
        addItemSetDateBtn->setObjectName(QStringLiteral("addItemSetDateBtn"));
        addItemSetDateBtn->setGeometry(QRect(1160, 250, 71, 41));
        addItemSetDateBtn->setStyleSheet(QStringLiteral("alternate-background-color: rgb(255, 255, 25);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/res/date.png"), QSize(), QIcon::Normal, QIcon::Off);
        addItemSetDateBtn->setIcon(icon);
        addItemSetDateBtn->setFlat(true);
        isRepeatCheckbox = new QCheckBox(KTodo);
        isRepeatCheckbox->setObjectName(QStringLiteral("isRepeatCheckbox"));
        isRepeatCheckbox->setGeometry(QRect(1310, 270, 81, 31));
        isRepeatCheckbox->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        descriLinedit = new QLineEdit(KTodo);
        descriLinedit->setObjectName(QStringLiteral("descriLinedit"));
        descriLinedit->setGeometry(QRect(1460, 510, 301, 41));
        descriLinedit->setStyleSheet(QLatin1String("font: 9pt \"Arial\";\n"
"color: rgb(120, 120, 120);"));
        descriLinedit->setFrame(false);
        noteLinedit = new QLineEdit(KTodo);
        noteLinedit->setObjectName(QStringLiteral("noteLinedit"));
        noteLinedit->setGeometry(QRect(1460, 690, 301, 41));
        noteLinedit->setStyleSheet(QLatin1String("font: 9pt \"Arial\";\n"
"color: rgb(120, 120, 120);"));
        noteLinedit->setFrame(false);
        locLineedit = new QLineEdit(KTodo);
        locLineedit->setObjectName(QStringLiteral("locLineedit"));
        locLineedit->setGeometry(QRect(1460, 600, 301, 41));
        locLineedit->setStyleSheet(QLatin1String("color: rgb(120, 120, 120);\n"
"font: 9pt \"Arial\";"));
        locLineedit->setFrame(false);
        setActiLinedit = new QLineEdit(KTodo);
        setActiLinedit->setObjectName(QStringLiteral("setActiLinedit"));
        setActiLinedit->setGeometry(QRect(1460, 230, 181, 41));
        setActiLinedit->setStyleSheet(QLatin1String("font: 9pt \"Arial\";\n"
"color: rgb(120, 120, 120);"));
        setActiLinedit->setFrame(false);
        updateActBtn = new QPushButton(KTodo);
        updateActBtn->setObjectName(QStringLiteral("updateActBtn"));
        updateActBtn->setGeometry(QRect(1680, 230, 41, 41));
        updateActBtn->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        updateActBtn->setFlat(false);
        ringDateEdit = new QDateEdit(KTodo);
        ringDateEdit->setObjectName(QStringLiteral("ringDateEdit"));
        ringDateEdit->setGeometry(QRect(1460, 420, 301, 51));
        ringDateEdit->setFrame(false);
        dueDateEdit = new QDateEdit(KTodo);
        dueDateEdit->setObjectName(QStringLiteral("dueDateEdit"));
        dueDateEdit->setGeometry(QRect(1460, 340, 301, 51));
        dueDateEdit->setFrame(false);
        updateActBtn1 = new QPushButton(KTodo);
        updateActBtn1->setObjectName(QStringLiteral("updateActBtn1"));
        updateActBtn1->setGeometry(QRect(1790, 340, 41, 51));
        updateActBtn1->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        updateActBtn1->setFlat(false);
        updateActBtn2 = new QPushButton(KTodo);
        updateActBtn2->setObjectName(QStringLiteral("updateActBtn2"));
        updateActBtn2->setGeometry(QRect(1790, 420, 41, 51));
        updateActBtn2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        updateActBtn2->setFlat(false);
        hidLabel = new QLabel(KTodo);
        hidLabel->setObjectName(QStringLiteral("hidLabel"));
        hidLabel->setGeometry(QRect(1530, 400, 301, 81));
        hidLabel->setStyleSheet(QLatin1String("\n"
"font: 14pt \"Arial\";"));
        deleteButton = new QPushButton(KTodo);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(1460, 780, 101, 41));
        deleteButton->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 9pt \"Arial\";\n"
"color: rgb(120, 120, 120);"));
        createTimeSortBtn = new QPushButton(KTodo);
        createTimeSortBtn->setObjectName(QStringLiteral("createTimeSortBtn"));
        createTimeSortBtn->setGeometry(QRect(1170, 80, 131, 51));
        createTimeSortBtn->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 9pt \"Arial\";"));
        prioritySortBtn = new QPushButton(KTodo);
        prioritySortBtn->setObjectName(QStringLiteral("prioritySortBtn"));
        prioritySortBtn->setGeometry(QRect(1170, 130, 131, 51));
        prioritySortBtn->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 9pt \"Arial\";"));
        duetimeSortBtn = new QPushButton(KTodo);
        duetimeSortBtn->setObjectName(QStringLiteral("duetimeSortBtn"));
        duetimeSortBtn->setGeometry(QRect(1170, 30, 131, 51));
        duetimeSortBtn->setStyleSheet(QLatin1String("font: 9pt \"Arial\";\n"
"background-color: rgb(255, 255, 255);"));
        setDueLabel = new QLabel(KTodo);
        setDueLabel->setObjectName(QStringLiteral("setDueLabel"));
        setDueLabel->setGeometry(QRect(1610, 350, 111, 21));
        setDueLabel->setStyleSheet(QLatin1String("font: 10pt \"Arial\";\n"
"background-color: rgb(255, 255, 255);"));
        setRemLabel = new QLabel(KTodo);
        setRemLabel->setObjectName(QStringLiteral("setRemLabel"));
        setRemLabel->setGeometry(QRect(1610, 430, 101, 21));
        setRemLabel->setStyleSheet(QLatin1String("font: 10pt \"Arial\";\n"
"background-color: rgb(255, 255, 255);"));
        checkBox->raise();
        comboBox->raise();
        logo_label->raise();
        label->raise();
        groupScrollArea->raise();
        groupLabel->raise();
        addTodoItemLineEdit->raise();
        itemScrollArea->raise();
        addGroupSaveBtn->raise();
        addGroupLineEdit->raise();
        addItemBtn->raise();
        addItemSetDateBtn->raise();
        descriLinedit->raise();
        noteLinedit->raise();
        locLineedit->raise();
        setActiLinedit->raise();
        updateActBtn->raise();
        ringDateEdit->raise();
        dueDateEdit->raise();
        updateActBtn1->raise();
        updateActBtn2->raise();
        hidLabel->raise();
        deleteButton->raise();
        createTimeSortBtn->raise();
        prioritySortBtn->raise();
        duetimeSortBtn->raise();
        addItemCalendarWidget->raise();
        isRepeatCheckbox->raise();
        setDueLabel->raise();
        setRemLabel->raise();

        retranslateUi(KTodo);

        QMetaObject::connectSlotsByName(KTodo);
    } // setupUi

    void retranslateUi(QWidget *KTodo)
    {
        KTodo->setWindowTitle(QApplication::translate("KTodo", "KTodo", Q_NULLPTR));
        logo_label->setText(QApplication::translate("KTodo", "\351\207\221\345\261\261\345\276\205\345\212\236", Q_NULLPTR));
        label->setText(QString());
        groupLabel->setText(QApplication::translate("KTodo", "\346\210\221\347\232\204\351\246\226\351\241\265", Q_NULLPTR));
        addTodoItemLineEdit->setText(QString());
        checkBox->setText(QApplication::translate("KTodo", "\347\202\271\345\207\273\346\226\260\345\273\272\345\276\205\345\212\236", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("KTodo", "\346\227\240\344\274\230\345\205\210\347\272\247", Q_NULLPTR)
         << QApplication::translate("KTodo", "\351\253\230", Q_NULLPTR)
         << QApplication::translate("KTodo", "\344\270\255", Q_NULLPTR)
         << QApplication::translate("KTodo", "\344\275\216", Q_NULLPTR)
        );
        addGroupSaveBtn->setText(QApplication::translate("KTodo", "\344\277\235\345\255\230", Q_NULLPTR));
        addGroupLineEdit->setText(QApplication::translate("KTodo", "\350\276\223\345\205\245\345\210\206\347\273\204\345\220\215", Q_NULLPTR));
        addItemBtn->setText(QApplication::translate("KTodo", "\347\241\256\345\256\232", Q_NULLPTR));
        addItemSetDateBtn->setText(QString());
        isRepeatCheckbox->setText(QApplication::translate("KTodo", "\351\207\215\345\244\215", Q_NULLPTR));
        descriLinedit->setText(QApplication::translate("KTodo", "\347\202\271\345\207\273\346\267\273\345\212\240\346\217\217\350\277\260", Q_NULLPTR));
        noteLinedit->setText(QApplication::translate("KTodo", "\347\202\271\345\207\273\346\267\273\345\212\240\345\244\207\346\263\250", Q_NULLPTR));
        locLineedit->setText(QApplication::translate("KTodo", "\347\202\271\345\207\273\346\267\273\345\212\240\345\234\260\347\202\271", Q_NULLPTR));
        setActiLinedit->setText(QApplication::translate("KTodo", "\347\202\271\345\207\273\346\233\264\346\224\271\344\272\213\344\273\266", Q_NULLPTR));
        updateActBtn->setText(QApplication::translate("KTodo", "\346\233\264\346\224\271", Q_NULLPTR));
        updateActBtn1->setText(QApplication::translate("KTodo", "\346\233\264\346\224\271", Q_NULLPTR));
        updateActBtn2->setText(QApplication::translate("KTodo", "\346\233\264\346\224\271", Q_NULLPTR));
        hidLabel->setText(QApplication::translate("KTodo", "\347\202\271\345\207\273\345\267\246\344\276\247\345\276\205\345\212\236\346\237\245\347\234\213\350\257\246\346\203\205", Q_NULLPTR));
        deleteButton->setText(QApplication::translate("KTodo", "\345\210\240\351\231\244\345\276\205\345\212\236", Q_NULLPTR));
        createTimeSortBtn->setText(QApplication::translate("KTodo", "\345\210\233\345\273\272\346\227\266\351\227\264\346\216\222\345\272\217", Q_NULLPTR));
        prioritySortBtn->setText(QApplication::translate("KTodo", "\344\274\230\345\205\210\347\272\247\346\216\222\345\272\217", Q_NULLPTR));
        duetimeSortBtn->setText(QApplication::translate("KTodo", "\345\210\260\346\234\237\346\227\266\351\227\264\346\216\222\345\272\217", Q_NULLPTR));
        setDueLabel->setText(QApplication::translate("KTodo", "\350\256\276\347\275\256\345\210\260\346\234\237", Q_NULLPTR));
        setRemLabel->setText(QApplication::translate("KTodo", "\350\256\276\347\275\256\346\217\220\351\206\222", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class KTodo: public Ui_KTodo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KTODO_H
