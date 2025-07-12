#include "clickerwindow.h"
#include "ui_clickerwindow.h"

ClickerWindow::ClickerWindow(QWidget *parent, ClickerGame* game)
    : QMainWindow(parent)
    , ui(new Ui::ClickerWindow)
{
    ui->setupUi(this);
    clickerGame = game;
    this->setFixedSize(this->size());
    this->setWindowTitle("КЛИКАЙ!1!!1!");

    setWindowFlags(Qt::Window | Qt::CustomizeWindowHint
                   | Qt::WindowTitleHint);
}

ClickerWindow::~ClickerWindow()
{
    delete ui;
}

void ClickerWindow::connectSlots()
{

}

void ClickerWindow::updateScore()
{
    if (clickerGame) {
        ui->scoreLabel->setText(QString("Очки: %1")
                                    .arg(QString::number(clickerGame->getScore())));
    } else {
        qDebug() << "ClickerGame instance is not initialized.";
    }
}

void ClickerWindow::on_clickerPushButton_clicked()
{
    clickerGame->click();
    updateScore();
}

