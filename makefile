CC=gcc -g
EXE=demo

$(EXE) : ll.c ll.h demo.c
	$(CC) ll.c ll.h demo.c -o $(EXE)
