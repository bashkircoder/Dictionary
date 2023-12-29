#include "addwordswindow.h"
#include "ui_addwordswindow.h"
#include "QMessageBox"

AddWordsWindow::AddWordsWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AddWordsWindow)
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

AddWordsWindow::~AddWordsWindow()
{
    delete ui;
}

void AddWordsWindow::on_pushButton_clicked()
{

    QString RuWord = ui->EditRus->text();
    QString ENWord = ui->EditEng->text();

    Data* data;

    data = new Data("D:\\Study\\2812Class\\Dictionary.db");

    data->AddWord(RuWord, ENWord);

    ui->EditRus->clear();
    ui->EditEng->clear();

    QMessageBox::information(this, "Информация", "Запись добавлена", QMessageBox::Button::Ok);
    this->close();

}

