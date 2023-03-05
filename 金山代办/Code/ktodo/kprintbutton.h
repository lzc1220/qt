#ifndef KPRINTBUTTON_H
#define KPRINTBUTTON_H

#include <QPushButton>
#include <QPainter>
#include <QMessageBox>
class KPrintButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit KPrintButton(QWidget* parent());
    KPrintButton(QSize size, QString path, QRect rect, QString text,QColor background, QColor textcol, QString path2 = "");
    void setText(QString);
    QString getText();
    void setPath(QString);
    void setMyStyle(QColor background, QColor textcol);
    void changePath();
    QString getPath();
    QColor getBackground();
    void paintEvent(QPaintEvent *);
    void setTodoItemNum(QString oper,int data);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    ~KPrintButton();
private:
    QString m_path;
    QString m_path2;
    QRect m_rect;
    QSize m_size;
    QString m_text;
    QColor m_background;
    QColor m_textcol;
    int todoItemNum = 0;
    bool m_isError = false;
signals:
public slots:
};

#endif // KPRINTBUTTON_H
