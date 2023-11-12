#pragma once
#include "pieces.h"
#include "board.h"

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