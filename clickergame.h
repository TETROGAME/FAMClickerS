#ifndef CLICKERGAME_H
#define CLICKERGAME_H

#include <QObject>
#include <QTextStream>
#include <QDebug>
#include <QFile>

class ClickerGame : public QObject
{
    Q_OBJECT
public:
    explicit ClickerGame(QObject *parent = nullptr);
    ~ClickerGame();

    void saveGame();
    void loadGame();
    void click();

    int getScore() const;

    void updateScore(int value);
    void buyAutoClicker();
    void buyUpgrade();

signals:
    void scoreChanged(int newScore);

private:
    int score;
    int clicks;
    int clickValue;
    int autoClickerValue;
    int autoClickerCost;
    int upgradeCost;
};

#endif // CLICKERGAME_H
