#include "upgradewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClickerGame game;
    UpgradeWindow upgradeWindow(nullptr, &game);
    upgradeWindow.show();
    return a.exec();
}
