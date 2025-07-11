#include "clickerwindow.h"
#include "ui_clickerwindow.h"

ClickerWindow::ClickerWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClickerWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    this->setWindowTitle("КЛИКАЙ!!!");
}

ClickerWindow::~ClickerWindow()
{
    delete ui;
}

void ClickerWindow::connectSlots()
{
}
