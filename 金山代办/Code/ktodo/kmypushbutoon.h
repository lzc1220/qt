#ifndef KMYPUSHBUTOON_H
#define KMYPUSHBUTOON_H

#include <QPushButton>
#include <QMessageBox>

class KMyPushButoon : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyPushButoon(QWidget *parent = nullptr);
    KMyPushButoon(QString normalImg,QString stayImg, int width, int height);
    ~KMyPushButoon();
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    QString m_normalImgPath;
    QString m_stayImgPath;
    int m_width;
    int m_height;
signals:

public slots:
};

#endif // KMYPUSHBUTOON_H
