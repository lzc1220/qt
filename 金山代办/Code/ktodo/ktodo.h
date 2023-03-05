#ifndef KTODO_H
#define KTODO_H

#define toStr(x) #x

#include <QWidget>
#include <QDialog>
#include <QList>
#include <QString>
#include <QButtonGroup>
#include <QPushButton>
#include <QLineEdit>
#include <QMenu>
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QPainter>
#include <QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QVBoxLayout>
#include <QScrollArea>
#include "ktodoitem.h"
#include "kmypushbutoon.h"
#include "kprintbutton.h"
namespace Ui {
class KTodo;
}

class KTodo : public QWidget
{
    Q_OBJECT

public:
    explicit KTodo(QWidget *parent = 0);
    ~KTodo();
    void paintEvent(QPaintEvent *event);
    void inforHid();
    void inforShow();
    void lMidClear();
    void lMidInit();
    void AppBtnclicked();
    void talkBtnclicked();
    void addGroupBtnclicked();
    void addGroupSaveBtnclicked();
    void addTodoItemLineEditclicked();
    void addTodoItemLineEditingFinished();
    void addItemSetDateclicked();
    void notAssignBtnclicked();
    void afterDateBtnclicked();
    void sevenDayBtnclicked();
    void futureBtnclicked();
    void finishedBtnclicked();
    void updateBtnclicked();
    void descriLineditFinished();
    void locLineeditFinished();
    void noteLineditFinished();
    void setActiLineditFinished();
    void dueDateFinished();
    void ringDateEditFinished();
    void deleteBtnclicked();
    void p_sortclicked();
    void createTimeSortBtnclicked();
    void duetimeSortBtnclicked();
    void prioritySortBtnclicked();

private:
    Ui::KTodo *ui;
    QSqlDatabase m_db;
    QVBoxLayout * p_lLeft;
    QVBoxLayout * p_lMid;
    QButtonGroup * p_GLeft;
    QButtonGroup * p_GMid;
    KMyPushButoon * p_appBtn;
    KMyPushButoon * p_talkBtn;

    KPrintButton * p_myPageBtn;
    KPrintButton * p_myTodoBtn;
    KPrintButton * p_myAssignBtn;

    KPrintButton * p_update;
    KPrintButton * p_sort;

    KPrintButton * p_myAddGroupBtn;

    KPrintButton * p_notAssign;
    KPrintButton * p_afterDate;
    KPrintButton * p_sevenDay;
    KPrintButton * p_future;

    QSpacerItem * p_leftVerspacer;
    QSpacerItem * p_midVerspacer;
    KPrintButton * p_finishedBtn;
    QList <KTodoItem *> todoItemList;
    QList <KTodoItem *> nothideItemList;
    QList <KTodoItem *> hideItemList;
    int m_GLeftNum = 3;
    int m_GMidNum = 0;
    QWidget * p_w1;
    QWidget * p_w2;

public slots:
    void p_GLeftBtnclicked(int index);
    void p_GMidBtnclicked(int index);
    void comboBoxIndexChanged(int index);
    void checkBoxstateChanged(bool state);
};

#endif // KTODO_H
