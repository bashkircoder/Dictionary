#ifndef RUSTOENGWINDOW_H
#define RUSTOENGWINDOW_H

#include <QMainWindow>

namespace Ui {
class RustoEngWindow;
}

class RustoEngWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RustoEngWindow(QWidget *parent = nullptr);
    ~RustoEngWindow();

private slots:

    void on_ButtonRuToEng_clicked();

    void on_ButtonEngToRu_clicked();

private:
    Ui::RustoEngWindow *ui;
};

#endif // RUSTOENGWINDOW_H
