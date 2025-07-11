#ifndef UPGRADEWINDOW_H
#define UPGRADEWINDOW_H

#include <QMainWindow>
#include "clickerwindow.h"
namespace Ui {
class UpgradeWindow;
}

class UpgradeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UpgradeWindow(QWidget *parent = nullptr);
    ~UpgradeWindow();

private:
    Ui::UpgradeWindow *ui;
    ClickerWindow *clickerWindow;
};

#endif // UPGRADEWINDOW_H
