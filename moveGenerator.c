#pragma once
#include "moveGenerator.h"
#include <stdio.h>
#include <stdlib.h>

INT* generateMoves(piece *p, INT board, INT wboard, INT bboard, int *moveCount){
    switch(p->type){
        case KING:
            return generateKingMoves(p, board, wboard, bboard, moveCount);
        case QUEEN:
            return generateQueenMoves(p, board, wboard, bboard, moveCount);
        case ROOK:
            return generateRookMoves(p, board, wboard, bboard, moveCount);
        case KNIGHT:
            return generateKnightMoves(p, board, wboard, bboard, moveCount);
        case BISHOP:
            return generateBishopMoves(p, board, wboard, bboard, moveCount);
        case PAWN:
            return generatePawnMoves(p, board, wboard, bboard, moveCount);
        default:
            printf("Can't generate moves: unknown piece type");
            return 0;
    }
}

INT* generateKingMoves(piece *p, INT board, INT wboard, INT bboard, int *moveCount){
    INT *moves = (INT*)malloc(8 * sizeof(INT));         //allocate space for an array of possible moves
    INT pos = p->position;
    int i = 0;                                          //for incrementing the array
    //generate NW, N, and NE moves
    if(!(pos & rank8)){                                 //if piece is not on rank 8

        //NW move
        if(!(pos & afile)){                             //if piece is not on the a file
            INT npos = pos << 9;                        //create new position by shifting
            i = calculateKingMove(p, board, wboard, bboard, npos, moves, i, moveCount);
        }

        //N move
        INT npos = pos << 8;                           //N move position
        i = calculateKingMove(p, board, wboard, bboard, npos, moves, i, moveCount);

        //NE move
        if(!(pos & hfile)){
            INT npos = pos << 7;                        //NE move position
            i = calculateKingMove(p, board, wboard, bboard, npos, moves, i, moveCount);
        }
    }

    //generate W move
    if(!(pos & afile)){
        INT npos = pos << 1;                            //W move position
        i = calculateKingMove(p, board, wboard, bboard, npos, moves, i, moveCount);
    }

    //generate E move
    if(!(pos & hfile)){
        INT npos = pos >> 1;                             //E move position
        i = calculateKingMove(p, board, wboard, bboard, npos, moves, i, moveCount);
    }

    //generate SW, S, and SE moves
    if(!(pos & rank1)){
        //SW move
        if(!(pos & afile)){
            INT npos = pos >> 7;                        //SW move position
            i = calculateKingMove(p, board, wboard, bboard, npos, moves, i, moveCount);
        }

        //S move
        INT npos = pos >> 8;                            //S move position
        i = calculateKingMove(p, board, wboard, bboard, npos, moves, i, moveCount);

        //SE move
        if(!(pos & hfile)){
            INT npos = pos >> 9;                        //SE move position
            i = calculateKingMove(p, board, wboard, bboard, npos, moves, i, moveCount);
        }
    }

    /*
    Since there is no guarantee that the algorithm will add 8 moves to the array,
    it is quite inefficient to leave all the free memory allocated.
    So instead, let's create a new array of size i + 1 and put all the values in it.
    That way we're only using as much memory as we need. 
    */
    *moveCount = i;
    //printf("i: %d, moveCount: %d\n", i, *moveCount);

    INT *possibleMoves = (INT*)malloc((*moveCount) * sizeof(INT));
    for(int j = 0; j < i; j++){
        if(moves[j] != 0){
            //printf("%lx\n", moves[j]);
            possibleMoves[j] = moves[j];
        }else{
            *moveCount = *moveCount - 1;
        }
    }

    //printf("%d\n", *moveCount);

    free(moves);

    return possibleMoves;
}

int calculateKingMove(piece *p, INT board, INT wboard, INT bboard, INT npos, INT *moves, int i, int *moveCount){
    
    if(p->color == WHITE){
        //algorithm for white king
        if(!(npos & wboard)){                           //check for blockers
            INT nboard = (board ^ p->position) | npos;  //create the new board with new position
            INT nwboard = nboard ^ bboard;              //create the new white board with new position
            //if the new move doesn't put the king in check, add it to the possible moves
            if(!isKingInCheck(nboard, nwboard, bboard, WHITE)){
                moves[i] = npos;
                //printf("Pushing move %lx to %d\n", npos, i);
                i++;
            }
        }
    }else{
        if(!(npos & bboard)){
            INT nboard = (board ^ p->position) | npos;          //create the new board with new position
            INT nbboard = nboard ^ wboard;                      //create the new black board with new position
            //if the new move doesn't put the king in check, add it to the possible moves
            if(!isKingInCheck(nboard, wboard, nbboard, BLACK)){
                moves[i] = npos;
                i++;
            }
        }
    }
    return i;

    // if((p->color == WHITE && !(npos & wboard)) || p->color == BLACK && !(npos & bboard)){  
    //     INT nboard = (board ^ p->position) | npos;          //create the new board with new position
    //     if(p->color == WHITE){
    //         //algorithm for white king                      
    //         INT nwboard = nboard ^ bboard;          //create the new white board with new position
    //         //if the new move doesn't put the king in check, add it to the possible moves
    //         if(!isKingInCheck(nboard, nwboard, bboard, WHITE)){
    //             moves[i] = npos;
    //             i++;
    //             return i;
    //         }
    //     }else{
    //         //algorithm for black king
    //         INT nbboard = nboard ^ wboard;
    //         //if the new move doesn't put the king in check, add it to the possible moves
    //         if(!isKingInCheck(nboard, wboard, nbboard, BLACK)){
    //             moves[i] = npos;
    //             return i;
    //         }
    //     }
    // }
    // return i;
}


INT* generateQueenMoves(piece *p, INT board, INT wboard, INT bboard, int *moveCount){
    return 0;
}

INT* generateRookMoves(piece *p, INT board, INT wboard, INT bboard, int *moveCount){
    return 0;
}

INT* generateKnightMoves(piece *p, INT board, INT wboard, INT bboard, int *moveCount){
    return 0;
}

INT* generateBishopMoves(piece *p, INT board, INT wboard, INT bboard, int *moveCount){
    return 0;
}

INT* generatePawnMoves(piece *p, INT board, INT wboard, INT bboard, int *moveCount){
    return 0;
}

int isKingInCheck(INT board, INT wboard, INT bboard, INT color){
    return 0;
}