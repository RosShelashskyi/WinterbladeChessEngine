//This file will contain all the functions for testing code;
#include <stdio.h>
#include <stdlib.h>
#include "typesAndMacros.h"
#include "pieces.h"
#include "board.h"
#include "moveGenerator.h"
#include "tests/king.h"
#include "tests/queen.h"
#include "tests/rook.h"
#include "tests/bishop.h"
#include "numToPosition.h"
#include "test.h"

void testKingMoves(){
    kingTakeTest();
}

//full basic test with no other pieces
void testPawnMoves(){
    setBoards();
    INT board = 0;
    INT wboard = 0;
    INT bboard = 0;
    piece pawn;
    piece wpawn;

    pawn.position = 0x0020000000000000;
    pawn.type = PAWN;
    pawn.color = BLACK;

    wpawn.position = 0x0000400000000000;
    wpawn.type = PAWN;
    wpawn.color = WHITE;

    board  = pawn.position | wpawn.position;
    wboard = wpawn.position;
    bboard = pawn.position;

    // for(int i = 0; i < 48; i++){
    //     pawn.position = pawn.position >> 1;
    //     int moveCount = 0;
    //     INT *moves = generateMoves(&pawn, board, wboard, bboard, &moveCount);
    //     INT m = 0;
    //     printf("%d\n", moveCount);
    //     for(int i = 0; i < moveCount; i++){  
    //         m = m | moves[i];
    //     }
    //     free(moves);
    //     printf("%lx\n", m);
    // }

    int moveCount = 0;
    INT *moves = generateMoves(&pawn, board, wboard, bboard, &moveCount);
    printf("%d\n", moveCount);
    for(int i = 0; i < moveCount; i++){
        char str[73];
        numToPosition(moves[i], str);
        printf("%s\n", str);
    }
    free(moves);
}

void testKnightMoves(){
    // setBoards();
    // INT board = 0;
    // INT wboard = 0;
    // INT bboard = 0;
    // piece knight;
    // knight.position = 0x8000000000000000;
    // knight.color = WHITE;
    // knight.type = KNIGHT;

    // board = knight.position;
    // wboard = knight.position;

    // // int moveCount = 0;
    // //     INT *moves = generateMoves(&knight, board, wboard, bboard, &moveCount);
    // //     INT m = 0;
    // //     printf("Move count: %d\n", moveCount);
    // //     for(int i = 0; i < moveCount; i++){
    // //         printf("move[%d]: %lx\n", i, moves[i]);
    // //         m = m | moves[i];
    // //     }
    // //     free(moves);
    // //     printf("%lx\n", m);

    // for(int i = 0; i < 64; i++){
    //     if(i) knight.position = knight.position >> 1;
    //     board = knight.position;
    //     wboard = knight.position;
    //     int moveCount = 0;
    //     INT *moves = generateMoves(&knight, board, wboard, bboard, &moveCount);
    //     INT m = 0;
    //     printf("Move count: %d\n", moveCount);
    //     for(int i = 0; i < moveCount; i++){
    //         //printf("move[%d]: %lx\n", i, moves[i]);
    //         m = m | moves[i];
    //     }
    //     free(moves);
    //     printf("%lx\n\n\n", m);
    // }
}

void testRookMoves(){
    rookBlockTest();
}

void testBishopMoves(){
    bishopBlockTest();
}

void testQueenMoves(){
    queenTakeTest();
}

