OBJS	= interpreter.o
SOURCE	= interpreter.c
HEADER	= 
OUT	= bf
CC	 = gcc
FLAGS	 = -g -c -Werror
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

interpreter.o: interpreter.c
	$(CC) $(FLAGS) interpreter.c -std=c99


clean:
	rm -f $(OBJS) $(OUT)

test: $(OUT) hello.bf
	./$(OUT) ./hello.bf