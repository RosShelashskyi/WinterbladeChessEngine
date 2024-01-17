#include "pieces.h"
#include "board.h"
#include "typesAndMacros.h"
#include "test.c"
#include <stdio.h>



int main(){
    //setupGame();
    // char str[73];
    // numToPosition(0x0010000000000000, str);
    // printf("%s\n", str);
    testKingMoves();
    return 0;
}

// void setupGame(){
//     setWhitePieces();
//     setBlackPieces();
//     setBoards();
// }