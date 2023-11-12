#pragma once
#include "pieces.h"
#include "board.h"
#include "typesAndMacros.h"

void setupGame(){
    setWhitePieces();
    setBlackPieces();
    setBoards();
}

int main(){
    setupGame();
    return 0;
}