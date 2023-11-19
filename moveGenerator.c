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
    int balancer = 0;
    //printf("i: %d, moveCount: %d\n", i, *moveCount);
    if(*moveCount != 0){
        INT *possibleMoves = (INT*)malloc((*moveCount) * sizeof(INT));
        for(int j = 0; j < i; j++){
            if(moves[j] != 0){
                //printf("%lx\n", moves[j]);
                possibleMoves[j - balancer] = moves[j];
            }else{
                *moveCount = *moveCount - 1;
                balancer++;
            }
        }
        //printf("%d\n", *moveCount);

        free(moves);

        return possibleMoves;
    }else{
        free(moves);
        return 0;
    }
    

    
}

int calculateKingMove(piece *p, INT board, INT wboard, INT bboard, INT npos, INT *moves, int i, int *moveCount){
    
    if(p->color == WHITE){
        //algorithm for white king
        if(!(npos & wboard)){                           //check for blockers
            INT nboard = (board & ~p->position) | npos;  //create the new board with new position
            INT nwboard = (wboard & ~p->position) | npos;//create the new white board with new position
            //if the new move doesn't put the king in check, add it to the possible moves
            if(!isKingInCheck(nboard, nwboard, bboard, WHITE)){
                moves[i] = npos;
                //printf("Pushing move %lx to %d\n", npos, i);
                i++;
            }
        }
    }else{
        if(!(npos & bboard)){
            INT nboard = (board & ~p->position) | npos;          //create the new board with new position
            INT nbboard = (bboard & ~p->position) | npos;        //create the new black board with new position
            //if the new move doesn't put the king in check, add it to the possible moves
            if(!isKingInCheck(nboard, wboard, nbboard, BLACK)){
                moves[i] = npos;
                i++;
            }
        }
    }
    return i;
}


INT* generateQueenMoves(piece *p, INT board, INT wboard, INT bboard, int *moveCount){
    return 0;
}

INT* generateRookMoves(piece *p, INT board, INT wboard, INT bboard, int *moveCount){
    INT *moves = (INT*)malloc(ROOK_MAX_MOVES * sizeof(INT));
    INT pos = p->position;
    int i = 0;
    INT npos = 0;
    int blocker = 0;
    //generate N moves
    int j = 8;
    while(pos << j && !blocker){
        npos = pos << j;
        i = calculateRookMove(p, board, wboard, bboard, npos, moves, i, moveCount, &blocker);
        j += 8;
    }

    blocker = 0;
    //generate S moves
    j = 8;
    while(pos >> j && !blocker){
        npos = pos >> j;
        i = calculateRookMove(p, board, wboard, bboard, npos, moves, i, moveCount, &blocker);
        j += 8;
    }

    blocker = 0;
    //generate W moves
    j = 1;
    while(!((pos << j) & hfile) && !blocker){
        npos = pos << j;
        i = calculateRookMove(p, board, wboard, bboard, npos, moves, i, moveCount, &blocker);
        j++;
    }

    blocker = 0;
    //generate E moves
    j = 1;
    while(!((pos >> j) & afile) && !blocker){
        npos = pos >> j;
        i = calculateRookMove(p, board, wboard, bboard, npos, moves, i, moveCount, &blocker);
        j++;
    }

    *moveCount = i;
    int balancer = 0;
    //printf("Move count: %d\n", *moveCount);
    if(*moveCount != 0){
        INT *possibleMoves = (INT*)malloc((*moveCount) * sizeof(INT));
        for(int j = 0; j < i; j++){
            //printf("j: %d, i: %d\n", j, i);
            if(moves[j] != 0){
                //printf("pushing %lx to new array\n", moves[j]);
                possibleMoves[j - balancer] = moves[j];
            }else{
                //printf("Move is zero\n");
                balancer++;
                *moveCount = *moveCount - 1;
            }  
        }
            free(moves);

            return possibleMoves;
    }else{
        free(moves);
        return 0;
    }
}

int calculateRookMove(piece *p, INT board, INT wboard, INT bboard, INT npos, INT *moves, int i, int *moveCount, int *blocker){
    if(p->color == WHITE){
        if(!(npos & wboard)){
            INT nboard = (board & ~p->position) | npos;  //create the new board with new position
            INT nwboard = (wboard & ~p->position) | npos; //create the new white board with new position
            if(npos & bboard) *blocker = 1;
            if(!isKingInCheck(nboard, nwboard, bboard, WHITE)){
                moves[i] = npos;
                //printf("Pushing move %lx to %d\n", npos, i);
                i++;
            }
        }else{
            *blocker = 1;
        }
    }else{
        if(!(npos & bboard)){
            INT nboard = (board & ~p->position) | npos;          //create the new board with new position
            INT nbboard = (bboard & ~p->position) | npos;        //create the new black board with new position
            if(npos & wboard) *blocker = 1;
            if(!isKingInCheck(nboard, nbboard, bboard, BLACK)){
                moves[i] = npos;
                //printf("Pushing move %lx to %d\n", npos, i);
                i++;
            }
        }else{
            *blocker = 1;
        }
    }
    return i;
}

INT* generateKnightMoves(piece *p, INT board, INT wboard, INT bboard, int *moveCount){
    INT *moves = (INT*)malloc(KNIGHT_MAX_MOVES * sizeof(INT));
    INT pos = p->position;
    int i = 0;
    INT npos = 0;
    //generate N moves
    if(!(pos & (rank8 | rank7))){
        //generate NNW moves
        if(!(pos & afile)){
            npos = pos << 17;
            i = calculateKnightMove(p, board, wboard, bboard, npos, moves, i, moveCount);
        }

        //generate NNE moves
        if(!(pos & hfile)){
            npos = pos << 15;
            i = calculateKnightMove(p, board, wboard, bboard, npos, moves, i, moveCount);
        }
    }

    //generate S moves
    if(!(pos & (rank1 | rank2))){
        //generate SSW moves
        if(!(pos & afile)){
            npos = pos >> 15;
            i = calculateKnightMove(p, board, wboard, bboard, npos, moves, i, moveCount);
        }

        //generate SSE moves
        if(!(pos & hfile)){
            npos = pos >> 17;
            i = calculateKnightMove(p, board, wboard, bboard, npos, moves, i, moveCount);
        }
    }

    //generate W moves
    if(!(pos & (afile | bfile))){
        //generate NWW moves
        if(!(pos & rank8)){
            npos = pos << 10;
            i = calculateKnightMove(p, board, wboard, bboard, npos, moves, i, moveCount);
        }

        //generate SWW moves
        if(!(pos & rank1)){
            npos = pos >> 6;
            i = calculateKnightMove(p, board, wboard, bboard, npos, moves, i, moveCount);
        }
    }

    //generate E moves
    if(!(pos & (gfile | hfile))){
        //generate NEE moves
        if(!(pos & rank8)){
            npos = pos << 6;
            i = calculateKnightMove(p, board, wboard, bboard, npos, moves, i, moveCount);
        }
        //generate SEE moves
        if(!(pos & rank1)){
            npos = pos >> 10;
            i = calculateKnightMove(p, board, wboard, bboard, npos, moves, i, moveCount);
        }
    }
    *moveCount = i;
    int balancer = 0;
    //printf("Move count: %d\n", *moveCount);
    if(*moveCount != 0){
        INT *possibleMoves = (INT*)malloc((*moveCount) * sizeof(INT));
        for(int j = 0; j < i; j++){
            //printf("j: %d, i: %d\n", j, i);
            if(moves[j] != 0){
                //printf("pushing %lx to new array\n", moves[j]);
                possibleMoves[j - balancer] = moves[j];
            }else{
                //printf("Move is zero\n");
                balancer++;
                *moveCount = *moveCount - 1;
            }  
        }
            free(moves);

            return possibleMoves;
    }else{
        free(moves);
        return 0;
    }
}

int calculateKnightMove(piece *p, INT board, INT wboard, INT bboard, INT npos, INT *moves, int i, int *moveCount){
    if(p->color == WHITE){
        //rintf("npos: %lx\n", npos);
        //white knight
        if(!(npos & wboard)){                   //check for blockers
            INT nboard = (board & ~p->position) | npos;  //create the new board with new position
            INT nwboard = (wboard & ~p->position) | npos;//create the new white board with new position
            //check check (haha)
            if(!isKingInCheck(nboard, nwboard, bboard, WHITE)){
                moves[i] = npos;
                //printf("Moves[%d]: %lx\n", i, moves[i]);
                i++;
            }
        }
    }else{
        if(!(npos & bboard)){
            INT nboard = (board & ~p->position) | npos;          //create the new board with new position
            INT nbboard = (bboard & ~p->position) | npos;        //create the new black board with new position
             //check check (haha)
            if(!isKingInCheck(nboard, nbboard, bboard, BLACK)){
                moves[i] = npos;
                i++;
            }
        }
    }
    return i;
}

INT* generateBishopMoves(piece *p, INT board, INT wboard, INT bboard, int *moveCount){
    return 0;
}

INT* generatePawnMoves(piece *p, INT board, INT wboard, INT bboard, int *moveCount){
    INT *moves = (INT*)malloc(PAWN_MAX_MOVES * sizeof(INT));
    INT pos = p->position;
    int i = 0;
    INT npos = 0;
    if(p->color == WHITE){
        if(pos & rank8){
            *moveCount = 0;
            return 0;
        }
        //generate N move
        if(!((pos << 8) & board)){
            //printf("N move\n");
            npos = pos << 8;
            i = calculatePawnMove(p, board, wboard, bboard, npos, moves, i, moveCount);
        }
       
        
        //generate 2N move
        if((pos & rank2) && !((pos << 16) & board) && !((pos << 8) & board)){
            //printf("2N move\n");
            npos = pos << 16;
            i = calculatePawnMove(p, board, wboard, bboard, npos, moves, i, moveCount);
        }
        
        //generate NW move
        if((pos << 9) & bboard){
            //printf("NW move\n");
            npos = pos << 9;
            i = calculatePawnMove(p, board, wboard, bboard, npos, moves, i, moveCount);
        }

        //generate NE move
        if((pos << 7) & bboard){
            //printf("NE move\n");
            npos = pos << 7;
            i = calculatePawnMove(p, board, wboard, bboard, npos, moves, i, moveCount);
        }

        //generate en passante moves
        if(enPassantePiece && enPassantePiece->color == BLACK){
            //printf("En passante move\n");
            //NW move
            if(enPassantePiece->position & (pos << 1)){
                npos = pos << 9;
                i = calculatePawnMove(p, board, wboard, bboard, npos, moves, i, moveCount);  
            }
            

            //NE move
            if(enPassantePiece->position & (pos >> 1)){
                npos = pos << 7;
                i = calculatePawnMove(p, board, wboard, bboard, npos, moves, i, moveCount);
            }
            
        }
    }else{
        if(pos & rank1){
            *moveCount = 0;
            return 0;
        }

        //generate S move
        if(!((pos >> 8) & board))
        npos = pos >> 8;
        i = calculatePawnMove(p, board, wboard, bboard, npos, moves, i, moveCount);
        
        //generate 2S move
        if(pos & rank7 && !((pos >> 16) & board)&& !((pos >> 8) & board)){
            npos = pos >> 16;
            i = calculatePawnMove(p, board, wboard, bboard, npos, moves, i, moveCount);
        }
       
        //generate SW move
        if((pos >> 7) & wboard){
            npos = pos >> 7;
            i = calculatePawnMove(p, board, wboard, bboard, npos, moves, i, moveCount);
        }

        //generate SE move
        if((pos >> 9) & wboard){
            npos = pos >> 9;
            i = calculatePawnMove(p, board, wboard, bboard, npos, moves, i, moveCount);
        }

        //generate en passante moves
        if(enPassantePiece && enPassantePiece->color == WHITE){
            //SW move
            if(enPassantePiece->position & (pos << 1)){
                npos = pos >> 7;
                i = calculatePawnMove(p, board, wboard, bboard, npos, moves, i, moveCount);
            }

            //SE move
            if(enPassantePiece->position & (pos >> 1)){
                npos = pos >> 9;
                i = calculatePawnMove(p, board, wboard, bboard, npos, moves, i, moveCount);
            }
        }
    }
    *moveCount = i;
    int balancer = 0;
    //printf("Move count: %d\n", *moveCount);
    if(*moveCount != 0){
        INT *possibleMoves = (INT*)malloc((*moveCount) * sizeof(INT));
        for(int j = 0; j < i; j++){
            //printf("j: %d, i: %d\n", j, i);
            if(moves[j] != 0){
                //printf("pushing %lx to new array\n", moves[j]);
                possibleMoves[j - balancer] = moves[j];
            }else{
                //printf("Move is zero\n");
                balancer++;
                *moveCount = *moveCount - 1;
            }  
        }
            free(moves);

            return possibleMoves;
    }else{
        free(moves);
        return 0;
    }
}

int calculatePawnMove(piece *p, INT board, INT wboard, INT bboard, INT npos, INT *moves, int i, int *moveCount){
    //algorithm for white pawn
    if(p->color == WHITE){
        INT nboard = (board & ~p->position) | npos;      //create the new board with the new position
        INT nwboard = (wboard & ~p->position) | npos;    //create new white board
        //if the new move doesn't put the king in check, add it to the possible moves
        if(!isKingInCheck(nboard, nwboard, bboard, WHITE)){
            //printf("moves[%d]: %lx\n", i, npos);
            moves[i] = npos;
            i++;
        }
    }else{
        INT nboard = (board & ~p->position) | npos;      //create the new board with the new position
        INT nbboard = (bboard & ~p->position) | npos;    //create new black board
        //if the new move doesn't put the king in check, add it to the possible moves
        if(!isKingInCheck(nboard, nbboard, bboard, BLACK)){
            //printf("moves[%d]: %lx\n", i, npos);
            moves[i] = npos;
            i++;
        }
    }
    return i;
}

int isKingInCheck(INT board, INT wboard, INT bboard, INT color){
    return 0;
}