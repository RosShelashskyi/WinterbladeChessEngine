#pragma once
#include "pieces.h"

//represents the whole board
INT board;

//boards for white and black pieces
INT blackPieces;
INT whitePieces;

//boards for every piece type and color
INT WKing;
INT WQueens;
INT WRooks;
INT WKnights;
INT WBishops;
INT WPawns;

INT BKing;
INT BQueens;
INT BRooks;
INT BKnights;
INT BBishops;
INT BPawns;

//function declarations
void setBoards();