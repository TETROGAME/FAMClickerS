#ifndef CLICKERGAME_H
#define CLICKERGAME_H
#include <QTextStream>
#include <QDebug>
#include <QFile>
class ClickerGame
{
public:
    ClickerGame();

    void saveGame();
    void loadGame();
    void click();

    int getScore();
    ~ClickerGame();

private:
    int score;
    int clicks;
    int clickValue;
    int autoClickers;
    int autoClickerCost;
    int upgradeCost;

    void updateScore(int value);
    void buyAutoClicker();
    void buyUpgrade();

};

#endif // CLICKERGAME_H
