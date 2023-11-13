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

    rank8 = 0xFF00000000000000;
    rank7 = 0x00FF000000000000;
    rank6 = 0x0000FF0000000000;
    rank5 = 0x000000FF00000000;
    rank4 = 0x00000000FF000000;
    rank3 = 0x0000000000FF0000;
    rank2 = 0x000000000000FF00;
    rank1 = 0x00000000000000FF;

    afile = 0x8080808080808080;
    bfile = 0x4040404040404040;
    cfile = 0x2020202020202020;
    dfile = 0x1010101010101010;
    efile = 0x0808080808080808;
    ffile = 0x0404040404040404;
    gfile = 0x0202020202020202;
    hfile = 0x0101010101010101;
}