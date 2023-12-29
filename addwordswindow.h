#ifndef ADDWORDSWINDOW_H
#define ADDWORDSWINDOW_H

#include <QMainWindow>
#include "data.h"

namespace Ui {
class AddWordsWindow;
}

class AddWordsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddWordsWindow(QWidget *parent = nullptr);
    ~AddWordsWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddWordsWindow *ui;
};

#endif // ADDWORDSWINDOW_H
