CC = gcc
GGC_FLAGS = -g -Wall -W
EXEC = test

all : $(EXEC)

SRC_OBJ = ../src/utils.c
SRC_PROG = test.c

OBJ_O = $(SRC_OBJ:.c=.o)
OBJ_PROG = $(SRC_PROG:.c=.o)

test : test.o $(OBJ_O)
	$(CC) $(GGC_FLAGS) -o $@ $^ -lcunit

%.o : %.c
	$(CC) $(GGC_FLAGS) -c -o $@ $<

-include .depend
depend :
	$(CC) -MM $(SRC_OBJ) $(SRC_PROG) > .depend

clean :
	rm -f $(OBJ_O) $(OBJ_PROG) $(EXEC) depend

.PHONY : all clean depend