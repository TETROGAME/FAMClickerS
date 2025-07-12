#ifndef CLICKERWINDOW_H
#define CLICKERWINDOW_H

#include <QMainWindow>
#include "clickergame.h"

namespace Ui {
class ClickerWindow;
}

class ClickerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClickerWindow(QWidget *parent = nullptr, ClickerGame* game = nullptr);
    ~ClickerWindow();
private slots:
    void connectSlots();
    void updateScore();
    void on_clickerPushButton_clicked();

private:
    Ui::ClickerWindow *ui;
    ClickerGame *clickerGame;
};

#endif // CLICKERWINDOW_H
