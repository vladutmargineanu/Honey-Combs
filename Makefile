CC=gcc
CFLAGS=-Wall
SRC=tema2.c
EXE=tema2

build: $(EXE)

$(EXE): tema2.o
	        $(CC) tema2.o -o $(EXE)
		        
tema2.o: $(SRC)
	        $(CC) $(CFLAGS) -c $(SRC) -o tema2.o -lm 

clean: 
	        rm -f tema2.o $(EXE)                                                                               
		                               
