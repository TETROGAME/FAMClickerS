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
    autoClickerTick();
}

void ClickerGame::saveGame(const QString& filename){
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QDataStream out(&file);
        out << score << clicks << clickValue
            << autoClickerValue << autoClickerUpgradeCost << upgradeCost
            << autoClickerEnabled;
        file.close();
    } else{
        qDebug() << "An error occured while trying to create savefile";
    }
}

void ClickerGame::loadGame(const QString& filename){
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream in(&file);
        in >> score >> clicks >> clickValue
            >> autoClickerValue >> autoClickerUpgradeCost >> upgradeCost
            >> autoClickerEnabled;
        file.close();
        emit scoreChanged(score);
        this->autoClickerTick();
    } else{
        qDebug() << "An error occured while trying to open savefile";
    }
}

void ClickerGame::click(){
    score += clickValue;
    clicks++;
    emit scoreChanged(score);
}
int ClickerGame::getScore() const { return score;}
int ClickerGame::getUpgradeCost() const { return upgradeCost; }
int ClickerGame::getAutoClickerUpgradeCost() const { return autoClickerUpgradeCost; }
int ClickerGame::getClickValue() const { return clickValue; }
int ClickerGame::getAutoClickerValue() const { return autoClickerValue; }
int ClickerGame::getClicks() const { return clicks; }
bool ClickerGame::isAutoClickerEnabled() const { return autoClickerEnabled; }
void ClickerGame::setClickValue(int value) { clickValue = value; }
void ClickerGame::setAutoClickerValue(int value) { autoClickerValue = value; }
void ClickerGame::setAutoClickerUpgradeCost(int cost) { autoClickerUpgradeCost = cost; }
void ClickerGame::setUpgradeCost(int cost) { upgradeCost = cost; }
void ClickerGame::setScore(int value) { score = value; emit scoreChanged(score); }
void ClickerGame::setClicks(int value) { clicks = value; }
void ClickerGame::setAutoClickerEnabled(bool enabled) {
    if(autoClickerEnabled != enabled){
        autoClickerEnabled = enabled;
        if(enabled){
            autoClickerTick();
        }
    }
}

void ClickerGame::updateScore(int value)
{
    if (score + value < 0) {
        QMessageBox::warning(nullptr, "Живи по средствам!", "Похоже тебе не хватает на это очков!");
        return;
    }
    score += value;
    emit scoreChanged(score);
}

void ClickerGame::autoClickerTick(){
    QTimer::singleShot(1000, this, [this]() {
        if (autoClickerEnabled) {
            updateScore(autoClickerValue);
            autoClickerTick();
        }
    });
}

ClickerGame::~ClickerGame()
{

}
