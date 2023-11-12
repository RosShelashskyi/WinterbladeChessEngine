#include <stdint.h>

//defining values to be used throughout the program
#define WHITE 0
#define BLACK 1
#define KING 0
#define QUEEN 1
#define ROOK 2
#define KNIGHT 3
#define BISHOP 4
#define PAWN 5
#define MAX_MOVES 30

//defining a simple unsigned 64-bit integer type
typedef uint64_t INT;

//defining a struct type to represent the pieces
typedef struct Piece{
    INT position;
    int color;
    int value;
    int type;
    int possibleMoves[MAX_MOVES];
} piece;