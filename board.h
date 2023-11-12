#pragma once
#include "pieces.h"
#include "typesAndMacros.h"

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

INT aFile;
INT bFile;
INT cFile;
INT dFile;
INT eFile;
INT fFile;
INT gFile;
INT hFile;

INT rank1;
INT rank2;
INT rank3;
INT rank4;
INT rank5;
INT rank6;
INT rank7;
INT rank8;

//function declarations
void setBoards();