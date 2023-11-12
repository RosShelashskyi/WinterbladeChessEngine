#pragma once
#include "pieces.h"
#include "board.h"
#include "typesAndMacros.h"

INT* generateMoves(piece *p, INT board, INT wboard, INT bboard);

INT* generateKingMoves(piece *p, INT board, INT wboard, INT bboard);

INT* generateQueenMoves(piece *p, INT board, INT wboard, INT bboard);

INT* generateRookMoves(piece *p, INT board, INT wboard, INT bboard);

INT* generateKnightMoves(piece *p, INT board, INT wboard, INT bboard);

INT* generateBishopMoves(piece *p, INT board, INT wboard, INT bboard);

INT* generatePawnMoves(piece *p, INT board, INT wboard, INT bboard);

int isKingInCheck(INT board, INT wboard, INT bboard, INT color);

int calculateKingMove(piece *p, INT board, INT wboard, INT bboard, INT npos, INT *moves, int i);