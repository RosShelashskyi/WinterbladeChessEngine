#include "board.h"

//sets the default values for all the boards
void setBoards(){
    WKing = 0x0000000000000008;
    WQueens = 0x0000000000000010;
    WRooks = 0x0000000000000081;
    WKnights = 0x0000000000000042;
    WBishops = 0x0000000000000024;
    WPawns = 0x000000000000FF00;

    BKing = 0x0800000000000000;
    BQueens = 0x1000000000000000;
    BRooks = 0x8100000000000000;
    BKnights = 0x4200000000000000;
    BBishops = 0x2400000000000000;
    BPawns = 0x00FF000000000000;

    whitePieces = WKing | WQueens | WRooks | WKnights | WBishops | WPawns;

    blackPieces = BKing | BQueens | BRooks | BKnights | BBishops | BPawns;

    board = whitePieces | blackPieces;
}