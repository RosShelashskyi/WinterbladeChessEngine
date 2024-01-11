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
        printf("%lx\n", moves[i]);
    }
    free(moves);
}

void testKnightMoves(){
    setBoards();
    INT board = 0;
    INT wboard = 0;
    INT bboard = 0;
    piece knight;
    knight.position = 0x8000000000000000;
    knight.color = WHITE;
    knight.type = KNIGHT;

    board = knight.position;
    wboard = knight.position;

    // int moveCount = 0;
    //     INT *moves = generateMoves(&knight, board, wboard, bboard, &moveCount);
    //     INT m = 0;
    //     printf("Move count: %d\n", moveCount);
    //     for(int i = 0; i < moveCount; i++){
    //         printf("move[%d]: %lx\n", i, moves[i]);
    //         m = m | moves[i];
    //     }
    //     free(moves);
    //     printf("%lx\n", m);

    for(int i = 0; i < 64; i++){
        if(i) knight.position = knight.position >> 1;
        board = knight.position;
        wboard = knight.position;
        int moveCount = 0;
        INT *moves = generateMoves(&knight, board, wboard, bboard, &moveCount);
        INT m = 0;
        printf("Move count: %d\n", moveCount);
        for(int i = 0; i < moveCount; i++){
            //printf("move[%d]: %lx\n", i, moves[i]);
            m = m | moves[i];
        }
        free(moves);
        printf("%lx\n\n\n", m);
    }


}

void testRookMoves(){
    setBoards();
    INT board = 0;
    INT wboard = 0;
    INT bboard = 0;
    piece rook;
    rook.position = 0x8000000000000000;
    rook.type = ROOK;
    rook.color = WHITE;

    piece pawn;
    pawn.position = 0x0000800000000000;
    pawn.type = PAWN;
    pawn.color = BLACK;

    board = rook.position | pawn.position;
    wboard = rook.position;
    bboard = pawn.position;

    
    // for(int i = 0; i < 64; i++){
    //     if(i) rook.position = rook.position >> 1;
    //     board = rook.position;
    //     wboard = rook.position;
    //     int moveCount = 0;
    //     INT *moves = generateMoves(&rook, board, wboard, bboard, &moveCount);
    //     INT m = 0;
    //     printf("Move count: %d\n", moveCount);
    //     for(int i = 0; i < moveCount; i++){
    //         //printf("move[%d]: %lx\n", i, moves[i]);
    //         m = m | moves[i];
    //     }
    //     free(moves);
    //     printf("%lx\n\n\n", m);
    // }

    int moveCount = 0;
    INT *moves = generateMoves(&rook, board, wboard, bboard, &moveCount);
    INT m = 0;
    if(moves == 0) return;
    printf("Move count: %d\n", moveCount);
    for(int i = 0; i< moveCount; i++){
        //printf("move[%d]: %lx\n", i, moves[i]);
        m = m | moves[i];
    }
    free(moves);
    printf("%lx\n", m);
}

void testBishopMoves(){
    setBoards();
    INT board = 0;
    INT wboard = 0;
    INT bboard = 0;
    piece bishop;
    bishop.position = 0x0000200000000000;
    bishop.type = BISHOP;
    bishop.color = WHITE;

    piece pawn;
    pawn.position = 0x0000001000000000;
    pawn.type = PAWN;
    pawn.color = BLACK;

    board = bishop.position | pawn.position;
    wboard = bishop.position;
    bboard = pawn.position;

    
    // for(int i = 0; i < 64; i++){
    //     if(i) bishop.position = bishop.position >> 1;
    //     board = bishop.position;
    //     wboard = bishop.position;
    //     int moveCount = 0;
    //     INT *moves = generateMoves(&bishop, board, wboard, bboard, &moveCount);
    //     INT m = 0;
    //     printf("Move count: %d\n", moveCount);
    //     for(int i = 0; i < moveCount; i++){
    //         //printf("move[%d]: %lx\n", i, moves[i]);
    //         m = m | moves[i];
    //     }
    //     free(moves);
    //     printf("%lx\n\n", m);
    // }

    int moveCount = 0;
    INT *moves = generateMoves(&bishop, board, wboard, bboard, &moveCount);
    INT m = 0;
    if(moves == 0) return;
    printf("Move count: %d\n", moveCount);
    for(int i = 0; i< moveCount; i++){
        //printf("move[%d]: %lx\n", i, moves[i]);
        m = m | moves[i];
    }
    free(moves);
    printf("%lx\n", m);
}

void testQueenMoves(){
        setBoards();
    INT board = 0;
    INT wboard = 0;
    INT bboard = 0;
    piece queen;
    queen.position = 0x0000100000000000;
    queen.type = QUEEN;
    queen.color = WHITE;

    piece pawn;
    pawn.position = 0x0000001000000000;
    pawn.type = PAWN;
    pawn.color = BLACK;

    board = queen.position | pawn.position;
    wboard = queen.position;
    bboard = pawn.position;

    // board = queen.position | pawn.position;
    // wboard = queen.position | pawn.position;
    // bboard = 0;


    
    // for(int i = 0; i < 64; i++){
    //     if(i) queen.position = queen.position >> 1;
    //     board = queen.position;
    //     wboard = queen.position;
    //     int moveCount = 0;
    //     INT *moves = generateMoves(&queen, board, wboard, bboard, &moveCount);
    //     INT m = 0;
    //     printf("Move count: %d\n", moveCount);
    //     for(int i = 0; i < moveCount; i++){
    //         //printf("move[%d]: %lx\n", i, moves[i]);
    //         m = m | moves[i];
    //     }
    //     free(moves);
    //     printf("%lx\n\n", m);
    // }

    int moveCount = 0;
    INT *moves = generateMoves(&queen, board, wboard, bboard, &moveCount);
    INT m = 0;
    if(moves == 0) return;
    printf("Move count: %d\n", moveCount);
    for(int i = 0; i< moveCount; i++){
        //printf("move[%d]: %lx\n", i, moves[i]);
        m = m | moves[i];
    }
    free(moves);
    printf("%lx\n", m);
}

//function for transforming a position into a human readable chess board format
void numToPosition(INT pos, char *str){
    //64 bits, 8 new lines, and one string terminator = 73 chars
    char result[73];
    //iterator for the string
    int strI = 0;
    //create a mask to shift right each iteration
    INT mask = 0x8000000000000000;
    char c;
    for(int i = 0; i < 64; i++){
        //get the bit and add it to the result
        if(pos & (mask >> i)){
            c = '1';
        }else{
            c = '0';
        }
        str[strI] = c;
        strI++;
        //if the rank should end, add a newline
        if((i + 1) % 8 == 0){
            str[strI] = '\n';
            strI++;
        }
    }
    //add a string terminator
    str[strI] = '\0';
}