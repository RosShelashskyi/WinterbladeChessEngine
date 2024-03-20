#include "../numToPosition.h"   
#include "../moveGenerator.h"
#include "../board.h"
#include "queen.h"
#include "stdio.h"

//full test of the queen's move on every square of the board
void queenMoveTest(){
    setBoards();
    INT board = 0;
    INT wboard = 0;
    INT bboard = 0;

    piece queen;
    queen.position = A8;
    queen.type = QUEEN;
    queen.color = WHITE;

    printf("WHITE QUEEN\n");

    for(int i = 0 ; i < 64; i++){
        if(i) queen.position = queen.position >> 1;
        board = queen.position;
        wboard = queen.position;
        int moveCount = 0;
        INT *moves = generateMoves(&queen, board, wboard, bboard, &moveCount);
        INT m = 0;
        for(int i = 0; i < moveCount; i++){
            m = m | moves[i];
        }
        char str[73];
        numToPosition(m, str);
        printf("%s\n", str);
    }

    printf("BLACK QUEEN\n");

    queen.position = A8;
    queen.color = BLACK;
    wboard = 0;

    for(int i = 0; i < 64; i++){
        if(i) queen.position = queen.position >> 1;
        board = queen.position;
        bboard = queen.position;
        int moveCount = 0;
        INT *moves = generateMoves(&queen, board, wboard, bboard, &moveCount);
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

//testing the queen being blocked by friendly pieces
void queenBlockTest(){
    setBoards();
    INT board = 0;
    INT wboard = 0;
    INT bboard = 0;

    piece queen;
    queen.position = E4;
    queen.type = QUEEN;
    queen.color = WHITE;

    piece pawn;
    pawn.position = D5;
    pawn.type = PAWN;
    pawn.color = WHITE;

    printf("WHITE QUEEN\n");

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
        board = queen.position | pawn.position;
        wboard = board;
        int moveCount = 0;
        INT *moves = generateMoves(&queen, board, wboard, bboard, &moveCount);
        INT m = 0;
        for(int i = 0; i < moveCount; i++){
            m = m | moves[i];
        }
        char str[73];
        numToPosition(m, str);
        printf("%s\n", str);
    }

    printf("BLACK QUEEN\n");

    queen.color = BLACK;
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
        board = queen.position | pawn.position;
        bboard = board;
        int moveCount = 0;
        INT *moves = generateMoves(&queen, board, wboard, bboard, &moveCount);
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

//testing the queen being able to capture enemy pieces
void queenTakeTest(){
    setBoards();
    INT board = 0;
    INT wboard = 0;
    INT bboard = 0;

    piece queen;
    queen.position = E4;
    queen.type = QUEEN;
    queen.color = WHITE;

    piece pawn;
    pawn.position = D5;
    pawn.type = PAWN;
    pawn.color = BLACK;

    printf("WHITE QUEEN\n");

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
        board = queen.position | pawn.position;
        wboard = queen.position;
        bboard = pawn.position;
        int moveCount = 0;
        INT *moves = generateMoves(&queen, board, wboard, bboard, &moveCount);
        INT m = 0;
        for(int i = 0; i < moveCount; i++){
            m = m | moves[i];
        }
        char str[73];
        numToPosition(m, str);
        printf("%s\n", str);
    }

    printf("BLACK QUEEN\n");

    queen.color = BLACK;
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
        board = queen.position | pawn.position;
        bboard = queen.position;
        wboard = pawn.position;
        int moveCount = 0;
        INT *moves = generateMoves(&queen, board, wboard, bboard, &moveCount);
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