#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(sL->pB,&QPushButton::clicked,this,&MainWindow::slot_start);
    ui->verticalLayout->addLayout(sL->hBL);
    ui->verticalLayout->addLayout(gL);




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_start(){
    computerList->clear();
    masterList->clear();
    ingenerPos = 0;

    for (int i = 0;i < sL->sB->value() ; ++i) {
        computer *t = new computer("ПК № "+ QString::number(i));
        computerList->append(t);
        gL->addLayout(t->vBL,i/4,i%4);
    }

    ingenerTimer = new QTimer();
    connect(ingenerTimer, SIGNAL(timeout()), this, SLOT(slotIngenerTimer()));
    ingenerTimer->start(3000);


    masterTimer = new QTimer();
    connect(masterTimer, SIGNAL(timeout()), this, SLOT(slotMasterTimer()));
    masterTimer->start(10000);

    QTimer *breakTimer = new QTimer();
    connect(breakTimer, SIGNAL(timeout()), this, SLOT(slotBreakTimer()));
    breakTimer->start(5000);

}

void MainWindow::slotIngenerTimer()
{
    if(computerList->count()> ingenerPos){
        computerList->at(ingenerPos)->ingener->setText("");
        if(ingenerPos < computerList->count()-1)
            ingenerPos++;
        else ingenerPos = 0;

        if(computerList->at(ingenerPos)->tehStatus->toPlainText() == "Ошибка"){
            computerList->at(ingenerPos)->tehStatus->setText("В Очереди");
            masterList->append(computerList->at(ingenerPos));
        }
        if(computerList->at(ingenerPos)->sysStatus->toPlainText() == "Ошибка"){
            computerList->at(ingenerPos)->reload();
        }
        computerList->at(ingenerPos)->ingener->setText("Инженер Тут");
    }
    else ingenerPos = 0;

}


void MainWindow::slotMasterTimer()
{
    if(masterList->count() > 0 && masterList->first()->tehStatus->toPlainText() == "В Процессе"){
        masterList->first()->tehStatus->setText("Норм");
        masterList->pop_front();
    }

    if(masterList->count() > 0){
        masterList->first()->tehStatus->setText("В Процессе");
    }
}

void MainWindow::slotBreakTimer()
{
    static QRandomGenerator *random =  new QRandomGenerator();
    int t = random->generate()%computerList->count();
    if(computerList->at(t)->sysStatus->toPlainText()=="Норм" && computerList->at(t)->tehStatus->toPlainText()=="Норм"){
        int p = random->generate()%3;
        switch (p) {
        case 0:
            break;
        case 1:
            computerList->at(t)->tehStatus->setText("Ошибка");
            break;
        case 2:
            computerList->at(t)->sysStatus->setText("Ошибка");
            break;
        }
    computerList->at(t)->reShow();
    }
}
