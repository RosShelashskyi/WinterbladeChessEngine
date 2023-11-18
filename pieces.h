#pragma once
#include <stdint.h>
#include "typesAndMacros.h"

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

//pointer to piece that can be taken by en passante
piece *enPassantePiece;

void setWhitePieces();
void setBlackPieces();