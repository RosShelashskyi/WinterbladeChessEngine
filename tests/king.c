#pragma once
#include "../numToPosition.c"
#include "../moveGenerator.h"

//full test of the king's moves on every square of the board
void moveTest(){
    setBoards();
    INT board = 0;
    INT wboard = 0;
    INT bboard = 0;

    piece king;
    king.position = 0x8000000000000000;
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
            m = m | moves[i];
        }
        char str[73];
        numToPosition(m, str);
        printf("%s\n", str);
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
            m = m | moves[i];
        }
        char str[73];
        numToPosition(m, str);
        printf("%s\n", str);
    }

    printf("END OF TEST");
}

//testing the king being blocked by friendly pieces
void blockTest(){
    setBoards();
    INT board = 0;
    INT wboard = 0;
    INT bboard = 0;

    piece king;
    king.position = 0x0000080000000000;
    king.type = KING;
    king.color = WHITE;

    piece pawn;
    pawn.position = 0x0010000000000000;
    pawn.type = PAWN;
    pawn.color = WHITE;

    printf("WHITE KING\n");
    
    for(int i = 0; i < 8; i++){
        switch(i){
            case 0 :
                //do nothing
                break;
            case 1:
                pawn.position = 0x0008000000000000;
                break;
            case 2:
                pawn.position = 0x0004000000000000;
                break;
            case 3:
                pawn.position = 0x0000100000000000;
                break;
            case 4:
                pawn.position = 0x0000040000000000;
                break;
            case 5:
                pawn.position = 0x0000001000000000;
                break;
            case 6: 
                pawn.position = 0x0000000800000000;
                break;
            case 7:
                pawn.position = 0x0000000400000000;
                break;
        }
        board = king.position | pawn.position;
        wboard = board;
        int moveCount = 0;
        INT *moves = generateMoves(&king, board, wboard, bboard, &moveCount);
        INT m = 0;
        for(int i = 0; i < moveCount; i++){
            m = m | moves[i];
        }
        char str[73];
        numToPosition(m, str);
        printf("%s\n", str);
    }


    printf("BLACK KING\n");


    king.color = BLACK;

    pawn.position = 0x0010000000000000;
    pawn.color = BLACK;
    wboard = 0;

    for(int i = 0; i < 8; i++){
        switch(i){
            case 0 :
                //do nothing
                break;
            case 1:
                pawn.position = 0x0008000000000000;
                break;
            case 2:
                pawn.position = 0x0004000000000000;
                break;
            case 3:
                pawn.position = 0x0000100000000000;
                break;
            case 4:
                pawn.position = 0x0000040000000000;
                break;
            case 5:
                pawn.position = 0x0000001000000000;
                break;
            case 6: 
                pawn.position = 0x0000000800000000;
                break;
            case 7:
                pawn.position = 0x0000000400000000;
                break;
        }
        board = king.position | pawn.position;
        bboard = board;
        int moveCount = 0;
        INT *moves = generateMoves(&king, board, wboard, bboard, &moveCount);
        INT m = 0;
        for(int i = 0; i < moveCount; i++){
            m = m | moves[i];
        }
        char str[73];
        numToPosition(m, str);
        printf("%s\n", str);
    }
}

//testing the king being able to capture enemy pieces
void takeTest(){
    setBoards();
    INT board = 0;
    INT wboard = 0;
    INT bboard = 0;

    piece king;
    king.position = 0x0000080000000000;
    king.type = KING;
    king.color = WHITE;

    piece pawn;
    pawn.position = 0x0010000000000000;
    pawn.type = PAWN;
    pawn.color = BLACK;

    printf("WHITE KING\n");
    
    for(int i = 0; i < 8; i++){
        switch(i){
            case 0 :
                //do nothing
                break;
            case 1:
                pawn.position = 0x0008000000000000;
                break;
            case 2:
                pawn.position = 0x0004000000000000;
                break;
            case 3:
                pawn.position = 0x0000100000000000;
                break;
            case 4:
                pawn.position = 0x0000040000000000;
                break;
            case 5:
                pawn.position = 0x0000001000000000;
                break;
            case 6: 
                pawn.position = 0x0000000800000000;
                break;
            case 7:
                pawn.position = 0x0000000400000000;
                break;
        }
        board = king.position | pawn.position;
        wboard = king.position;
        bboard = pawn.position;
        int moveCount = 0;
        INT *moves = generateMoves(&king, board, wboard, bboard, &moveCount);
        INT m = 0;
        for(int i = 0; i < moveCount; i++){
            m = m | moves[i];
        }
        char str[73];
        numToPosition(m, str);
        printf("%s\n", str);
    }

    printf("BLACK KING\n");


    king.color = BLACK;

    pawn.position = 0x0010000000000000;
    pawn.color = WHITE;
    bboard = 0;
    wboard = 0;
    board = 0;

    for(int i = 0; i < 8; i++){
        switch(i){
            case 0 :
                //do nothing
                break;
            case 1:
                pawn.position = 0x0008000000000000;
                break;
            case 2:
                pawn.position = 0x0004000000000000;
                break;
            case 3:
                pawn.position = 0x0000100000000000;
                break;
            case 4:
                pawn.position = 0x0000040000000000;
                break;
            case 5:
                pawn.position = 0x0000001000000000;
                break;
            case 6: 
                pawn.position = 0x0000000800000000;
                break;
            case 7:
                pawn.position = 0x0000000400000000;
                break;
        }
        board = king.position | pawn.position;
        bboard = king.position;
        wboard = pawn.position;
        int moveCount = 0;
        INT *moves = generateMoves(&king, board, wboard, bboard, &moveCount);
        INT m = 0;
        for(int i = 0; i < moveCount; i++){
            m = m | moves[i];
        }
        char str[73];
        numToPosition(m, str);
        printf("%s\n", str);
    }
}

//testing castling