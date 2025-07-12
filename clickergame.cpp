#include "clickergame.h"

ClickerGame::ClickerGame(QObject *parent)
    : QObject(parent)
{
    score = 0;
    clicks = 0;
    clickValue = 1;
    autoClickerValue = 0;
    autoClickerCost = 10;
    upgradeCost = 50;
}

void ClickerGame::saveGame(){
    QFile file("savefile.bin");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QDataStream out(&file);
        out << score << clicks << clickValue
            << autoClickerValue << autoClickerCost << upgradeCost;
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
            >> autoClickerValue >> autoClickerCost >> upgradeCost;
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

ClickerGame::~ClickerGame()
{

}
