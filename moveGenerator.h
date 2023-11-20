#pragma once
#include "pieces.h"
#include "board.h"
#include "typesAndMacros.h"

INT* generateMoves(piece *p, INT board, INT wboard, INT bboard, int *moveCount);

INT* generateKingMoves(piece *p, INT board, INT wboard, INT bboard, int *moveCount);

INT* generateQueenMoves(piece *p, INT board, INT wboard, INT bboard, int *moveCount);

INT* generateRookMoves(piece *p, INT board, INT wboard, INT bboard, int *moveCount);

INT* generateKnightMoves(piece *p, INT board, INT wboard, INT bboard, int *moveCount);

INT* generateBishopMoves(piece *p, INT board, INT wboard, INT bboard, int *moveCount);

INT* generatePawnMoves(piece *p, INT board, INT wboard, INT bboard, int *moveCount);

int isKingInCheck(INT board, INT wboard, INT bboard, INT color);

int calculateMove(piece *p, INT board, INT wboard, INT bboard, INT npos, INT *moves, int i, int *moveCount);

int calculateRayMove(piece *p, INT board, INT wboard, INT bboard, INT npos, INT *moves, int i, int *moveCount, int *blocker);