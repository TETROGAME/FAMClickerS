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

    updateAutoClickerLabels();
    updateClickValueLabels();
    checkUpgradeClickValueAvailability();
    checkUpgradeAutoClickerAvailability();

    connectSlots();
}

UpgradeWindow::~UpgradeWindow()
{
    delete clickerGame;
    delete clickerWindow;
    delete ui;
}

void UpgradeWindow::checkUpgradeClickValueAvailability()
{
    if (clickerGame->getScore() >= clickerGame->getUpgradeCost()) {
        ui->upgradeClickValuePushButton->setEnabled(true);
    } else {
        ui->upgradeClickValuePushButton->setEnabled(false);
    }
}
void UpgradeWindow::checkUpgradeAutoClickerAvailability()
{
    if (clickerGame->getScore() >= clickerGame->getAutoClickerUpgradeCost()) {
        ui->upgradeAutoClickerPushButton->setEnabled(true);
    } else {
        ui->upgradeAutoClickerPushButton->setEnabled(false);
    }
}

void UpgradeWindow::updateClickValueLabels()
{
    ui->currentClickValuerLevelLabel->setText(QString("Очков за клик: %1")
                                     .arg(clickerGame->getClickValue()));
    ui->upgradeClickValuePriceLabel->setText(QString("Цена: %1 очков")
                                                 .arg(clickerGame->getUpgradeCost()));

}

void UpgradeWindow::updateAutoClickerLabels()
{
    ui->currentAutoClickerLevelLabel->setText(QString("Очков в секунду: %1")
                                                  .arg(clickerGame->getAutoClickerValue()));
    ui->upgradeAutoClickerPriceLabel->setText(QString("Цена: %1 очков")
                                                 .arg(clickerGame->getAutoClickerUpgradeCost()));
}

void UpgradeWindow::connectSlots()
{
    connect(clickerGame, &ClickerGame::scoreChanged, this, &UpgradeWindow::checkUpgradeClickValueAvailability);
    connect(clickerGame, &ClickerGame::scoreChanged, this, &UpgradeWindow::checkUpgradeAutoClickerAvailability);
    connect(clickerGame, &ClickerGame::scoreChanged, this, &UpgradeWindow::updateClickValueLabels);
    connect(clickerGame, &ClickerGame::scoreChanged, this, &UpgradeWindow::updateAutoClickerLabels);
}

void UpgradeWindow::on_upgradeClickValuePushButton_clicked()
{
    clickerGame->setClickValue(clickerGame->getClickValue() + 1);
    clickerGame->updateScore(-clickerGame->getUpgradeCost());
    clickerGame->setUpgradeCost(clickerGame->getUpgradeCost() * 2);
    updateClickValueLabels();
    checkUpgradeClickValueAvailability();
}


void UpgradeWindow::on_upgradeAutoClickerPushButton_clicked()
{
    clickerGame->setAutoClickerUpgradeCost(clickerGame->getAutoClickerValue() + 1);

}

