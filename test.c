//This file will contain all the functions for testing code;
#pragma once
#include "typesAndMacros.h"
#include "pieces.h"
#include "board.h"
#include "moveGenerator.c"

void testKingMoves(){
    INT board = 0;
    INT wboard = 0;
    INT bboard = 0;
    piece k;
    k.position = 0x0000000010000000;
    k.type = KING;
    k.color = WHITE;
    board = board | k.position;
    wboard = board | k.position;

    INT *moves = generateMoves(&k, board, wboard, bboard);

    INT m = 0;

    for(int i = 0; i < 8; i++){
        m = m | moves[i];
    }

    printf("%lx\n", m);
}