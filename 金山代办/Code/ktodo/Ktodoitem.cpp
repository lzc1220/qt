#include "KTodoItem.h"

//KTodoItem::KTodoItem(QWidget *parent) : QWidget(parent)
//{

//}
KTodoItem::KTodoItem(QString text,QColor backgroundColor, int height , QDate date , bool isRepeat,QString group,bool check){
    this->m_text = text;
    this->m_backgroundColor = backgroundColor;
    this->m_height = height;
    this->m_date = date;
    this->m_isRepeat = isRepeat;
    this->setFixedSize(790,80);
    this->m_group = group;
    this->m_check = check;
}

KTodoItem::~KTodoItem(){
}

void KTodoItem::enterEvent(QEvent *event){
    if(m_backgroundColor == QColor(255,255,255)){
      m_backgroundColor = QColor(230,230,230);
    }
}

void KTodoItem::leaveEvent(QEvent *event){
    if(m_backgroundColor == QColor(230,230,230)){
      m_backgroundColor = QColor(255,255,255);
    }
}

void KTodoItem::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QBrush brush(m_backgroundColor);
    painter.setBrush(brush);
    QPen pen(m_backgroundColor);
    painter.setPen(pen);
    painter.drawRect(0,0,this->width(),80);
    pen.setColor(QColor(0,0,0));
    painter.setPen(pen);
    painter.drawText(QRect(42,15,500,60),m_text);
    painter.drawEllipse(QRect(10,13,20,20));
    if(m_check == 1){
    painter.drawLine(10,33,30,10);
    }
    if(m_date != QDate(0,0,0)){
        if(m_date < QDate::currentDate()){
        pen.setColor(QColor(150,0,0));
        }
        else pen.setColor(QColor(150,150,150));
        painter.setPen(pen);
        painter.drawText(QRect(42,50,180,60),m_date.toString());
        painter.drawLine(210,49,210,69);
    QPixmap pix;
    bool ret = pix.load(":/res/repeat");
    if(!ret && !m_isError){
        QMessageBox::warning(this,"error","图片加载失败");
        m_isError = true;
        return;
    }
    pix = pix.scaled(25,25,Qt::KeepAspectRatio);

    //this->setStyleSheet("QPushButton{border:0px;}");
    painter.drawPixmap(230,45,pix);
    if(m_isRepeat == true){
         painter.drawText(QRect(270,50,150,60),"重复");
    }
    else{
         painter.drawText(QRect(270,50,150,60),"不重复");
    }
    }
    if(m_check == true){
    pen.setColor(QColor(100,100,100));
    painter.setPen(pen);
        painter.drawLine(0,this->height(),this->width(),0);
        this->update();
    }
}

void KTodoItem::setBackgroundColor(QColor backgroundColor){
    this->m_backgroundColor = backgroundColor;
}

void KTodoItem::setheight(int height){
    this->m_height =height;
}

void KTodoItem::setDate(QDate date){
    this->m_date = date;
}

QDate KTodoItem::getDate(){
    return m_date;
}

void KTodoItem::setIsRepeat(bool isRepeat){
    this->m_isRepeat = isRepeat;
}

QString KTodoItem::getText(){
    return m_text;
}

QString KTodoItem::getGroup(){
    return m_group;
}

bool KTodoItem::isChecked(){
    return m_check;
}

QColor KTodoItem::getBackgroundColor(){
    return m_backgroundColor;
}

void KTodoItem::setText(QString text){
    m_text = text;
}

bool KTodoItem::getCheck(){
    return m_check;
}
void KTodoItem::setCheck(bool check){
    m_check = check;
}
