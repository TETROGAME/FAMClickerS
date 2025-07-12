#include "upgradewindow.h"
#include "ui_upgradewindow.h"

UpgradeWindow::UpgradeWindow(QWidget *parent, ClickerGame *game)
    : QMainWindow(parent)
    , ui(new Ui::UpgradeWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("УЛУЧШАЙ!1!!1!");

    clickerGame = game;
    clickerWindow = new ClickerWindow(this, clickerGame);
    clickerWindow->show();
}

UpgradeWindow::~UpgradeWindow()
{
    delete clickerGame;
    delete clickerWindow;
    delete ui;
}
