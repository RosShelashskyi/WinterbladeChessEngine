#include "../numToPosition.h"   
#include "../moveGenerator.h"
#include "../board.h"
#include "queen.h"
#include "stdio.h"

void rookMoveTest(){
    setBoards();
    INT board = 0;
    INT wboard = 0;
    INT bboard = 0;
    piece rook;
    rook.position = A8;
    rook.type = ROOK;
    rook.color = WHITE;

    board = rook.position;
    wboard = rook.position;

    printf("WHITE ROOK\n");

    for(int i = 0; i < 64; i++){
        if(i) rook.position = rook.position >> 1;
        board = rook.position;
        wboard = rook.position;
        int moveCount = 0;
        INT *moves = generateMoves(&rook, board, wboard, bboard, &moveCount);
        INT m = 0;
        for(int i = 0; i < moveCount; i++){
            m = m | moves[i];
        }
        char str[73];
        numToPosition(m, str);
        printf("%s\n", str);
    }

    printf("BLACK ROOK\n");

    rook.position = A8;
    rook.color = BLACK;
    wboard = 0;

    for(int i = 0; i < 64; i++){
        if(i) rook.position = rook.position >> 1;
        board = rook.position;
        bboard = rook.position;
        int moveCount = 0;
        INT *moves = generateMoves(&rook, board, wboard, bboard, &moveCount);
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

void rookBlockTest(){
    setBoards();
    INT board = 0;
    INT wboard = 0;
    INT bboard = 0;

    piece rook;
    rook.position = E4;
    rook.type = ROOK;
    rook.color = WHITE;

    piece pawn;
    pawn.position = D5;
    pawn.type = PAWN;
    pawn.color = WHITE;

    printf("WHITE ROOK\n");

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
                //bug here?
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
        board = rook.position | pawn.position;
        wboard = board;
        int moveCount = 0;
        INT *moves = generateMoves(&rook, board, wboard, bboard, &moveCount);
        INT m = 0;
        for(int i = 0; i < moveCount; i++){
            m = m | moves[i];
        }
        char str[73];
        numToPosition(m, str);
        printf("%s\n", str);
    }

    printf("BLACK ROOK\n");

    rook.color = BLACK;
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
        board = rook.position | pawn.position;
        bboard = board;
        int moveCount = 0;
        INT *moves = generateMoves(&rook, board, wboard, bboard, &moveCount);
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

void rookTakeTest(){
    setBoards();
    INT board = 0;
    INT wboard = 0;
    INT bboard = 0;

    piece rook;
    rook.position = E4;
    rook.type = ROOK;
    rook.color = WHITE;

    piece pawn;
    pawn.position = D5;
    pawn.type = PAWN;
    pawn.color = BLACK;

    printf("WHITE ROOK\n");

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
        board = rook.position | pawn.position;
        wboard = rook.position;
        bboard = pawn.position;
        int moveCount = 0;
        INT *moves = generateMoves(&rook, board, wboard, bboard, &moveCount);
        INT m = 0;
        for(int i = 0; i < moveCount; i++){
            m = m | moves[i];
        }
        char str[73];
        numToPosition(m, str);
        printf("%s\n", str);
    }

    printf("BLACK ROOK\n");

    rook.color = BLACK;
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
        board = rook.position | pawn.position;
        bboard = rook.position;
        wboard = pawn.position;
        int moveCount = 0;
        INT *moves = generateMoves(&rook, board, wboard, bboard, &moveCount);
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