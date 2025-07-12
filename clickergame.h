#ifndef CLICKERGAME_H
#define CLICKERGAME_H

#include <QObject>
#include <QTextStream>
#include <QDebug>
#include <QFile>
#include <QMessageBox>
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
    int getUpgradeCost() const;
    int getAutoClickerUpgradeCost() const;
    int getClickValue() const;
    int getAutoClickerValue() const;
    int getClicks() const;
    void setClickValue(int value);
    void setAutoClickerValue(int value);
    void setAutoClickerUpgradeCost(int cost);
    void setUpgradeCost(int cost);
    void setScore(int value);
    void setClicks(int value);

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
    int autoClickerUpgradeCost;
    int upgradeCost;

    bool autoClickerEnabled;
};

#endif // CLICKERGAME_H
