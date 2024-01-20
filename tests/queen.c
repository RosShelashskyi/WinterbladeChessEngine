#include "../numToPosition.h"   
#include "../moveGenerator.h"
#include "../board.h"
#include "queen.h"
#include "stdio.h"

//full test of the queen's move on every square of the board
void queenMoveTest(){
    setBoards();
    INT board = 0;
    INT wboard = 0;
    INT bboard = 0;

    piece queen;
    queen.position = A8;
    queen.type = QUEEN;
    queen.color = WHITE;

    printf("WHITE QUEEN\n");

    for(int i = 0 ; i < 64; i++){
        if(i) queen.position = queen.position >> 1;
        board = queen.position;
        wboard = queen.position;
        int moveCount = 0;
        INT *moves = generateMoves(&queen, board, wboard, bboard, &moveCount);
        INT m = 0;
        for(int i = 0; i < moveCount; i++){
            m = m | moves[i];
        }
        char str[73];
        numToPosition(m, str);
        printf("%s\n", str);
    }

    printf("BLACK QUEEN\n");

    queen.position = A8;
    queen.color = BLACK;
    wboard = 0;

    for(int i = 0; i < 64; i++){
        if(i) queen.position = queen.position >> 1;
        board = queen.position;
        bboard = queen.position;
        int moveCount = 0;
        INT *moves = generateMoves(&queen, board, wboard, bboard, &moveCount);
        INT m = 0;
        for(int i = 0; i < moveCount; i++){
            m = m | moves[i];
        }
        char str[73];
        numToPosition(m, str);
        printf("%s\n", str);
    }
    printf("END OF TEST");
}

//testing the queen being blocked by friendly pieces

//testing the queen being able to capture enemy pieces