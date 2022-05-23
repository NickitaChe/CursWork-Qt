#ifndef COMPUTER_H
#define COMPUTER_H

#include <QVBoxLayout>
#include <QVariant>
#include <QString>
#include <QTextEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QTimer>


class computer : QWidget
{
    Q_OBJECT
public:
    computer(QString n = "");

    QVBoxLayout* vBL = new QVBoxLayout;
    QHBoxLayout *hBL_1 = new QHBoxLayout;
    QHBoxLayout *hBL_2 = new QHBoxLayout;
    QHBoxLayout *hBL_3 = new QHBoxLayout;


    QTextEdit* name = new QTextEdit;
    QTextEdit* sysText = new QTextEdit;
    QTextEdit* sysStatus = new QTextEdit;
    QTextEdit* tehText = new QTextEdit;
    QTextEdit* tehStatus = new QTextEdit;
    QTextEdit* ingener = new QTextEdit;

    QTimer* timer;

    void reload();
    void reShow();

private:
    void TextConstructor(QTextEdit* tE, int i = 100);

public slots:
    void slotTimer();
};

#endif // COMPUTER_H
