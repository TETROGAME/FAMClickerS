#include "upgradewindow.h"
#include "ui_upgradewindow.h"

UpgradeWindow::UpgradeWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UpgradeWindow)
{
    ui->setupUi(this);
    clickerWindow = new ClickerWindow(this);
    clickerWindow->show();
}

UpgradeWindow::~UpgradeWindow()
{
    delete ui;
}
