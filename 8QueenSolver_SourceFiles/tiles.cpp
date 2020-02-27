#include "tiles.h"

tiles::tiles()
{
    hasQueen = false;

}

bool tiles::getQueen(){
    return hasQueen;
}

void tiles::setQueen(bool a){
    hasQueen =a;
}


