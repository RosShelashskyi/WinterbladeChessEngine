#pragma once
#include <stdint.h>

//defining values to be used throughout the program
#define WHITE 0
#define BLACK 1
#define KING 0
#define QUEEN 1
#define ROOK 2
#define KNIGHT 3
#define BISHOP 4
#define PAWN 5
#define MAX_MOVES 30

//defining a simple unsigned 64-bit integer type
typedef uint64_t INT;

//defining a struct type to represent the pieces
typedef struct Piece{
    INT position;
    int color;
    int value;
    int type;
    int possibleMoves[MAX_MOVES];
} piece;

//declaring pointers for white pieces
piece *W_King;
piece *W_Queen;
piece *W_A_Rook;
piece *W_H_Rook;
piece *W_B_Knight;
piece *W_G_Knight;
piece *W_C_Bishop;
piece *W_F_Bishop;
piece *W_A_Pawn;
piece *W_B_Pawn;
piece *W_C_Pawn;
piece *W_D_Pawn;
piece *W_E_Pawn;
piece *W_F_Pawn;
piece *W_G_Pawn;
piece *W_H_Pawn;

//declaring pointer for black pieces
piece *B_King;
piece *B_Queen;
piece *B_A_Rook;
piece *B_H_Rook;
piece *B_B_Knight;
piece *B_G_Knight;
piece *B_C_Bishop;
piece *B_F_Bishop;
piece *B_A_Pawn;
piece *B_B_Pawn;
piece *B_C_Pawn;
piece *B_D_Pawn;
piece *B_E_Pawn;
piece *B_F_Pawn;
piece *B_G_Pawn;
piece *B_H_Pawn;

void setWhitePieces();
void setBlackPieces();