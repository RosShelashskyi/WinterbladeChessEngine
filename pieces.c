#include "pieces.h"

//setting the white pieces
void setWhitePieces(){
    W_King->color = WHITE;
    W_King->position = 0x0000000000000008;
    W_King->type = KING;
    W_King->value = 0;

    W_Queen->color = WHITE;
    W_Queen->position = 0x0000000000000010;
    W_Queen->type = QUEEN;
    W_Queen->value = 9;

    W_A_Rook->color = WHITE;
    W_A_Rook->position = 0x00000000000000080;
    W_A_Rook->type = ROOK;
    W_A_Rook->value = 5;

    W_H_Rook->color = WHITE;
    W_H_Rook->position = 0x00000000000000001;
    W_H_Rook->type = ROOK;
    W_H_Rook->value = 5;

    W_B_Knight->color = WHITE;
    W_B_Knight->position = 0x0000000000000040;
    W_B_Knight->type = KNIGHT;
    W_B_Knight->value = 3;

    W_B_Knight->color = WHITE;
    W_B_Knight->position = 0x0000000000000002;
    W_B_Knight->type = KNIGHT;
    W_B_Knight->value = 3;

    W_C_Bishop->color = WHITE;
    W_C_Bishop->position = 0x0000000000000020;
    W_C_Bishop->type = BISHOP;
    W_C_Bishop->value = 3;

    W_F_Bishop->color = WHITE;
    W_F_Bishop->position = 0x0000000000000004;
    W_F_Bishop->type = BISHOP;
    W_F_Bishop->value = 3;

    W_A_Pawn->color = WHITE;
    W_A_Pawn->position = 0x0000000000008000;
    W_A_Pawn->type = PAWN;
    W_A_Pawn->value = 1;

    W_B_Pawn->color = WHITE;
    W_B_Pawn->position = 0x0000000000004000;
    W_B_Pawn->type = PAWN;
    W_B_Pawn->value = 1;

    W_C_Pawn->color = WHITE;
    W_C_Pawn->position = 0x0000000000002000;
    W_C_Pawn->type = PAWN;
    W_C_Pawn->value = 1;

    W_D_Pawn->color = WHITE;
    W_D_Pawn->position = 0x0000000000001000;
    W_D_Pawn->type = PAWN;
    W_D_Pawn->value = 1;

    W_E_Pawn->color = WHITE;
    W_E_Pawn->position = 0x0000000000000800;
    W_E_Pawn->type = PAWN;
    W_E_Pawn->value = 1;
    
    W_F_Pawn->color = WHITE;
    W_F_Pawn->position = 0x0000000000000400;
    W_F_Pawn->type = PAWN;
    W_F_Pawn->value = 1;

    W_G_Pawn->color = WHITE;
    W_G_Pawn->position = 0x0000000000000200;
    W_G_Pawn->type = PAWN;
    W_G_Pawn->value = 1;

    W_H_Pawn->color = WHITE;
    W_H_Pawn->position = 0x0000000000000100;
    W_H_Pawn->type = PAWN;
    W_H_Pawn->value = 1;

    whitePieces[0] = W_King;
    whitePieces[1] = W_Queen;
    whitePieces[2] = W_A_Rook;
    whitePieces[3] = W_H_Rook;
    whitePieces[4] = W_B_Knight;
    whitePieces[5] = W_G_Knight;
    whitePieces[6] = W_C_Bishop;
    whitePieces[7] = W_F_Bishop;
    whitePieces[8] = W_A_Pawn;
    whitePieces[9] = W_B_Pawn;
    whitePieces[10] = W_C_Pawn;
    whitePieces[11] = W_D_Pawn;
    whitePieces[12] = W_E_Pawn;
    whitePieces[13] = W_F_Pawn;
    whitePieces[14] = W_G_Pawn;
    whitePieces[15] = W_H_Pawn;

    enPassantePiece = 0;
}

//setting the black pieces
void setBlackPieces(){
    B_King->color = BLACK;
    B_King->position = 0x0800000000000000;
    B_King->type = KING;
    B_King->value = 0;

    B_Queen->color = BLACK;
    B_Queen->position = 0x1000000000000000;
    B_Queen->type = QUEEN;
    B_Queen->value = 9;

    B_A_Rook->color = BLACK;
    B_A_Rook->position = 0x8000000000000000;
    B_A_Rook->type = ROOK;
    B_A_Rook->value = 5;

    B_H_Rook->color = BLACK;
    B_H_Rook->position = 0x0100000000000000;
    B_H_Rook->type = ROOK;
    B_H_Rook->value = 5;

    B_B_Knight->color = BLACK;
    B_B_Knight->position = 0x4000000000000000;
    B_B_Knight->type = KNIGHT;
    B_B_Knight->value = 3;

    B_G_Knight->color = BLACK;
    B_G_Knight->position = 0x0200000000000000;
    B_G_Knight->type = KNIGHT;
    B_G_Knight->value = 3;

    B_C_Bishop->color = BLACK;
    B_C_Bishop->position = 0x2000000000000000;
    B_C_Bishop->type = BISHOP;
    B_C_Bishop->value = 3;

    B_F_Bishop->color = BLACK;
    B_F_Bishop->position = 0x0400000000000000;
    B_F_Bishop->type = BISHOP;
    B_F_Bishop->value = 3;

    B_A_Pawn->color = BLACK;
    B_A_Pawn->position = 0x0080000000000000;
    B_A_Pawn->type = PAWN;
    B_A_Pawn->value = 1;

    B_B_Pawn->color = BLACK;
    B_B_Pawn->position = 0x0040000000000000;
    B_B_Pawn->type = PAWN;
    B_B_Pawn->value = 1;

    B_C_Pawn->color = BLACK;
    B_C_Pawn->position = 0x0020000000000000;
    B_C_Pawn->type = PAWN;
    B_C_Pawn->value = 1;

    B_D_Pawn->color = BLACK;
    B_D_Pawn->position = 0x0010000000000000;
    B_D_Pawn->type = PAWN;
    B_D_Pawn->value = 1;

    B_E_Pawn->color = BLACK;
    B_E_Pawn->position = 0x0008000000000000;
    B_E_Pawn->type = PAWN;
    B_E_Pawn->value = 1;

    B_F_Pawn->color = BLACK;
    B_F_Pawn->position = 0x0004000000000000;
    B_F_Pawn->type = PAWN;
    B_F_Pawn->value = 1;

    B_G_Pawn->color = BLACK;
    B_G_Pawn->position = 0x0002000000000000;
    B_G_Pawn->type = PAWN;
    B_G_Pawn->value = 1;

    B_H_Pawn->color = BLACK;
    B_H_Pawn->position = 0x0001000000000000;
    B_H_Pawn->type = PAWN;
    B_H_Pawn->value = 1;

    blackPieces[0] = W_King;
    blackPieces[1] = W_Queen;
    blackPieces[2] = W_A_Rook;
    blackPieces[3] = W_H_Rook;
    blackPieces[4] = W_B_Knight;
    blackPieces[5] = W_G_Knight;
    blackPieces[6] = W_C_Bishop;
    blackPieces[7] = W_F_Bishop;
    blackPieces[8] = W_A_Pawn;
    blackPieces[9] = W_B_Pawn;
    blackPieces[10] = W_C_Pawn;
    blackPieces[11] = W_D_Pawn;
    blackPieces[12] = W_E_Pawn;
    blackPieces[13] = W_F_Pawn;
    blackPieces[14] = W_G_Pawn;
    blackPieces[15] = W_H_Pawn;

}