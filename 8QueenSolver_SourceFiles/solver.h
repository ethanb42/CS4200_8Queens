#ifndef SOLVER_H
#define SOLVER_H
#include <tiles.h>


class solver
{

public:

    int counter =1;
    solver();
    bool isValid(tiles board[][8], int row, int col);
    void placeQueens(tiles board[][8], int row);

};

#endif // SOLVER_H
