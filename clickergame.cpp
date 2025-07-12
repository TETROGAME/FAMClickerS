#include "clickergame.h"

ClickerGame::ClickerGame(QObject *parent)
    : QObject(parent)
{
    score = 0;
    clicks = 0;
    clickValue = 1;
    autoClickerValue = 0;
    autoClickerUpgradeCost = 1000;
    upgradeCost = 50;
    autoClickerEnabled = false;

}

void ClickerGame::saveGame(){
    QFile file("savefile.bin");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QDataStream out(&file);
        out << score << clicks << clickValue
            << autoClickerValue << autoClickerUpgradeCost << upgradeCost;
        file.close();
    } else{
        qDebug() << "An error occured while trying to create savefile";
    }
}

void ClickerGame::loadGame(){
    QFile file("savefile.bin");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QDataStream in(&file);
        in >> score >> clicks >> clickValue
            >> autoClickerValue >> autoClickerUpgradeCost >> upgradeCost;
        file.close();
        emit scoreChanged(score);
    } else{
        qDebug() << "An error occured while trying to open savefile";
    }
}

void ClickerGame::click(){
    score += clickValue;
    clicks++;
    emit scoreChanged(score);
}

int ClickerGame::getScore() const {
    return score;
}

int ClickerGame::getUpgradeCost() const { return upgradeCost; }

int ClickerGame::getAutoClickerUpgradeCost() const { return autoClickerUpgradeCost; }

int ClickerGame::getClickValue() const { return clickValue; }

int ClickerGame::getAutoClickerValue() const { return autoClickerValue; }

int ClickerGame::getClicks() const { return clicks; }

void ClickerGame::setClickValue(int value) { clickValue = value; }

void ClickerGame::setAutoClickerValue(int value) { autoClickerValue = value; }

void ClickerGame::setAutoClickerUpgradeCost(int cost) { autoClickerUpgradeCost = cost; }

void ClickerGame::setUpgradeCost(int cost) { upgradeCost = cost; }

void ClickerGame::setScore(int value) { score = value; }

void ClickerGame::setClicks(int value) { clicks = value; }

void ClickerGame::updateScore(int value)
{
    if (score < value) {
        QMessageBox::warning(nullptr, "Живи по средствам!", "Похоже тебе не хватает на это очков!");
        return;
    }
    score += value;
    emit scoreChanged(score);
}

ClickerGame::~ClickerGame()
{

}
