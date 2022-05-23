#ifndef SETUPLAYOUT_H
#define SETUPLAYOUT_H


#include <QVBoxLayout>
#include <QVariant>
#include <QString>
#include <QTextEdit>
#include <QSpinBox>
#include <QPushButton>

#include <QHBoxLayout>

class setupLayout
{
public:

    QPushButton* pB = new QPushButton;
    QSpinBox* sB = new QSpinBox;
    QVBoxLayout* vBL = new QVBoxLayout;
    QTextEdit* tE = new QTextEdit;
    QHBoxLayout *hBL = new QHBoxLayout;
    setupLayout();
};

#endif // SETUPLAYOUT_H
