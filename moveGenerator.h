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

int calculateKingMove(piece *p, INT board, INT wboard, INT bboard, INT npos, INT *moves, int i, int *moveCount);

int calculatePawnMove(piece *p, INT board, INT wboard, INT bboard, INT npos, INT *moves, int i, int *moveCount);

int calculateKnightMove(piece *p, INT board, INT wboard, INT bboard, INT npos, INT *moves, int i, int *moveCount);

int calculateRookMove(piece *p, INT board, INT wboard, INT bboard, INT npos, INT *moves, int i, int *moveCount, int *blocker);

int calculateBishopMove(piece *p, INT board, INT wboard, INT bboard, INT npos, INT *moves, int i, int *moveCount, int *blocker);