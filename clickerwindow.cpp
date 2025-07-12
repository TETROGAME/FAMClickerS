#include "clickerwindow.h"
#include "qmovie.h"
#include "ui_clickerwindow.h"

ClickerWindow::ClickerWindow(QWidget *parent, ClickerGame* game)
    : QMainWindow(parent)
    , ui(new Ui::ClickerWindow)
{
    ui->setupUi(this);
    clickerGame = game;
    this->setFixedSize(this->size());
    this->setWindowTitle("КЛИКАЙ!1!!1!");
    QString happyRaaccoonGifPath = ":/source-images/images/happy_racoon.gif";
    setMovie(happyRaaccoonGifPath);
    connectSlots();

    setWindowFlags(Qt::Window | Qt::CustomizeWindowHint
                   | Qt::WindowTitleHint);
}

ClickerWindow::~ClickerWindow()
{
    delete ui;
}

void ClickerWindow::setMovie(QString &path)
{
    QMovie *movie = new QMovie(path);
    if (movie->isValid()) {
        ui->clickerPushButton->setIcon(QIcon(QPixmap::fromImage(movie->currentImage())));
        ui->clickerPushButton->setIconSize(QSize(250, 250));
        movie->start();
        connect(movie, &QMovie::frameChanged, this, [this, movie]() {
            ui->clickerPushButton->setIcon(QIcon(QPixmap::fromImage(movie->currentImage())));
        });
    } else {
        qDebug() << "Failed to load movie from path:" << path;
    }
}

void ClickerWindow::connectSlots()
{
    connect(clickerGame, &ClickerGame::scoreChanged, this, &ClickerWindow::updateScore);
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
}

