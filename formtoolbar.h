#ifndef FORMTOOLBAR_H
#define FORMTOOLBAR_H

#include <QWidget>
#include <QToolBar>

namespace Ui {
class FormToolbar;
}

class FormToolbar : public QWidget
{
    Q_OBJECT

public:
    explicit FormToolbar(QWidget *parent = nullptr);
    ~FormToolbar();

private slots:
    void onOpen();
    void onSave();
    void onExit();

private:
    Ui::FormToolbar *ui;

    QToolBar* mpToolbar;

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    QPoint mptMouse;
    QPoint mptBase;
    bool mbPressed = false;

};

#endif // FORMTOOLBAR_H
