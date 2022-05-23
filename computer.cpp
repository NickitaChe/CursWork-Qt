#include "computer.h"

computer::computer(QString n)
{
    name->setText(n);
    sysText->setText("Статус Систем:");
    tehText->setText("Статус Оборудования:");

    TextConstructor(sysStatus);
    TextConstructor(sysText);
    TextConstructor(tehStatus);
    TextConstructor(tehText);
    TextConstructor(name);
    TextConstructor(ingener);

    sysStatus->setText("Норм");
    tehStatus->setText("Норм");

    hBL_1->addWidget(sysText);
    hBL_1->addWidget(sysStatus);

    hBL_2->addWidget(tehText);
    hBL_2->addWidget(tehStatus);

    hBL_3->addWidget(name);
    hBL_3->addWidget(ingener);

    hBL_1->setSpacing(0);
    hBL_2->setSpacing(0);
    hBL_3->setSpacing(0);

    vBL->setSpacing(0);
    vBL->addLayout(hBL_3);
    vBL->addLayout(hBL_1);
    vBL->addLayout(hBL_2);
}


void computer::TextConstructor(QTextEdit* tE, int i){
    tE->setMaximumSize(i,40);
    tE->setEnabled(false);


}

void computer::reShow(){
    sysStatus->show();
    tehStatus->show();
    ingener->show();
}

void computer::reload(){

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimer()));
    timer->start(5000);
    sysStatus->setText("Перезагрузка");
}

void computer::slotTimer(){
    sysStatus->setText("Норм");
    timer->stop();
}
