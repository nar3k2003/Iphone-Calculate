#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QString>

class Display:public QWidget
{
public:
    Display()
    {
        QHBoxLayout* hLayout = new QHBoxLayout(this);
        QLabel* display = new QLabel("0");
        display->setFixedHeight(160);
        display->setAlignment(Qt::AlignRight | Qt::AlignBottom);
        display->setStyleSheet("QLabel{font-size:65px;"
                               "font-weight: 150;"
                               "background-color: black;"
                               "color: white;}");

        hLayout->setContentsMargins(4,4,4,4);
        hLayout->addWidget(display);
    }
};

class ButtonGray:public QWidget{
public:
    ButtonGray(const QString& symbol)
    {
        QHBoxLayout* hLayout = new QHBoxLayout(this);
        QPushButton* button = new QPushButton(symbol);
        button->setStyleSheet("QPushButton{background-color:#D4D4D2; "
                              "color:black; "
                              "font-size: 22px; "
                              "height: 56px; "
                              "width: 56px; "
                              "border-radius: 28px;}");
        hLayout->setContentsMargins(4,4,4,4);
        hLayout->addWidget(button);
    }
};

class ButtonOrange:public QWidget{
public:
    ButtonOrange(const QString& symbol)
    {
        QHBoxLayout* hLayout = new QHBoxLayout(this);
        QPushButton* button = new QPushButton(symbol);
        button->setStyleSheet("QPushButton{background-color:#FF9500; "
                              "color:white; "
                              "font-size: 22px; "
                              "height: 56px; "
                              "width: 56px; "
                              "border-radius: 28px;}");
        hLayout->setContentsMargins(4,4,4,4);
        hLayout->addWidget(button);
    }
};

class ButtonDarkGray:public QWidget{
public:
    ButtonDarkGray(const QString& symbol)
    {
        QHBoxLayout* hLayout = new QHBoxLayout(this);
        QPushButton* button = new QPushButton(symbol);
        button->setStyleSheet("QPushButton{background-color:#505050; "
                              "color:white; "
                              "font-size: 22px; "
                              "height: 56px; "
                              "width: 56px; "
                              "border-radius: 28px;}");
        hLayout->setContentsMargins(4,4,4,4);
        hLayout->addWidget(button);
    }
};

class Calculate:public QWidget
{
public:
    Calculate()
    {
        setStyleSheet("QWidget{background-color:black; "
                      "color:white; "
                      "border-radius:32px; "
                      "height:550px; "
                      "width:310px; "
                      "}");
        QVBoxLayout* vLayout = new QVBoxLayout(this);
        QHBoxLayout* hLayout1 = new QHBoxLayout();
        QHBoxLayout* hLayout2 = new QHBoxLayout();
        QHBoxLayout* hLayout3 = new QHBoxLayout();
        QHBoxLayout* hLayout4 = new QHBoxLayout();
        QHBoxLayout* hLayout5 = new QHBoxLayout();
        QHBoxLayout* hLayout6 = new QHBoxLayout();

        vLayout->setContentsMargins(12,12,12,12);

        vLayout->addWidget(new Display());
        vLayout->addLayout(hLayout1);
        hLayout1->addWidget(new ButtonGray("AC"));
        hLayout1->addWidget(new ButtonGray("+/-"));
        hLayout1->addWidget(new ButtonGray("%"));
        hLayout1->addWidget(new ButtonOrange("/"));
        vLayout->addLayout(hLayout2);
        hLayout2->addWidget(new ButtonDarkGray("7"));
        hLayout2->addWidget(new ButtonDarkGray("8"));
        hLayout2->addWidget(new ButtonDarkGray("9"));
        hLayout2->addWidget(new ButtonOrange("x"));
        vLayout->addLayout(hLayout3);
        hLayout3->addWidget(new ButtonDarkGray("4"));
        hLayout3->addWidget(new ButtonDarkGray("5"));
        hLayout3->addWidget(new ButtonDarkGray("6"));
        hLayout3->addWidget(new ButtonOrange("-"));
        vLayout->addLayout(hLayout4);
        hLayout4->addWidget(new ButtonDarkGray("1"));
        hLayout4->addWidget(new ButtonDarkGray("2"));
        hLayout4->addWidget(new ButtonDarkGray("3"));
        hLayout4->addWidget(new ButtonOrange("+"));
        vLayout->addLayout(hLayout5);
        hLayout5->addWidget(new ButtonDarkGray("0"));
        hLayout5->addLayout(hLayout6);
        hLayout6->addWidget(new ButtonDarkGray("."));
        hLayout6->addWidget(new ButtonOrange("="));
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setFixedSize(QSize(320, 580));
    w.setContentsMargins(8,8,8,8);
    w.setCentralWidget(new Calculate());
    w.show();
    return a.exec();
}
