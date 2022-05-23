#include "setuplayout.h"

setupLayout::setupLayout()
{
    tE->setMaximumSize(100,25);
    tE->setText("Количество ПК");
    tE->setEnabled(false);

    pB->setText("Принять");

    sB->setMaximumSize(100,25);


    vBL->addWidget(tE);
    vBL->addWidget(sB);
    vBL->addWidget(pB);

    hBL->addLayout(vBL);


}
