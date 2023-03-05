#include "kmypushbutoon.h"

//MyPushButoon::MyPushButoon(QWidget *parent) : QPushButton(parent)
//{

//}
KMyPushButoon::KMyPushButoon(QString normalImg, QString stayImg, int width ,int height){
    this->m_normalImgPath = normalImg;
    this->m_stayImgPath = stayImg;
    this->m_width = width;
    this->m_height = height;

    QPixmap pix;
    bool ret = pix.load(normalImg);
    if(!ret){
        QMessageBox::warning(this,"error","图片加载失败");
        return;
    }
    pix = pix.scaled(width,height,Qt::KeepAspectRatio);
    this->setFixedSize(pix.width(),pix.height());

    this->setStyleSheet("QPushButton{border:0px;}");

    this->setIcon(pix);

    this->setIconSize(QSize(pix.width(),pix.height()));
}

KMyPushButoon::~KMyPushButoon(){
}

void KMyPushButoon::enterEvent(QEvent *event){
    QPixmap pix;
    bool ret = pix.load(m_stayImgPath);
    if(!ret){
        QMessageBox::warning(this,"error","图片加载失败");
        return;
    }
    pix = pix.scaled(m_width,m_height,Qt::KeepAspectRatio);
    this->setFixedSize(pix.width(),pix.height());

    this->setStyleSheet("QPushButton{border:0px;}");

    this->setIcon(pix);

    this->setIconSize(QSize(pix.width(),pix.height()));
}

void KMyPushButoon::leaveEvent(QEvent *event){
    QPixmap pix;
    bool ret = pix.load(m_normalImgPath);
    if(!ret){
        QMessageBox::warning(this,"error","图片加载失败");
        return;
    }
    pix = pix.scaled(m_width,m_height,Qt::KeepAspectRatio);
    this->setFixedSize(pix.width(),pix.height());

    this->setStyleSheet("QPushButton{border:0px;}");

    this->setIcon(pix);

    this->setIconSize(QSize(pix.width(),pix.height()));
}

