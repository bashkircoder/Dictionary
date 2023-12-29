#include "rustoengwindow.h"
#include "ui_rustoengwindow.h"
#include "data.h"

RustoEngWindow::RustoEngWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RustoEngWindow)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::WindowMinimizeButtonHint, false);
    this->setWindowFlag(Qt::WindowMinMaxButtonsHint, false);
    this->setWindowFlag(Qt::WindowSystemMenuHint, false);
    this->setWindowFlag(Qt::WindowFullscreenButtonHint, false);
    this->setWindowFlag(Qt::CustomizeWindowHint, true);
    this->setWindowFlag(Qt::FramelessWindowHint, false);
    this->setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
}

RustoEngWindow::~RustoEngWindow()
{
    delete ui;
}


void RustoEngWindow::on_ButtonRuToEng_clicked()
{
    ui->textEditEng->clear();


    QString RuWord = ui->textEditRus->toPlainText();

    Data* data;

    data = new Data("D:\\Study\\2812Class\\Dictionary.db");



    auto translate = data->RuToEng(RuWord);

    foreach (auto item, translate) {

        ui->textEditEng->append(item.getRuWord());

    }
}


void RustoEngWindow::on_ButtonEngToRu_clicked()
{
    ui->textEditRus->clear();


    QString EnWord = ui->textEditEng->toPlainText();

    Data* data;

    data = new Data("D:\\Study\\2812Class\\Dictionary.db");



    auto translate = data->EngToRu(EnWord);

    foreach (auto item, translate) {

        ui->textEditRus->append(item.getRuWord());

    }
}

