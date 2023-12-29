#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::WindowMinimizeButtonHint, false);
    this->setWindowFlag(Qt::WindowMinMaxButtonsHint, false);
    this->setWindowFlag(Qt::WindowSystemMenuHint, false);
    this->setWindowFlag(Qt::WindowFullscreenButtonHint, false);
    this->setWindowFlag(Qt::CustomizeWindowHint, true);
    this->setWindowFlag(Qt::FramelessWindowHint, false);
    this->setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);

    rustoeng = new RustoEngWindow();

    connect(ui->ButtonRusToEng, SIGNAL(clicked()), this, SLOT(RusToEngWindowOpen()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::RusToEngWindowOpen()
{

    auto window = new RustoEngWindow();
    window->show();

}

void MainWindow::on_ButtonAddWords_clicked()
{
    auto window = new AddWordsWindow();
    window->show();
}

