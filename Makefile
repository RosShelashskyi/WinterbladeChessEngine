make: main.c board.c moveGenerator.c numToPosition.c pieces.c test.c tests/king.c tests/queen.c tests/rook.c
	gcc *.c tests/*.c