#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //bind each input buttons with function getChessBoardInput() 
    connect(ui->r0c0,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r0c1,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r0c2,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r0c3,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r0c4,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r0c5,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r0c6,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r0c7,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r1c0,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r1c1,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r1c2,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r1c3,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r1c4,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r1c5,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r1c6,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r1c7,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r2c0,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r2c1,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r2c2,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r2c3,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r2c4,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r2c5,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r2c6,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r2c7,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r3c0,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r3c1,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r3c2,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r3c3,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r3c4,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r3c5,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r3c6,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r3c7,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r4c0,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r4c1,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r4c2,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r4c3,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r4c4,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r4c5,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r4c6,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r4c7,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r5c0,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r5c1,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r5c2,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r5c3,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r5c4,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r5c5,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r5c6,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r5c7,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r6c0,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r6c1,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r6c2,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r6c3,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r6c4,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r6c5,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r6c6,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r6c7,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r7c0,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r7c1,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r7c2,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r7c3,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r7c4,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r7c5,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r7c6,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    connect(ui->r7c7,SIGNAL(clicked()),this,SLOT(getChessBoardInput()));
    // initialize chess board and UI
    chess.init();
    ui->sign->setStyleSheet(tr("QPushButton { background-color: rgb(0, 0, 0);border-radius: 3px} QPushButton:hover { background-color: rgb(0, 0, 0); }"));
    QString bc;
    QFont font;
    font.setPointSize(14);
    ui->blackcnt->setFont(font);
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::white);
    ui->blackcnt->setPalette(pa);
    ui->blackcnt->setText(bc.setNum(chess.blackCount()));
    ui->whitecnt->setFont(font);
    ui->whitecnt->setText(bc.setNum(chess.whiteCount()));
    // set count down
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeSlots()));
    timer->start(1000);
    secCount=60;
    font.setPointSize(15);
    ui->countdown->setFont(font);
    ui->countdown->setText(bc.setNum(secCount));

    //If AI is black
    chess.AIplayer();
    refresh();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// get the input of player
void MainWindow::getChessBoardInput(){
	// get the obect(button) that sends the signal
    QPushButton *btn=(QPushButton*)sender();
    // get the sender's name
    QString btnName = btn->objectName();
    // decipher the sender's name and get the row number and column number
    QString rowNum=btnName.mid(1,1);
    QString colNum=btnName.right(1);
    rowInput=rowNum.toInt();
    colInput=colNum.toInt();

    int now1 = chess.getPlayer();
	
	// if player plays at an incorrect position, send a warning message
    if(chess.play(rowInput,colInput)==0){
        QMessageBox::warning(this,tr("Warning"),tr("Not Valid move!"));
        return;
    }

    refresh();
    //if the player change(did not pass)
    if(chess.getPlayer() != now1){
        int now2 = chess.getPlayer();
        while(!chess.isEnd() && now2 == chess.getPlayer()){
            //pause some time to show the result of human player
            QEventLoop eventloop;
            QTimer::singleShot(1000, &eventloop, SLOT(quit()));
            eventloop.exec();

            //AI player plays
            chess.AIplayer();
            refresh();
        }
    }



}


//the function for refresh: when state changes, refresh the chessboard UI
void MainWindow::refresh(){
    QString btnMod=tr("r%1c%2");
    QString black=tr("QPushButton { background-color: rgb(0, 0, 0);border-radius: 3px} QPushButton:hover { background-color: rgb(0, 0, 0); }");
    QString white=tr("QPushButton { background-color: rgb(255, 255, 255);border-radius: 3px} QPushButton:hover { background-color: rgb(255, 255, 255); }");
	
	// set current player's color on main window
    if(chess.getPlayer()==1){
        ui->sign->setStyleSheet(black);
    }else if(chess.getPlayer()==-1){
        ui->sign->setStyleSheet(white);
    }
	
	// redraw chess board based after player's movement
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(chess.board[i][j]==1){
                QString btnN=btnMod.arg(i).arg(j);
                QPushButton *btn=ui->centralWidget->findChild<QPushButton*>(btnN);
                btn->setStyleSheet((black));
            }else if(chess.board[i][j]==-1){
                QString btnN=btnMod.arg(i).arg(j);
                QPushButton *btn=ui->centralWidget->findChild<QPushButton*>(btnN);
                btn->setStyleSheet(white);
            }
        }
    }

	// update the game info on main window
    QString bc;
    QFont font;
    font.setPointSize(14);
    ui->blackcnt->setFont(font);
    QPalette pa;
    ui->blackcnt->setText(bc.setNum(chess.blackCount()));
    ui->whitecnt->setFont(font);
    ui->whitecnt->setText(bc.setNum(chess.whiteCount()));

 	// reset count down and UI
    secCount=60;
    QString s;
    font.setPointSize(15);
    ui->countdown->setFont(font);
    ui->countdown->setText(s.setNum(secCount));
    QPalette red;
    pa.setColor(QPalette::WindowText,Qt::red);

	// if game ends, show the game result
    if(chess.isEnd()){
        if(chess.endResult()>0){
            ui->turn->setText(tr("胜利"));
            ui->sign->setStyleSheet(black);
            ui->sign->setPalette(red);
            timer->stop();
        }else if(chess.endResult()<0){
            ui->turn->setText(tr("胜利"));
            ui->sign->setStyleSheet(white);
            ui->sign->setPalette(red);
            timer->stop();
        }
    }
}

// count down function
void MainWindow::timeSlots(){
    if(secCount>0){
        secCount--;
    }
    QString s;
    QFont font;
    font.setPointSize(15);
    ui->countdown->setFont(font);
    ui->countdown->setText(s.setNum(secCount));
}
