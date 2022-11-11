#include "formtoolbar.h"
#include "ui_formtoolbar.h"
#include <QMouseEvent>

FormToolbar::FormToolbar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormToolbar)
{
    ui->setupUi(this);

    mpToolbar = new QToolBar("tool bar");
    mpToolbar->addAction(QIcon(":/img/open.png"), "Open", this, SLOT(onOpen()));
    mpToolbar->addAction(QIcon(":/img/save.png"), "Save", this, SLOT(onSave()));
    mpToolbar->addAction(QIcon(":/img/exit.png"), "Exit", this, SLOT(onExit()));
    mpToolbar->setStyleSheet("QToolBar {border: 2px solid black; background-color: white;}");
    mpToolbar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    ui->hLayout->addWidget(mpToolbar);
    mpToolbar->move(0, 0);
}

FormToolbar::~FormToolbar()
{
    delete ui;
}

void FormToolbar::onOpen()
{
    ui->label->setText("Open");
}

void FormToolbar::onSave()
{
    ui->label->setText("Save");
}

void FormToolbar::onExit()
{
    ui->label->setText("Exit");
}

void FormToolbar::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) {
        mptBase = ui->horizontalLayoutWidget->pos();
        QSize size = mpToolbar->size();
        QPoint ptMouse = event->pos();
        if(mptBase.x() <= ptMouse.x() && ptMouse.x() <= mptBase.x() + size.width()
                && mptBase.y() <= ptMouse.y() && ptMouse.y() <= mptBase.y() + size.height()) {
            mptMouse = ptMouse;
            mbPressed = true;
        }
    }
}

void FormToolbar::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) {
        mbPressed = false;
    }
}

void FormToolbar::mouseMoveEvent(QMouseEvent *event)
{
    if(mbPressed) {
        int x = event->pos().x() - mptMouse.x();
        int y = event->pos().y() - mptMouse.y();

        ui->horizontalLayoutWidget->move(mptBase.x() + x, mptBase.y() + y);
    }
}
