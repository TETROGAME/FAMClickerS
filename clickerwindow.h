#ifndef CLICKERWINDOW_H
#define CLICKERWINDOW_H

#include <QMainWindow>
namespace Ui {
class ClickerWindow;
}

class ClickerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClickerWindow(QWidget *parent = nullptr);
    ~ClickerWindow();
private slots:
    void connectSlots();
private:
    Ui::ClickerWindow *ui;
};

#endif // CLICKERWINDOW_H
