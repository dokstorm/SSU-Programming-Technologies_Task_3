#include <QtWidgets>
#include <QMessageBox>
#include "app.h"
#include <QtCore>

Window::Window(QWidget *parent) : QWidget(parent)
{
    QGridLayout *grid = new QGridLayout;
    grid->addWidget(createSecondExclusiveGroup());
    setLayout(grid);

    setWindowTitle(tr("SomeApp"));
    resize(800, 600);
}

QGroupBox *Window::createSecondExclusiveGroup()
 {
     QGroupBox *groupBox = new QGroupBox(tr("Radiobutton group"));
     groupBox->setCheckable(true);
     groupBox->setChecked(false);
     QRadioButton *button1 = new QRadioButton("1", this);
     QRadioButton *button2 = new QRadioButton("2", this);
     QRadioButton *button3 = new QRadioButton("3", this);

     QVBoxLayout *vbox = new QVBoxLayout;
     vbox->addWidget(button1);
     vbox->addWidget(button2);
     vbox->addWidget(button3);
     vbox->addStretch(1);
     groupBox->setLayout(vbox);

     connect(button1, SIGNAL(clicked()), this, SLOT(slotButton1()));
     connect(button2, SIGNAL(clicked()), this, SLOT(slotButton2()));
     connect(button3, SIGNAL(clicked()), this, SLOT(slotButton3()));

     connect(this, &Window::signalFromButton, this, &Window::slotMessage);

     return groupBox;
}

void Window::slotButton1()
{
    emit signalFromButton(1);
}
void Window::slotButton2()
{
    emit signalFromButton(2);
}
void Window::slotButton3()
{
    emit signalFromButton(3);
}
void Window::slotMessage(int buttonID)
{
    QMessageBox::information(this, "Message", "You chose Button " + QString::number(buttonID));
}
