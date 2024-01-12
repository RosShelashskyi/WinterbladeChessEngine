#pragma once
#include "numToPosition.c"
#include "moveGenerator.h"

//full test of the king's moves on every square of the board
void moveTest(){
    setBoards();
    INT board = 0;
    INT wboard = 0;
    INT bboard = 0;

    piece king;
    king.position = 0x800000000000000;
    king.type = KING;
    king.color = WHITE;

    printf("WHITE KING\n");

    for(int i = 0; i < 64; i++){
        if(i) king.position = king.position >> 1;
        board = king.position;
        wboard = king.position;
        int moveCount = 0;
        INT *moves = generateMoves(&king, board, wboard, bboard, &moveCount);
        INT m = 0;
        for(int i = 0; i < moveCount; i++){
            char str[73];
            numToPosition(moves[i], str);
            printf("%s\n", str);
        }
    }

    printf("BLACK KING\n");

    king.position = 0x8000000000000000;
    king.color = BLACK;
    wboard = 0;

    for(int i = 0; i < 64; i++){
        if(i) king.position = king.position >> 1;
        board = king.position;
        bboard = king.position;
        int moveCount = 0;
        INT *moves = generateMoves(&king, board, wboard, bboard, &moveCount);
        INT m = 0;
        for(int i = 0; i < moveCount; i++){
            char str[73];
            numToPosition(moves[i], str);
            printf("%s\n", str);
        }
    }

    printf("END OF TEST");
}

//testing the king being blocked by friendly pieces

//testing the king being able to capture enemy pieces

//testing castling