#include "../numToPosition.h"   
#include "../moveGenerator.h"
#include "../board.h"
#include "bishop.h"
#include "stdio.h"

void bishopMoveTest(){
    setBoards();
    INT board = 0;
    INT wboard = 0;
    INT bboard = 0;

    piece bishop;
    bishop.position = A8;
    bishop.type = BISHOP;
    bishop.color = WHITE;

    printf("WHITE BISHOP\n");

    for(int i = 0 ; i < 64; i++){
        if(i) bishop.position = bishop.position >> 1;
        board = bishop.position;
        wboard = bishop.position;
        int moveCount = 0;
        INT *moves = generateMoves(&bishop, board, wboard, bboard, &moveCount);
        INT m = 0;
        for(int i = 0; i < moveCount; i++){
            m = m | moves[i];
        }
        char str[73];
        numToPosition(m, str);
        printf("%s\n", str);
    }

    printf("BLACK BISHOP\n");

    bishop.position = A8;
    bishop.color = BLACK;
    wboard = 0;

    for(int i = 0; i < 64; i++){
        if(i) bishop.position = bishop.position >> 1;
        board = bishop.position;
        bboard = bishop.position;
        int moveCount = 0;
        INT *moves = generateMoves(&bishop, board, wboard, bboard, &moveCount);
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

void bishopTakeTest(){
    setBoards();
    INT board = 0;
    INT wboard = 0;
    INT bboard = 0;

    piece bishop;
    bishop.position = E4;
    bishop.type = BISHOP;
    bishop.color = WHITE;

    piece pawn;
    pawn.position = D5;
    pawn.type = PAWN;
    pawn.color = BLACK;

    printf("WHITE BISHOP\n");

    for(int i = 0 ; i < 8; i++){
        switch(i){
            case 0 :
                //do nothing
                break;
            case 1:
                pawn.position = E5;
                break;
            case 2:
                pawn.position = F5;
                break;
            case 3:
                pawn.position = D4;
                break;
            case 4:
                pawn.position = F4;
                break;
            case 5:
                pawn.position = D3;
                break;
            case 6: 
                pawn.position = E3;
                break;
            case 7:
                pawn.position = F3;
                break;
        }
        board = bishop.position | pawn.position;
        wboard = bishop.position;
        bboard = pawn.position;
        int moveCount = 0;
        INT *moves = generateMoves(&bishop, board, wboard, bboard, &moveCount);
        INT m = 0;
        for(int i = 0; i < moveCount; i++){
            m = m | moves[i];
        }
        char str[73];
        numToPosition(m, str);
        printf("%s\n", str);
    }

    printf("BLACK BISHOP\n");

    bishop.color = BLACK;
    pawn.color = WHITE;

   for(int i = 0 ; i < 8; i++){
        switch(i){
            case 0 :
                pawn.position = D5;
                break;
            case 1:
                pawn.position = E5;
                break;
            case 2:
                pawn.position = F5;
                break;
            case 3:
                pawn.position = D4;
                break;
            case 4:
                pawn.position = F4;
                break;
            case 5:
                pawn.position = D3;
                break;
            case 6: 
                pawn.position = E3;
                break;
            case 7:
                pawn.position = F3;
                break;
        }
        board = bishop.position | pawn.position;
        bboard = bishop.position;
        wboard = pawn.position;
        int moveCount = 0;
        INT *moves = generateMoves(&bishop, board, wboard, bboard, &moveCount);
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

void bishopBlockTest(){
    setBoards();
    INT board = 0;
    INT wboard = 0;
    INT bboard = 0;

    piece bishop;
    bishop.position = E4;
    bishop.type = BISHOP;
    bishop.color = WHITE;

    piece pawn;
    pawn.position = D5;
    pawn.type = PAWN;
    pawn.color = WHITE;

    printf("WHITE BISHOP\n");

    for(int i = 0 ; i < 8; i++){
        switch(i){
            case 0 :
                //do nothing
                break;
            case 1:
                pawn.position = E5;
                break;
            case 2:
                pawn.position = F5;
                break;
            case 3:
                pawn.position = D4;
                break;
            case 4:
                pawn.position = F4;
                break;
            case 5:
                pawn.position = D3;
                break;
            case 6: 
                pawn.position = E3;
                break;
            case 7:
                pawn.position = F3;
                break;
        }
        board = bishop.position | pawn.position;
        wboard = board;
        int moveCount = 0;
        INT *moves = generateMoves(&bishop, board, wboard, bboard, &moveCount);
        INT m = 0;
        for(int i = 0; i < moveCount; i++){
            m = m | moves[i];
        }
        char str[73];
        numToPosition(m, str);
        printf("%s\n", str);
    }

    printf("BLACK QUEEN\n");

    bishop.color = BLACK;
    pawn.color = BLACK;
    wboard = 0;

   for(int i = 0 ; i < 8; i++){
        switch(i){
            case 0 :
                pawn.position = D5;
                break;
            case 1:
                pawn.position = E5;
                break;
            case 2:
                pawn.position = F5;
                break;
            case 3:
                pawn.position = D4;
                break;
            case 4:
                pawn.position = F4;
                break;
            case 5:
                pawn.position = D3;
                break;
            case 6: 
                pawn.position = E3;
                break;
            case 7:
                pawn.position = F3;
                break;
        }
        board = bishop.position | pawn.position;
        bboard = board;
        int moveCount = 0;
        INT *moves = generateMoves(&bishop, board, wboard, bboard, &moveCount);
        INT m = 0;
        for(int i = 0; i < moveCount; i++){
            m = m | moves[i];
        }
        char str[73];
        numToPosition(m, str);
        printf("%s\n", str);
    }
    printf("END OF TEST\n");
}