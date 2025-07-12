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

void UpgradeWindow::checkAutoClickerEnabled(){
    if(clickerGame->getAutoClickerValue() > 0){
        clickerGame->setAutoClickerEnabled(true);
    } else {
        clickerGame->setAutoClickerEnabled(false);
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
    connect(clickerGame, &ClickerGame::scoreChanged, this, &UpgradeWindow::checkAutoClickerEnabled);
}

void UpgradeWindow::on_upgradeClickValuePushButton_clicked()
{
    int oldCost = clickerGame->getUpgradeCost();
    clickerGame->setClickValue(clickerGame->getClickValue() + 1);
    clickerGame->setUpgradeCost(oldCost * 2);
    clickerGame->updateScore(-oldCost);
}

void UpgradeWindow::on_upgradeAutoClickerPushButton_clicked()
{
    int oldAutoCost = clickerGame->getAutoClickerUpgradeCost();
    clickerGame->setAutoClickerValue(clickerGame->getAutoClickerValue() + 1);
    clickerGame->setAutoClickerUpgradeCost(oldAutoCost * 10);
    clickerGame->updateScore(-oldAutoCost);
}

void UpgradeWindow::on_saveGameAction_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Сохранить игру")
                                                    , "", tr("Файлы сохранений (*.savefile)"));
    if (!filename.isEmpty()) {
        clickerGame->saveGame(filename);
        QMessageBox::information(this, "Сохранение игры", "Игра успешно сохранена в файл: " + filename);
    }

}


void UpgradeWindow::on_loadGameAction_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Загрузить игру")
                                                    , "", tr("Файлы сохранений (*.savefile)"));
    if (!filename.isEmpty()) {
        clickerGame->loadGame(filename);
        QMessageBox::information(this, "Загрузка игры", "Игра успешно загружена из файла: " + filename);
    }

}

