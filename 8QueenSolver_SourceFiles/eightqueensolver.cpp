
#include "eightqueensolver.h"
#include "ui_eightqueensolver.h"
#include <QtCore>
#include <QApplication>





EightQueenSolver::EightQueenSolver(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EightQueenSolver)
{
    ui->setupUi(this);
    ui->counter->display(0);
    //An array of Queens

}

//Number of solutions
int solution = 0;

//Boolean to continue
boolean resume = false;

//Number of Queens placed
int queenCounter =0;

int xScale =65;
int yScale = 63;

EightQueenSolver::~EightQueenSolver()
{
    delete ui;
}

void EightQueenSolver::resetAllQueen(){
   ui->one->move(1010,210);
   ui->two->move(1080,210);
   ui->three->move(1140,210);
   ui->four->move(1200,210);
   ui->five->move(1010,280);
   ui->six->move(1080,280);
   ui->sevon->move(1140,280);
   ui->eight->move(1200,280);

}

void EightQueenSolver::on_right_clicked()
{

    solution =0;
    tiles board[8][8];
    placeQueens(board, 0);


    }



bool EightQueenSolver::isValid(tiles board[][8], int row, int col) {

    // Checks if two Queens share the same column
    for (int x = 0; x < row; x++)
        if (board[x][col].getQueen()) {
            return false;

        }

    // Checks if two Queens share the same diagonals (up & left)
    for (int x = row, y = col; x >= 0 && y >= 0; x--, y--)
        if (board[x][y].getQueen()) {
            return false;
        }

    // Checks if two Queens share the same diagonals (up & right)
    for (int x = row, y = col; x >= 0 && y <8; x--, y++)
        if (board[x][y].getQueen()) {
            return false;
        }

    // If all of the 3-statements above pass, then the board is valid
    return true;
}





void EightQueenSolver::placeQueens(tiles board[][8], int row) {

    if (row == 8) {
        //Create a 2D array to translate the result into ints
        int tempCount =0;
         solution++;
         ui->counter->display(solution);
        resume = false;
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {

                if (board[x][y].getQueen()) {

                    if(tempCount==0){
                        ui->one->move(160+xScale*x,130+yScale*y);
                    }
                    else if(tempCount==1){
                         ui->two->move(160+xScale*x,130+yScale*y);
                    }
                    else if(tempCount==2){
                         ui->three->move(160+xScale*x,130+yScale*y);
                    }
                    else if(tempCount ==3){
                         ui->four->move(160+xScale*x,130+yScale*y);
                    }
                    else if(tempCount ==4){
                         ui->five->move(160+xScale*x,130+yScale*y);
                    }
                    else if(tempCount ==5){
                         ui->six->move(160+xScale*x,130+yScale*y);
                    }
                    else if (tempCount ==6){
                         ui->sevon->move(160+xScale*x,130+yScale*y);
                    }
                    else if(tempCount ==7){
                         ui->eight->move(160+xScale*x,130+yScale*y);
                    }

                    tempCount++;
                //    cout << "[Q]";


                } else {
                    //Do nothing

                }

            }
        }


   //Wait
    //Force the UI to display the new board
    qApp->processEvents();
    //Brief pause
    Sleep(250);


    while(!ui->pushButton->isDown()){
        qApp->processEvents();
        if(ui->checkBox->isChecked()){
             ui->pushButton->setDown(true);
        }
    }

    ui->pushButton->setDown(false);
    qApp->processEvents();
    Sleep(100);








    }

    // Place a Queen on each tile in the row
    // If the move is valid we recur to find other possible combinations

    for (int x = 0; x < 8; x++) {
        // if no two queens threaten each other
        if (isValid(board, row, x)) {
            // place queen on current square
            board[row][x].setQueen(true);

            // Calls placeQueens for the next row
            placeQueens(board, row + 1);

            // Backtrack and remove the Queen from the tile
            board[row][x].setQueen(false);
        }
    }
}








