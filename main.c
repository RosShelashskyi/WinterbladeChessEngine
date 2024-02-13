#include "pieces.h"
#include "board.h"
#include "typesAndMacros.h"
#include "test.h"
#include <stdio.h>



int main(){
    //setupGame();
    // char str[73];
    // numToPosition(0x0010000000000000, str);
    // printf("%s\n", str);
    testRookMoves();
    return 0;
}

// void setupGame(){
//     setWhitePieces();
//     setBlackPieces();
//     setBoards();
// }