all: clean clear compile run

clean:
	@rm -f *.out
	@rm -f *.o

clear:
	@clear

compile:
	@g++ -std=c++11 -c main.cpp -o main.o
	@g++ -std=c++11 -c Tetromino.cpp -o Tetromino.o
	@g++ main.o Tetromino.o -o tetris.out

run:
	./tetris.out