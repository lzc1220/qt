#include "kprintbutton.h"

//KPrintButton::KPrintButton(QWidget* parent()) : QPushButton(parent)
//{

//}
KPrintButton::KPrintButton(QSize size,QString path,QRect rect,QString text,QColor background,QColor textcol,QString path2){
    this->m_path = path;
    this->m_path2 = path2;
    this->m_text = text;
    this->m_rect = rect;
    this->m_size = size;
    this->m_background = background;
    this->m_textcol = textcol;
    this->setFixedSize(size);
}

KPrintButton::~KPrintButton(){
}

void KPrintButton::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QBrush brush(m_background);
    painter.setBrush(brush);
    QPen pen(m_background);
    painter.setPen(pen);
    painter.drawRect(0,0,m_size.width()-5,m_size.height()-5);
    pen.setColor(m_textcol);
    painter.setPen(pen);
    if(todoItemNum != 0){
        painter.drawText(QRect(40,20,160,60),m_text+"("+(QString)todoItemNum+")");
    }
    else{
        painter.drawText(QRect(40,20,160,60),m_text);
    }
    QPixmap pix;
    bool ret = pix.load(m_path);
    if(!ret && !m_isError){
        QMessageBox::warning(this,"error","图片加载失败");
        m_isError = true;
        return;
    }
    pix = pix.scaled(m_rect.width(),m_rect.height(),Qt::KeepAspectRatio);

    //this->setStyleSheet("QPushButton{border:0px;}");
    //painter.drawPixmap(m_rect.x(),m_rect.y(),pix);
    painter.drawPixmap(m_rect.x()-20,m_rect.y(),pix);
}

void KPrintButton::setText(QString text){
    this->m_text = text;
}
QString KPrintButton::getText(){
    return m_text;
}
void KPrintButton::setPath(QString path){
    this->m_path = path;
}
void KPrintButton::setMyStyle(QColor background, QColor textcol){
    this->m_background = background;
    this->m_textcol = textcol;
}
void KPrintButton::changePath(){
    if(m_path2 != ""){
        m_path.swap(m_path2);
    }
    this->update();
}

void KPrintButton::setTodoItemNum(QString oper,int data){
    if(oper == "+"){
        todoItemNum += data;
    }
    else{
        todoItemNum -= data;
    }
}

QString KPrintButton::getPath(){
    return m_path;
}
QColor KPrintButton::getBackground(){
    return m_background;
}
void KPrintButton::enterEvent(QEvent *event){
    if(m_background == QColor(255,255,255)){
      m_background = QColor(230,230,230);
    }
}
void KPrintButton::leaveEvent(QEvent *event){
    if(m_background == QColor(230,230,230)){
      m_background = QColor(255,255,255);
    }
}
