#include "upgradewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UpgradeWindow upgradeWindow;
    upgradeWindow.show();
    return a.exec();
}
