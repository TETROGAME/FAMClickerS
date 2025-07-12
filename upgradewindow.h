#ifndef UPGRADEWINDOW_H
#define UPGRADEWINDOW_H

#include <QMainWindow>
#include "clickerwindow.h"
#include "clickergame.h"
namespace Ui {
class UpgradeWindow;
}

class UpgradeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UpgradeWindow(QWidget *parent = nullptr, ClickerGame *game = nullptr);
    ~UpgradeWindow();

private:
    Ui::UpgradeWindow *ui;
    ClickerWindow *clickerWindow;
    ClickerGame *clickerGame;
};

#endif // UPGRADEWINDOW_H
