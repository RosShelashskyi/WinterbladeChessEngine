#pragma once
#include "pieces.h"
#include "board.h"
#include "typesAndMacros.h"

int* generateMoves(piece *p, INT board, INT wboard, INT bboard){
    switch(p->type){
        case KING:
            return generateKingMoves(p, board, wboard, bboard);
        case QUEEN:
            return generateQueenMoves(p, board, wboard, bboard);
        case ROOK:
            return generateRookMoves(p, board, wboard, bboard);
        case KNIGHT:
            return generateKnightMoves(p, board, wboard, bboard);
        case BISHOP:
            return generateBishopMoves(p, board, wboard, bboard);
        case PAWN:
            return generatePawnMoves(p, board, wboard, bboard);
        default:
            printf("Can't generate moves: unknown piece type");
            return 0;
    }
}

int* generateKingMoves(piece *p, INT board, INT wboard, INT bboard){
    int *moves = (int*)malloc(8 * sizeof(INT)); //allocate space for an array of possible moves
    INT pos = p->position;
    if(p->color = WHITE){                       //algorithm for the white king
        int i = 0;                              //for incrementing the array
        
    }else{

    }
}

int* generateQueenMoves(piece *p, INT board, INT wboard, INT bboard){

}

int* generateRookMoves(piece *p, INT board, INT wboard, INT bboard){

}

int* generateKnightMoves(piece *p, INT board, INT wboard, INT bboard){

}

int* generateBishopMoves(piece *p, INT board, INT wboard, INT bboard){

}

int* generatePawnMoves(piece *p, INT board, INT wboard, INT bboard){

}

int isKingUnderCheck(piece *p){
    return 0;
}