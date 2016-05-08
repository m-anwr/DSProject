#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addRequestBtn_clicked();
    void on_createSimFileBtn_clicked();
    void on_startSimBtn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
