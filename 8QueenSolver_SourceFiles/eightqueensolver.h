#ifndef EIGHTQUEENSOLVER_H
#define EIGHTQUEENSOLVER_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include "tiles.h"


#include <QMainWindow>

namespace Ui {
class EightQueenSolver;
}

class EightQueenSolver : public QMainWindow
{
    Q_OBJECT

public:
    explicit EightQueenSolver(QWidget *parent = nullptr);
    ~EightQueenSolver();

private slots:


    void resetAllQueen();
    void on_right_clicked();
    bool isValid(tiles board[][8], int row, int col);
    void placeQueens(tiles board[][8], int row);



private:
    Ui::EightQueenSolver *ui;




};

#endif // EIGHTQUEENSOLVER_H
