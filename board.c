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

    aFile = 0xFF00000000000000;
    bFile = 0x00FF000000000000;
    cFile = 0x0000FF0000000000;
    dFile = 0x000000FF00000000;
    eFile = 0x00000000FF000000;
    fFile = 0x0000000000FF0000;
    gFile = 0x000000000000FF00;
    hFile = 0x00000000000000FF;

    rank1 = 0x8080808080808080;
    rank2 = 0x4040404040404040;
    rank3 = 0x2020202020202020;
    rank4 = 0x1010101010101010;
    rank5 = 0x0808080808080808;
    rank6 = 0x0404040404040404;
    rank7 = 0x0202020202020202;
    rank8 = 0x0101010101010101;
}