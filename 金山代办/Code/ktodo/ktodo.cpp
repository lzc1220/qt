#include "ktodo.h"
#include "ui_ktodo.h"
KTodo::KTodo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KTodo)
{
    //ui界面
    ui->setupUi(this);
    //初始化数据库
    m_db = QSqlDatabase::addDatabase("QSQLITE");//添加驱动
    m_db.setDatabaseName("todogroup.db");

    bool ok = m_db.open();
    if(ok){

    }
    else{
        qDebug()<<m_db.lastError().text();
        exit(-1);
    }

    QSqlQuery query;
    query.exec("create table todogroup(id INTEGER PRIMARY KEY AUTOINCREMENT,name TEXT unique NOT NULL)");
    query.exec("create table todoitem(id INTEGER PRIMARY KEY AUTOINCREMENT,activity TEXT unique,todogroupname TEXT NULL,isrepeat INTEGER NULL,status INTEGER"
               " NOT NULL,priority INTEGER default '2',createtime date NOT NULL,duetime date NULL,remtime date NULL"
               " NULL,description TEXT NULL,location TEXT NULL,note TEXT NULL)");
      query.exec();
    query.prepare("insert into todogroup(id, name) "
                  "VALUES (:id, :name)");
        query.bindValue(":name","我的待办");
      query.exec();
    query.prepare("insert into todogroup(id, name) "
                  "VALUES (:id, :name)");
        query.bindValue(":name","分配给我的");

        query.exec();

    //初始化界面
    p_appBtn = new KMyPushButoon(":/res/app_hui",":/res/app_green",90,90);
    p_appBtn->setParent(this);
    p_appBtn->move(this->width() - 400,55);

    p_finishedBtn = new KPrintButton(QSize(300,60),":/res/shang",QRect(20,15,40,40),"显示已完成（未实现）",QColor(255,255,255),QColor(0,0,0),":/res/xia");

    p_talkBtn = new KMyPushButoon(":/res/talk_hui",":/res/talk_green",90,90);
    p_talkBtn->setParent(this);
    p_talkBtn->move(this->width() - 300,55);

    p_update = new KPrintButton(QSize(110,60),":/res/gengxin",QRect(7,7,80,80),"更新",QColor(255,255,255),QColor(0,0,0));
    p_sort = new KPrintButton(QSize(110,60),":/res/paixu",QRect(7,7,80,80),"排序",QColor(255,255,255),QColor(0,0,0));
    p_update->setParent(this);
    p_update->move(1040,180);
    p_sort->setParent(this);
    p_sort->move(1165,180);

    p_myPageBtn = new KPrintButton(QSize(300,60),":/res/shouye_green",QRect(7,7,80,80),"我的首页",QColor(210,210,210),QColor(0,180,0),":/res/shouye");
    p_myTodoBtn = new KPrintButton(QSize(300,60),":/res/daiban",QRect(7,7,80,80),"我的待办",QColor(255,255,255),QColor(0,0,0),":/res/daiban_green");
    p_myAssignBtn = new KPrintButton(QSize(300,60),":/res/fenpei",QRect(7,7,80,80),"分配给我的",QColor(255,255,255),QColor(0,0,0),":/res/fenpei_green");
    p_myAddGroupBtn = new KPrintButton(QSize(300,60),":/res/xinjiangroup.png",QRect(7,7,80,80),"添加分组",QColor(255,255,255),QColor(0,0,0));
    p_GLeft = new QButtonGroup;
    p_GMid = new QButtonGroup;
    p_GLeft->addButton(p_myPageBtn,0);
    p_GLeft->addButton(p_myTodoBtn,1);
    p_GLeft->addButton(p_myAssignBtn,2);
    m_GLeftNum = 3;

    p_w1 = new QWidget;
    p_lLeft = new QVBoxLayout;
    p_lLeft->addWidget(p_myPageBtn);
    p_lLeft->addWidget(p_myTodoBtn);
    p_lLeft->addWidget(p_myAssignBtn);
    p_leftVerspacer =new QSpacerItem(160,100,QSizePolicy::Expanding,QSizePolicy::Expanding);
    p_lLeft->insertSpacerItem(3,p_leftVerspacer);
    p_lLeft->insertWidget(4,p_myAddGroupBtn);
    p_lLeft->setSpacing(5);
    p_w1->setLayout(p_lLeft);
    ui->groupScrollArea->setWidget(p_w1);
    query.exec("select * from todogroup");
    while(query.next()){
        if(query.value(1)!="我的待办" && query.value(1)!="分配给我的"){
        KPrintButton * item = new KPrintButton(QSize(300,60),":/res/mygroup",QRect(7,7,80,80),query.value(1).toString(),QColor(255,255,255),QColor(0,0,0),":/res/mygroup_green");
        p_GLeft->addButton(item,m_GLeftNum++);
        p_lLeft->insertWidget(p_lLeft->count()-2,item);
        }
    }
    query.exec();
    p_w2 = new QWidget;
    p_lMid = new QVBoxLayout;


    p_notAssign = new KPrintButton(QSize(300,60),":/res/shang",QRect(20,15,40,40),"未安排",QColor(255,255,255),QColor(0,0,0),":/res/xia");
    p_afterDate = new KPrintButton(QSize(300,60),":/res/shang",QRect(20,15,40,40),"已逾期",QColor(255,255,255),QColor(0,0,0),":/res/xia");
    p_sevenDay = new KPrintButton(QSize(300,60),":/res/shang",QRect(20,15,40,40),"未来七天",QColor(255,255,255),QColor(0,0,0),":/res/xia");
    p_future = new KPrintButton(QSize(300,60),":/res/shang",QRect(20,15,40,40),"以后",QColor(255,255,255),QColor(0,0,0),":/res/xia");
    lMidInit();

    p_finishedBtn = new KPrintButton(QSize(300,60),":/res/shang",QRect(20,15,40,40),"显示已完成",QColor(255,255,255),QColor(0,0,0),":/res/xia");
//    KTodoItem * Itemtest1 = new KTodoItem("吃饭",QColor(255,255,255));
//    KTodoItem * Itemtest2 = new KTodoItem("睡觉",QColor(255,255,255),80,QDate(2022,10,5),true);
//    p_lMid->addWidget(Itemtest1);
    p_midVerspacer =new QSpacerItem(160,100,QSizePolicy::Expanding,QSizePolicy::Expanding);
    p_lMid->insertSpacerItem(4,p_midVerspacer);
    p_lMid->setSpacing(5);
    p_w2->setLayout(p_lMid);
    ui->itemScrollArea->setWidget(p_w2);

    ui->duetimeSortBtn->hide();
    ui->createTimeSortBtn->hide();
    ui->prioritySortBtn->hide();
    p_sort->hide();
    ui->addGroupLineEdit->hide();
    ui->addGroupSaveBtn->hide();
    ui->addItemCalendarWidget->hide();
    ui->addTodoItemLineEdit->setText("  +  点击新建待办");
    ui->addTodoItemLineEdit->setStyleSheet(toStr(font-family:"Arial"; font-size: 12; color: rgb(0,200,0)));
    ui->isRepeatCheckbox->hide();
    inforHid();
    //todoitem的初始化
    query.exec("select * from todoitem");
    while(query.next()){
        if(!query.value(7).isNull()){
            KTodoItem * item = new KTodoItem(query.value(1).toString(),QColor(255,255,255),80,QDate::fromString(query.value(7).toString()),query.value(3).toBool(),query.value(2).toString(),!query.value(4).toBool());
            todoItemList.append(item);
            p_GMid->addButton(item,m_GMidNum++);
        }
        else {
            KTodoItem * item = new KTodoItem(query.value(1).toString(),QColor(255,255,255),80,QDate(0,0,0),query.value(3).toBool(),query.value(2).toString(),!query.value(4).toBool());
            todoItemList.append(item);
            p_GMid->addButton(item,m_GMidNum++);
        }
    }
    //信号和槽函数的连接
    connect(p_appBtn,&KMyPushButoon::clicked,this,&KTodo::AppBtnclicked);
    connect(p_talkBtn,&KMyPushButoon::clicked,this,&KTodo::talkBtnclicked);
    connect(p_myAddGroupBtn,&KPrintButton::clicked,this,&KTodo::addGroupBtnclicked);
    connect(ui->addGroupSaveBtn,&QPushButton::clicked,this,&KTodo::addGroupSaveBtnclicked);
    connect(p_GLeft,SIGNAL(buttonClicked(int)),this,SLOT(p_GLeftBtnclicked(int)));
    connect(p_GMid,SIGNAL(buttonClicked(int)),this,SLOT(p_GMidBtnclicked(int)));
    connect(ui->addTodoItemLineEdit,&QLineEdit::textChanged,this,&KTodo::addTodoItemLineEditclicked);
    connect(ui->addItemBtn,&QPushButton::clicked,this,&KTodo::addTodoItemLineEditingFinished);
    connect(ui->addItemSetDateBtn,&QPushButton::clicked,this,&KTodo::addItemSetDateclicked);
    connect(p_finishedBtn,&KPrintButton::clicked,this,&KTodo::finishedBtnclicked);
    connect(p_notAssign,&KPrintButton::clicked,this,&KTodo::notAssignBtnclicked);
    connect(p_afterDate,&KPrintButton::clicked,this,&KTodo::afterDateBtnclicked);
    connect(p_sevenDay,&KPrintButton::clicked,this,&KTodo::sevenDayBtnclicked);
    connect(p_future,&KPrintButton::clicked,this,&KTodo::futureBtnclicked);
    connect(p_update,&KPrintButton::clicked,this,&KTodo::updateBtnclicked);
    connect(ui->descriLinedit,&QLineEdit::editingFinished,this,&KTodo::descriLineditFinished);
    connect(ui->locLineedit,&QLineEdit::editingFinished,this,&KTodo::locLineeditFinished);
    connect(ui->noteLinedit,&QLineEdit::editingFinished,this,&KTodo::noteLineditFinished);
    connect(ui->updateActBtn,&QPushButton::clicked,this,&KTodo::setActiLineditFinished);
    connect(ui->updateActBtn1,&QPushButton::clicked,this,&KTodo::dueDateFinished);
    connect(ui->updateActBtn2,&QPushButton::clicked,this,&KTodo::ringDateEditFinished);
    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(comboBoxIndexChanged(int)));
    connect(ui->checkBox,SIGNAL(clicked(bool)),this,SLOT(checkBoxstateChanged(bool)));
    connect(ui->deleteButton,&QPushButton::clicked,this,&KTodo::deleteBtnclicked);
    connect(p_sort,KPrintButton::clicked,this,&KTodo::p_sortclicked);
    connect(ui->duetimeSortBtn,QPushButton::clicked,this,&KTodo::duetimeSortBtnclicked);
    connect(ui->createTimeSortBtn,QPushButton::clicked,this,&KTodo::createTimeSortBtnclicked);
    connect(ui->prioritySortBtn,QPushButton::clicked,this,&KTodo::prioritySortBtnclicked);
}

KTodo::~KTodo()
{
    delete ui;
    m_db.close();
    delete p_lLeft;
    delete p_lMid;
    delete p_GLeft;
    delete p_GMid;
    delete p_appBtn;
    delete p_talkBtn;

    delete p_myPageBtn;
    delete p_myTodoBtn;
    delete p_myAssignBtn;

    delete p_update;
    delete p_sort;

    delete p_myAddGroupBtn;

    delete p_notAssign;
    delete p_afterDate;
    delete p_sevenDay;
    delete p_future;

    delete p_leftVerspacer;
    delete p_midVerspacer;
    delete p_finishedBtn;
    for(KTodoItem * item : todoItemList){
        delete item;
    }
    todoItemList.clear();
    for(KTodoItem * item : nothideItemList){
        delete item;
    }
    nothideItemList.clear();
    for(KTodoItem * item : hideItemList){
        delete item;
    }
    hideItemList.clear();
    delete p_w1;
    delete p_w2;
}

void KTodo::AppBtnclicked(){
    QMessageBox::information(this,"information","未实现");
}

void KTodo::inforHid(){
    ui->hidLabel->show();
    ui->checkBox->hide();
    ui->updateActBtn->hide();
    ui->comboBox->hide();
    ui->dueDateEdit->hide();
    ui->updateActBtn1->hide();
    ui->ringDateEdit->hide();
    ui->updateActBtn2->hide();
    ui->descriLinedit->hide();
    ui->locLineedit->hide();
    ui->noteLinedit->hide();
    ui->setActiLinedit->hide();
    ui->deleteButton->hide();
    ui->setRemLabel->hide();
    ui->setDueLabel->hide();
}

void KTodo::inforShow(){
    ui->hidLabel->hide();
    ui->checkBox->show();
    ui->updateActBtn->show();
    ui->comboBox->show();
    ui->dueDateEdit->show();
    ui->updateActBtn1->show();
    ui->ringDateEdit->show();
    ui->updateActBtn2->show();
    ui->descriLinedit->show();
    ui->locLineedit->show();
    ui->noteLinedit->show();
    ui->setActiLinedit->show();
    ui->deleteButton->show();
    ui->setRemLabel->show();
    ui->setDueLabel->show();
}

void KTodo::talkBtnclicked(){
    QMessageBox::information(this,"information","未实现");
}

void KTodo::addGroupBtnclicked(){
    if(ui->addGroupLineEdit->isHidden()){
        ui->addGroupLineEdit->show();
    }
    else ui->addGroupLineEdit->hide();
    if(ui->addGroupSaveBtn->isHidden()){
        ui->addGroupSaveBtn->show();
    }
    else ui->addGroupSaveBtn->hide();
    p_myAddGroupBtn->setMyStyle(QColor(255,255,255),QColor(0,180,0));
    p_myAddGroupBtn->update();

}

void KTodo::addGroupSaveBtnclicked(){
    //数据库操作
    QSqlQuery query;
    query.prepare("insert into todogroup(id, name) "
                  "VALUES (:id, :name)");
        query.bindValue(":name",ui->addGroupLineEdit->text());
        query.exec();
     //界面操作
     ui->addGroupLineEdit->hide();
     ui->addGroupSaveBtn->hide();
     KPrintButton * pBtn = new KPrintButton(QSize(300,60),":/res/mygroup",QRect(7,7,80,80),ui->addGroupLineEdit->text(),QColor(255,255,255),QColor(0,0,0),":/res/mygroup_green");
     p_GLeft->addButton(pBtn,m_GLeftNum++);
     p_lLeft->insertWidget(p_lLeft->count()-2,pBtn);
     p_GLeftBtnclicked(p_GLeft->id(pBtn));
}

void KTodo::p_GMidBtnclicked(int index){
    if(!ui->hidLabel->isHidden()){
        inforShow();
    }
    KTodoItem * btn = dynamic_cast<KTodoItem *>(this->p_GMid->button(index));
    QSqlQuery qy("select * from todoitem");
    while(qy.next()){
        if(qy.value(1) == btn->getText()){
            ui->checkBox->setText(qy.value(1).toString());
            ui->checkBox->setChecked(!qy.value(4).toBool());
            ui->comboBox->setCurrentIndex(qy.value(5).toInt());
            ui->dueDateEdit->setDate(QDate::fromString(qy.value(7).toString()));
            ui->ringDateEdit->setDate(QDate::fromString(qy.value(8).toString()));
            if(qy.value(9).toString() != ""){
                 ui->descriLinedit->setText(qy.value(9).toString());
            }
            else ui->descriLinedit->setText("点击添加待办");
            if(qy.value(10).toString() != ""){
                 ui->locLineedit->setText(qy.value(10).toString());
            }
            else ui->locLineedit->setText("点击添加地点");
            if(qy.value(11).toString() != ""){
                 ui->noteLinedit->setText(qy.value(11).toString());
            }
            else ui->noteLinedit->setText("点击添加备注");
        }
    }

    for(KTodoItem * item : todoItemList){
        if(item == btn){
            if(item->getBackgroundColor() != QColor(210,210,210)){
                item->setBackgroundColor(QColor(210,210,210));
                item->update();
            }
        }
        else{
            if(item->getBackgroundColor() == QColor(210,210,210)){
                item->setBackgroundColor(QColor(255,255,255));
                item->update();
            }
        }
    }
}


void KTodo::p_GLeftBtnclicked(int index){
    inforHid();
    for(int i = 0;i < m_GLeftNum;i++){
        KPrintButton * curBtn = dynamic_cast<KPrintButton *>(this->p_GLeft->button(i));
        if(i == index){
            if(curBtn->getBackground() != QColor(210,210,210)){
                curBtn->setMyStyle(QColor(210,210,210),QColor(0,180,0));
                curBtn->changePath();
                curBtn->update();
            }
        }
        else{
            if(curBtn->getBackground() == QColor(210,210,210)){
                curBtn->setMyStyle(QColor(255,255,255),QColor(0,0,0));
                curBtn->changePath();
                curBtn->update();
            }
        }
    }

    ui->groupLabel->setText(dynamic_cast<KPrintButton *>(this->p_GLeft->button(index))->getText());

    if(dynamic_cast<KPrintButton *>(this->p_GLeft->button(index))->getText()!="我的首页"){
        p_sort->show();
        if(p_finishedBtn->getPath() == ":/res/xia"){
            p_finishedBtn->changePath();
        }
        this->lMidClear();
        p_lMid->insertWidget(0,p_finishedBtn);
        for(KTodoItem * allitem : todoItemList){
            //qDebug()<<dynamic_cast<KPrintButton *>(this->p_GLeft->button(index))->getText();
            if(allitem->getGroup() == dynamic_cast<KPrintButton *>(this->p_GLeft->button(index))->getText())
                {
                    if(allitem->isChecked() == 1){
                        hideItemList.append(allitem);
                    }
                    else{
                        nothideItemList.append(allitem);
                        p_lMid->insertWidget(0,allitem);
                    }
                }
        }
    }
    else{
        p_sort->hide();
        if(p_notAssign->getPath() == ":/res/xia"){
            p_notAssign->changePath();
        }
        if(p_sevenDay->getPath() == ":/res/xia"){
            p_sevenDay->changePath();
        }
        if(p_future->getPath() == ":/res/xia"){
            p_future->changePath();
        }
        if(p_afterDate->getPath() == ":/res/xia"){
            p_afterDate->changePath();
        }
        this->lMidClear();
        this->lMidInit();
    }
}

void KTodo::addTodoItemLineEditclicked(){
    ui->addTodoItemLineEdit->setStyleSheet(toStr(font-family:"Arial"; font-size: 12; color: rgb(0,0,0)));
    ui->addTodoItemLineEdit->update();
}

void KTodo::addTodoItemLineEditingFinished(){
    for(KTodoItem * item : todoItemList){
        if(item->getText() == ui->addTodoItemLineEdit->text()){
            ui->addTodoItemLineEdit->setText("  +  点击新建待办");
            ui->addTodoItemLineEdit->setStyleSheet(toStr(font-family:"Arial"; font-size: 12; color: rgb(0,200,0)));
            ui->addTodoItemLineEdit->show();
            ui->isRepeatCheckbox->hide();
            ui->addItemCalendarWidget->hide();
            QMessageBox::warning(this,"warning","不允许创建两个相同的事件");
            return;
        }
    }
    if(!ui->addItemCalendarWidget->isHidden()){
        QSqlQuery query;
        query.prepare("insert INTO todoitem(id,activity,todogroupname,isrepeat,status,priority,createtime,duetime,remtime,description,location,note) "
                      "VALUES (:id,:activity, :todogroupname,:isrepeat,:status,:priority,:createtime,:duetime,:remtime,:description,:location,:note)");
            query.bindValue(":activity",ui->addTodoItemLineEdit->text());
            if(ui->groupLabel->text() == "我的首页"){
                 query.bindValue(":todogroupname","我的待办");
            }
            else{
                  query.bindValue(":todogroupname",ui->groupLabel->text());
            }
            query.bindValue(":status",1);
            query.bindValue(":isrepeat",(int)ui->isRepeatCheckbox->isChecked());
            query.bindValue(":createtime",QDate::currentDate());
            query.bindValue(":duetime",ui->addItemCalendarWidget->selectedDate());
            query.exec();
        ui->addItemCalendarWidget->hide();
        ui->isRepeatCheckbox->hide();
        if(ui->groupLabel->text() != "我的首页"){
            KTodoItem * item = new KTodoItem(ui->addTodoItemLineEdit->text(),QColor(255,255,255),80,ui->addItemCalendarWidget->selectedDate(),ui->isRepeatCheckbox->isChecked(),ui->groupLabel->text());
            todoItemList.append(item);
            p_GMid->addButton(item,m_GMidNum++);
            p_lMid->insertWidget(0,item);
            nothideItemList.append(item);
            p_GMidBtnclicked(p_GMid->id(item));
           }
        else{
            KTodoItem * item = new KTodoItem(ui->addTodoItemLineEdit->text(),QColor(255,255,255),80,ui->addItemCalendarWidget->selectedDate(),ui->isRepeatCheckbox->isChecked(),"我的待办");
            todoItemList.append(item);
            p_GMid->addButton(item,m_GMidNum++);
            for(KTodoItem * curitem : nothideItemList){
                if(p_future->getPath() == ":/res/xia" && item->getDate() >= QDate::currentDate().addDays(7))
                {
                    p_lMid->insertWidget(p_lMid->indexOf(p_future)+1,item);
                    nothideItemList.append(curitem);
                }
                if(p_afterDate->getPath() == ":/res/xia" && item->getDate() < QDate::currentDate())
                {
                    p_lMid->insertWidget(p_lMid->indexOf(p_afterDate)+1,item);
                    nothideItemList.append(curitem);
                }
                if(p_sevenDay->getPath() == ":/res/xia" && item->getDate() >= QDate::currentDate() && item->getDate() < QDate::currentDate().addDays(7)){
                    p_lMid->insertWidget(p_lMid->indexOf(p_sevenDay)+1,item);
                    nothideItemList.append(curitem);
                }
            }
             p_GMidBtnclicked(p_GMid->id(item));
        }
    }
    else{
        QSqlQuery query;
        query.prepare("insert INTO todoitem(id,activity,todogroupname,isrepeat,status,priority,createtime,duetime,remtime,description,location,note) "
                      "VALUES (:id,:activity, :todogroupname,:isrepeat,:status,:priority,:createtime,:duetime,:remtime,:description,:location,:note)");
            query.bindValue(":activity",ui->addTodoItemLineEdit->text());
            if(ui->groupLabel->text() == "我的首页"){
                 query.bindValue(":todogroupname","我的待办");
            }
            else{
                  query.bindValue(":todogroupname",ui->groupLabel->text());
            }
            query.bindValue(":status",1);
            query.bindValue(":createtime",QDate::currentDate());
            query.exec();
        if(ui->groupLabel->text() != "我的首页"){
        KTodoItem * item = new KTodoItem(ui->addTodoItemLineEdit->text(),QColor(255,255,255),50,QDate(0,0,0),false,ui->groupLabel->text());
        todoItemList.append(item);
        p_GMid->addButton(item,m_GMidNum++);
        p_lMid->insertWidget(0,item);
        nothideItemList.append(item);
        p_GMidBtnclicked(p_GMid->id(item));
        }
        else{
            KTodoItem * item = new KTodoItem(ui->addTodoItemLineEdit->text(),QColor(255,255,255),50,QDate(0,0,0),false,"我的待办");
            todoItemList.append(item);
            p_GMid->addButton(item,m_GMidNum++);
            for(KTodoItem * curitem : nothideItemList){
                if(p_notAssign->getPath() == ":/res/xia" && curitem->getDate() == QDate(0,0,0)){
                p_lMid->insertWidget(p_lMid->indexOf(p_notAssign)+1,item);
                nothideItemList.append(curitem);
                }
            }
            p_GMidBtnclicked(p_GMid->id(item));
        }
    }


    ui->addTodoItemLineEdit->setText("  +  点击新建待办");
    ui->addTodoItemLineEdit->setStyleSheet(toStr(font-family:"Arial"; font-size: 12; color: rgb(0,200,0)));
    ui->addTodoItemLineEdit->show();
}

void KTodo::addItemSetDateclicked(){
    if(ui->addItemCalendarWidget->isHidden()){
        ui->isRepeatCheckbox->show();
        ui->addItemCalendarWidget->show();
    }
    else{
        ui->addItemCalendarWidget->hide();
        ui->isRepeatCheckbox->hide();
    }
}

void KTodo::lMidClear(){
    p_notAssign->setParent(NULL);
    p_lLeft->removeWidget(p_notAssign);
    p_afterDate->setParent(NULL);
    p_lLeft->removeWidget(p_afterDate);
    p_sevenDay->setParent(NULL);
    p_lLeft->removeWidget(p_sevenDay);
    p_future->setParent(NULL);
    p_lLeft->removeWidget(p_future);
    p_finishedBtn->setParent(NULL);
    p_lLeft->removeWidget(p_finishedBtn);
    for(KTodoItem* item:nothideItemList){
        item->setParent(NULL);
        p_lLeft->removeWidget(item);
    }
    nothideItemList.clear();
    for(KTodoItem* item:hideItemList){
        item->setParent(NULL);
        p_lLeft->removeWidget(item);
    }
    hideItemList.clear();
}

void KTodo::lMidInit(){
    p_lMid->insertWidget(0,p_future);
    p_lMid->insertWidget(0,p_sevenDay);
    p_lMid->insertWidget(0,p_afterDate);
    p_lMid->insertWidget(0,p_notAssign);
}

void KTodo::notAssignBtnclicked(){
    if(p_notAssign->getPath() == ":/res/shang"){
        p_notAssign->changePath();
//    if(p_future->getPath() != ":/res/shang") p_future->changePath();
//    if(p_sevenDay->getPath() != ":/res/shang") p_sevenDay->changePath();
//    if(p_afterDate->getPath() != ":/res/shang") p_afterDate->changePath();
        for(KTodoItem * curitem : todoItemList){
            if(!curitem->getCheck() &&curitem->getDate() == QDate(0,0,0)){
            p_lMid->insertWidget(p_lMid->indexOf(p_notAssign)+1,curitem);
            nothideItemList.append(curitem);
            }
        }
        }
    else {
        p_notAssign->changePath();
        for(KTodoItem * curitem : nothideItemList){
            if(!curitem->getCheck() &&curitem->getDate() == QDate(0,0,0)){
            p_lMid->removeWidget(curitem);
            curitem->setParent(NULL);
            nothideItemList.removeOne(curitem);
            }
        }
    }
}

void KTodo::afterDateBtnclicked(){
    if(p_afterDate->getPath() == ":/res/shang"){
        p_afterDate->changePath();
        for(KTodoItem * curitem : todoItemList){
            if(!curitem->getCheck() &&curitem->getDate() != QDate(0,0,0) && curitem->getDate() < QDate::currentDate()){
            p_lMid->insertWidget(p_lMid->indexOf(p_afterDate)+1,curitem);
            nothideItemList.append(curitem);
            }
        }
        }
    else {
        p_afterDate->changePath();
        for(KTodoItem * curitem : nothideItemList){
            if(!curitem->getCheck() &&curitem->getDate() != QDate(0,0,0) && curitem->getDate() < QDate::currentDate()){
            p_lMid->removeWidget(curitem);
            curitem->setParent(NULL);
            nothideItemList.removeOne(curitem);
            }
        }
    }
}

void KTodo::sevenDayBtnclicked(){
    if(p_sevenDay->getPath() == ":/res/shang"){
        p_sevenDay->changePath();
        for(KTodoItem * curitem : todoItemList){
            if(!curitem->getCheck() &&curitem->getDate() != QDate(0,0,0) && curitem->getDate() < QDate::currentDate().addDays(7) && curitem->getDate() >= QDate::currentDate()){
            p_lMid->insertWidget(p_lMid->indexOf(p_sevenDay)+1,curitem);
            nothideItemList.append(curitem);
            }
        }
        }
    else {
        p_sevenDay->changePath();
        for(KTodoItem * curitem : nothideItemList){
            if(!curitem->getCheck() &&curitem->getDate() != QDate(0,0,0) && curitem->getDate() < QDate::currentDate().addDays(7) && curitem->getDate() >= QDate::currentDate()){
            p_lMid->removeWidget(curitem);
            curitem->setParent(NULL);
            nothideItemList.removeOne(curitem);
            }
        }
    }
}
void KTodo::futureBtnclicked(){
    if(p_future->getPath() == ":/res/shang"){
        p_future->changePath();
        for(KTodoItem * curitem : todoItemList){
            if(!curitem->getCheck() && curitem->getDate() != QDate(0,0,0) && curitem->getDate() >= QDate::currentDate().addDays(7)){
            p_lMid->insertWidget(p_lMid->indexOf(p_future)+1,curitem);
            nothideItemList.append(curitem);
            }
        }
        }
    else {
        p_future->changePath();
        for(KTodoItem * curitem : nothideItemList){
            if(!curitem->getCheck() &&curitem->getDate() != QDate(0,0,0) && curitem->getDate() >= QDate::currentDate().addDays(7)){
            p_lMid->removeWidget(curitem);
            curitem->setParent(NULL);
            nothideItemList.removeOne(curitem);
            }
        }
    }
}

void KTodo::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPen pen;
    pen.setColor(QColor(220,220,220));;
    painter.setPen(pen);
    QBrush brush(QColor(255,255,255));
    painter.setBrush(brush);
    painter.drawRect(0,0,this->width(),this->height());
    painter.drawLine(0,130,2000,130);
    painter.drawLine(440,130,440,1000);
    painter.drawLine(1400,130,1400,1000);
}

void KTodo::KTodo::finishedBtnclicked(){
    if(p_finishedBtn->getPath() == ":/res/shang"){
        p_finishedBtn->changePath();
        for(KTodoItem * curitem : todoItemList){
            if(curitem->getGroup() == ui->groupLabel->text()){
                if(curitem->isChecked() == 1){
                    int i = 1;
                    for(KTodoItem * nothidItem : nothideItemList){
                        if(nothidItem == curitem){
                            p_lMid->insertWidget(p_lMid->indexOf(p_finishedBtn),curitem);
                            hideItemList.append(curitem);
                            nothideItemList.removeOne(curitem);
                            i = 0;
                        }
                    }
                    if(i){
                        p_lMid->insertWidget(p_lMid->indexOf(p_finishedBtn)+1,curitem);
                        hideItemList.append(curitem);
                    }
                }
            }

        }
        }
    else {
        p_finishedBtn->changePath();
        for(KTodoItem * curitem : hideItemList){
            p_lMid->removeWidget(curitem);
            curitem->setParent(NULL);
            hideItemList.removeOne(curitem);
        }
    }
}

void KTodo::updateBtnclicked(){
    this->update();
    QMessageBox::information(this,"information","已完成更新");
}

void KTodo::descriLineditFinished(){
    QSqlQuery qy;
    qy.prepare("update todoitem set description = :description where activity = :activity");
    qy.bindValue(":activity",ui->checkBox->text());
    qy.bindValue(":description",ui->descriLinedit->text());
    qy.exec();
}

void KTodo::locLineeditFinished(){
    QSqlQuery qy;
    qy.prepare("update todoitem set location = :location where activity = :activity");
    qy.bindValue(":activity",ui->checkBox->text());
    qy.bindValue(":location",ui->locLineedit->text());
    qy.exec();
}

void KTodo::noteLineditFinished(){
    QSqlQuery qy;
    qy.prepare("update todoitem set note = :note where activity = :activity");
    qy.bindValue(":activity",ui->checkBox->text());
    qy.bindValue(":note",ui->noteLinedit->text());
    qy.exec();
}

void KTodo::setActiLineditFinished(){
    int id = 0;
    QSqlQuery qy("select * from todoitem");
    while(qy.next()){
        if(qy.value(1) == ui->checkBox->text()){
            id = qy.value(0).toInt();
        }
    }
    qy.prepare("update todoitem set activity = :activity where id = :id");
    qy.bindValue(":activity",ui->setActiLinedit->text());
    qy.bindValue(":id",id);
    qy.exec();

    for(KTodoItem *item : todoItemList){
        if(item->getText() == ui->checkBox->text()){
            item->setText(ui->setActiLinedit->text());
        }
    }

    ui->checkBox->setText(ui->setActiLinedit->text());
    ui->setActiLinedit->setText("点击更改事件");
}

void KTodo::dueDateFinished(){
    QSqlQuery qy;
    qy.prepare("update todoitem set duetime = :duetime where activity = :activity");
    qy.bindValue(":activity",ui->checkBox->text());
    qy.bindValue(":duetime",ui->dueDateEdit->date());
    qy.exec();
    for(KTodoItem *item : nothideItemList){
        if(ui->groupLabel->text() == "我的首页" && item->getDate() == QDate(0,0,0) && item->getText() == ui->checkBox->text()){
            p_lMid->removeWidget(item);
            item->setParent(NULL);
            nothideItemList.removeOne(item);
        }
    }
    for(KTodoItem *item : todoItemList){
        if(item->getText() == ui->checkBox->text()){
            item->setDate(ui->dueDateEdit->date());
            item->update();
        }
    }
}

void KTodo::ringDateEditFinished(){
    QSqlQuery qy;
    qy.prepare("update todoitem set remtime = :remtime where activity = :activity");
    qy.bindValue(":activity",ui->checkBox->text());
    qy.bindValue(":remtime",ui->ringDateEdit->date());
    qy.exec();
    for(KTodoItem *item : todoItemList){
        if(item->getText() == ui->checkBox->text()){
            item->setDate(ui->ringDateEdit->date());
        }
    }
}

void KTodo::comboBoxIndexChanged(int index){
    QSqlQuery qy;
    qy.prepare("update todoitem set priority = :priority where activity = :activity");
    qy.bindValue(":activity",ui->checkBox->text());
    qy.bindValue(":priority",index);
    qy.exec();
}

void KTodo::checkBoxstateChanged(bool state){
    if(state == 1){
        inforHid();
    }
    QSqlQuery qy;
    qy.prepare("update todoitem set status = :status where activity = :activity");
    qy.bindValue(":activity",ui->checkBox->text());
    qy.bindValue(":status",!state);
    qy.exec();
    for(KTodoItem *item : todoItemList){
        if(item->getText() == ui->checkBox->text()){
            item->setCheck(state);
            item->update();
        }
    }
    if(ui->groupLabel->text() != "我的首页"){
        if(p_finishedBtn->getPath() == ":/res/xia"){
            this->lMidClear();
            p_lMid->insertWidget(0,p_finishedBtn);
            for(KTodoItem * allitem : todoItemList){
                //qDebug()<<dynamic_cast<KPrintButton *>(this->p_GLeft->button(index))->getText();
                if(allitem->getGroup() == ui->groupLabel->text())
                    {
                        if(allitem->isChecked() == 1){
                            hideItemList.append(allitem);
                            p_lMid->insertWidget(p_lMid->indexOf(p_finishedBtn)+1,allitem);
                        }
                        else{
                            nothideItemList.append(allitem);
                            p_lMid->insertWidget(0,allitem);
                        }
                    }
            }
        }
        else {
            this->lMidClear();
            p_lMid->insertWidget(0,p_finishedBtn);
            for(KTodoItem * allitem : todoItemList){
                if(allitem->getGroup() == ui->groupLabel->text())
                    {
                        if(allitem->isChecked() == 1){
                            hideItemList.append(allitem);
                        }
                        else{
                            nothideItemList.append(allitem);
                            p_lMid->insertWidget(0,allitem);
                        }
                    }
            }
        }
    }
    else{
        for(KTodoItem * allitem : nothideItemList){
            if(allitem->getText() == ui->checkBox->text())
                {
                p_lLeft->removeWidget(allitem);
                allitem->setParent(NULL);
                nothideItemList.removeOne(allitem);
                }
        }
    }
}

void KTodo::deleteBtnclicked(){
    QSqlQuery query;
    qDebug()<<ui->checkBox->text();
    query.prepare("delete from todoitem where activity = :activity");
    query.bindValue(":activity",ui->checkBox->text());
    query.exec();
    for(KTodoItem * item : todoItemList){
        if(item->getText() == ui->checkBox->text()){
            qDebug()<<"todo1"<<m_GMidNum;
            item->setParent(NULL);
            p_lMid->removeWidget(item);
            p_GMid->removeButton(item);
            m_GMidNum = m_GMidNum-1;
            todoItemList.removeOne(item);
                        qDebug()<<"todo2"<<m_GMidNum;
        }
    }
    for(KTodoItem * item : nothideItemList){
        if(item->getText() == ui->checkBox->text()){
            nothideItemList.removeOne(item);
                        qDebug()<<"nodo1"<<m_GMidNum;
        }
    }
    for(KTodoItem * item : hideItemList){
        if(item->getText() == ui->checkBox->text()){
            hideItemList.removeOne(item);
                        qDebug()<<"hiddo1"<<m_GMidNum;
        }
    }
    inforHid();
}

void KTodo::p_sortclicked(){
    if(ui->duetimeSortBtn->isHidden()){
        ui->duetimeSortBtn->show();
        ui->createTimeSortBtn->show();
        ui->prioritySortBtn->show();
    }
    else{
        ui->duetimeSortBtn->hide();
        ui->createTimeSortBtn->hide();
        ui->prioritySortBtn->hide();
    }
}

void KTodo::duetimeSortBtnclicked(){
    for(KTodoItem* item : nothideItemList){
        item->setParent(NULL);
        p_lLeft->removeWidget(item);
    }
    for(KTodoItem* item : hideItemList){
        item->setParent(NULL);
        p_lLeft->removeWidget(item);
    }
    ui->createTimeSortBtn->hide();
    ui->prioritySortBtn->hide();
    ui->duetimeSortBtn->hide();
    QSqlQuery qy("select * from todoitem order by duetime desc");
    while(qy.next()){
        if(qy.value(2) == ui->groupLabel->text()){
            for(KTodoItem * item : nothideItemList){
                if(item->getText() == qy.value(1)){
                    p_lMid->insertWidget(0,item);
                }
            }
            if(p_finishedBtn->getPath() == ":/res/xia"){
                for(KTodoItem * item : hideItemList){
                    if(item->getText() == qy.value(1)){
                        p_lMid->insertWidget(p_lMid->indexOf(p_finishedBtn)+1,item);
                    }
                }
        }
        }
    }
}

void KTodo::createTimeSortBtnclicked(){
    for(KTodoItem* item : nothideItemList){
        item->setParent(NULL);
        p_lLeft->removeWidget(item);
    }
    for(KTodoItem* item : hideItemList){
        item->setParent(NULL);
        p_lLeft->removeWidget(item);
    }
    ui->createTimeSortBtn->hide();
    ui->prioritySortBtn->hide();
    ui->duetimeSortBtn->hide();
    QSqlQuery qy("select * from todoitem order by createtime desc");
    while(qy.next()){
        if(qy.value(2) == ui->groupLabel->text()){
            for(KTodoItem * item : nothideItemList){
                if(item->getText() == qy.value(1)){
                    p_lMid->insertWidget(0,item);
                }
            }
            if(p_finishedBtn->getPath() == ":/res/xia"){
                for(KTodoItem * item : hideItemList){
                    if(item->getText() == qy.value(1)){
                        p_lMid->insertWidget(p_lMid->indexOf(p_finishedBtn)+1,item);
                    }
                }
        }
        }
    }
}

void KTodo::prioritySortBtnclicked(){
    for(KTodoItem* item : nothideItemList){
        item->setParent(NULL);
        p_lLeft->removeWidget(item);
    }
    for(KTodoItem* item : hideItemList){
        item->setParent(NULL);
        p_lLeft->removeWidget(item);
    }
    ui->createTimeSortBtn->hide();
    ui->prioritySortBtn->hide();
    ui->duetimeSortBtn->hide();
    QSqlQuery qy("select * from todoitem order by priority desc");
    while(qy.next()){
        if(qy.value(2) == ui->groupLabel->text()){
            for(KTodoItem * item : nothideItemList){
                if(item->getText() == qy.value(1)){
                    p_lMid->insertWidget(0,item);
                }
            }
            if(p_finishedBtn->getPath() == ":/res/xia"){
                for(KTodoItem * item : hideItemList){
                    if(item->getText() == qy.value(1)){
                        p_lMid->insertWidget(p_lMid->indexOf(p_finishedBtn)+1,item);
                    }
                }
        }
        }
    }
}
