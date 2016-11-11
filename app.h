#ifndef APP_H
#define APP_H

#include <QWidget>
#include <QMainWindow>
#include <QMessageBox>

class QGroupBox;

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = 0);

signals:
    void signalFromButton(int buttonID);

private:
    QGroupBox *createSecondExclusiveGroup();

private slots:
    void slotButton1();
    void slotButton2();
    void slotButton3();

    void slotMessage(int buttonID);
};

#endif // APP_H
