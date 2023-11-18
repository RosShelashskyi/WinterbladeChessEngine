//This file will contain all the functions for testing code;
#pragma once
#include "typesAndMacros.h"
#include "pieces.h"
#include "board.h"
#include "board.c"
#include "moveGenerator.c"

void testKingMoves(){
    setBoards();
    INT board = 0;
    INT wboard = 0;
    INT bboard = 0;
    piece k;
    piece pawn;
    k.position = 0x8000000000000000;
    k.type = KING;
    k.color = WHITE;

    for(int i = 0; i < 64; i++){
        if(i) k.position = k.position >> 1;
        board = k.position;
        wboard = k.position;
        int moveCount = 0;
        INT *moves = generateMoves(&k, board, wboard, bboard, &moveCount);
        INT m = 0;
        for(int i = 0; i < moveCount; i++){
            m = m | moves[i];
        }
        free(moves);
        printf("%lx\n", m);
    }

    // board = board | k.position;
    // wboard = k.position;
    // bboard = 0;

    // int moveCount = 0;
    // INT *moves = generateMoves(&k, board, wboard, bboard, &moveCount);

    // INT m = 0;

    // for(int i = 0; i < moveCount; i++){
    //     printf("%llx\n", moves[i]);
    //     m = m | moves[i];
    // }

    //Linux version
    //printf("%lx\n", m);
    //Mac version
    //printf("%llx\n", m);
}

void testPawnMoves(){
    setBoards();
    INT board = 0;
    INT wboard = 0;
    INT bboard = 0;
    piece pawn;
    pawn.position = 0x0000000020000000;
    pawn.type = PAWN;
    pawn.color = BLACK;

    piece wpawn;
    wpawn.position = pawn.position << 1; 
    wpawn.type = PAWN;
    wpawn.color = WHITE;

    board  = pawn.position | wpawn.position;
    wboard = wpawn.position;
    bboard = pawn.position;

    enPassantePiece = &wpawn;

    int moveCount = 0;
    INT *moves = generateMoves(&pawn, board, wboard, bboard, &moveCount);
    INT m = 0;
    printf("%d\n", moveCount);
    for(int i = 0; i < moveCount; i++){
        printf("%lx\n", moves[i]);    
        m = m | moves[i];
    }
    free(moves);
    printf("%lx\n", m);
}