#ifndef KTodoItem_H
#define KTodoItem_H

#include <QPushButton>
#include <QCheckBox>
#include <QDate>
#include <QPainter>
#include <QMessageBox>
#include <QDebug>
class KTodoItem : public QPushButton
{
    Q_OBJECT
public:
    //explicit KTodoItem(QWidget *parent = nullptr);
    KTodoItem(QString text,QColor backgroundColor = QColor(255,255,255), int height = 50, QDate date = QDate(0,0,0), bool isRepeat = false,QString group = "",bool check = false);
    ~KTodoItem();
    void setBackgroundColor(QColor backgroundColor);
    void setheight(int height);
    void setDate(QDate date);
    void setText(QString text);
    QColor getBackgroundColor();
    QDate getDate();
    QString getText();
    QString getGroup();
    bool isChecked();
    void setIsRepeat(bool isRepeat);
    void paintEvent(QPaintEvent *event);
    bool getCheck();
    void setCheck(bool check);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
private:
    QString m_text;
    QColor m_backgroundColor;
    int m_height;
    QDate m_date;
    bool m_isRepeat;
    QString m_group;
    bool m_check;
    bool m_isError = false;
signals:
public slots:
};

#endif // KTodoItem_H
