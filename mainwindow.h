#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QTimer>
#include <QTime>
#include <QtMath>
#include <QRandomGenerator>



#include <setuplayout.h>
#include "computer.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    QTimer *masterTimer;
    QTimer *ingenerTimer;

    setupLayout *sL = new setupLayout;
    QGridLayout *gL = new QGridLayout;

    QList <computer*> *computerList = new QList <computer*>;
    QList <computer*> *masterList = new QList <computer*>;

    int ingenerPos = 0;

    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
    void slot_start();


private slots:
    void slotIngenerTimer();
    void slotMasterTimer();
    void slotBreakTimer();
};
#endif // MAINWINDOW_H
