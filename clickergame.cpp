#include "clickergame.h"

ClickerGame::ClickerGame() {
    score = 0;
    clicks = 0;
    clickValue = 1;
    autoClickers = 0;
    autoClickerCost = 10;
    upgradeCost = 50;
}

void ClickerGame::saveGame(){
    QFile file("savefile.bin");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QDataStream out(&file);
        out << score << clicks << clickValue
            << autoClickers << autoClickerCost << upgradeCost;
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
            >> autoClickers >> autoClickerCost >> upgradeCost;
        file.close();
    } else{
        qDebug() << "An error occured while trying to open savefile";
    }
}

void ClickerGame::click(){
    score += clickValue;
    clicks++;
}

int ClickerGame::getScore(){
    return score;
}

ClickerGame::~ClickerGame()
{

}
