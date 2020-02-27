#include "eightqueensolver.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EightQueenSolver w;

    w.show();

    return a.exec();
}

