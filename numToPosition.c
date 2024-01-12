#include "typesAndMacros.h"

//function for transforming a position into a human readable chess board format
void numToPosition(INT pos, char *str){
    //64 bits, 8 new lines, and one string terminator = 73 chars
    char result[73];
    //iterator for the string
    int strI = 0;
    //create a mask to shift right each iteration
    INT mask = 0x8000000000000000;
    char c;
    for(int i = 0; i < 64; i++){
        //get the bit and add it to the result
        if(pos & (mask >> i)){
            c = '1';
        }else{
            c = '0';
        }
        str[strI] = c;
        strI++;
        //if the rank should end, add a newline
        if((i + 1) % 8 == 0){
            str[strI] = '\n';
            strI++;
        }
    }
    //add a string terminator
    str[strI] = '\0';
}