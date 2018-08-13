#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "reversi.h"
#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int rowInput;// the input row 
    int colInput;// the input column


public slots:
    void getChessBoardInput();
    void refresh();
    void timeSlots();

private:
    Ui::MainWindow *ui;// Qt's application main window
    Reversi chess;// reversi chess board
    QTimer *timer;// timer for count down
    int secCount;// counter for count down

};

#endif // MAINWINDOW_H
