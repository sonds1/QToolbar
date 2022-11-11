#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

/*    QList<QAction*> actions = ui->toolBar->actions();
    for(int i=0; i<actions.count(); i++) {
        if(actions.at(i)->text() == "Open") {
            actions.at(i)->setDisabled(true);
        }
    }
*/
    QComboBox* comboBox = new QComboBox;
    comboBox->addItem("Open");
    comboBox->addItem("Save");
    comboBox->addItem("Exit");

    ui->toolBar->addWidget(comboBox);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
    QAction* action = qobject_cast<QAction*>(sender());
    action->setDisabled(true);
    ui->labelSlot->setText("Open trigger");
}


void MainWindow::on_actionSave_triggered()
{
    ui->labelSlot->setText("Save trigger");
}


void MainWindow::on_actionExit_triggered()
{
    ui->labelSlot->setText("Exit trigger");
}


void MainWindow::on_pushButton_clicked()
{
    mpformToolbar = new FormToolbar;
    mpformToolbar->show();
}

