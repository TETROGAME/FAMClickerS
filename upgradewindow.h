#ifndef UPGRADEWINDOW_H
#define UPGRADEWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
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

private slots:
    void checkUpgradeClickValueAvailability();
    void checkUpgradeAutoClickerAvailability();
    void checkAutoClickerEnabled();
    void updateClickValueLabels();
    void updateAutoClickerLabels();
    void connectSlots();

    void on_upgradeClickValuePushButton_clicked();
    void on_upgradeAutoClickerPushButton_clicked();

    void on_saveGameAction_triggered();

    void on_loadGameAction_triggered();

private:
    Ui::UpgradeWindow *ui;
    ClickerWindow *clickerWindow;
    ClickerGame *clickerGame;
};

#endif // UPGRADEWINDOW_H
