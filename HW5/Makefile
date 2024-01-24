all: clear compile run clean

compile: Tetromino.cpp Tetromino.hpp driver1.cpp driver2.cpp AbstractTetris.cpp AbstractTetris.hpp TetrisVector.cpp TetrisVector.hpp TetrisArray1D.hpp TetrisArray1D.cpp  TetrisAdapter.cpp
	@echo "Compiling..."
	@echo "-------------------------------------------"
	@g++	-std=c++11 -g driver1.cpp AbstractTetris.cpp TetrisVector.cpp TetrisArray1D.cpp TetrisAdapter.cpp Tetromino.cpp -o driver1
	@g++	-std=c++11 -g driver2.cpp AbstractTetris.cpp TetrisVector.cpp TetrisArray1D.cpp TetrisAdapter.cpp Tetromino.cpp -o driver2

run:
	@./driver1
	@./driver2

clean:
	@rm -f *.o
	@rm -f driver1
	@rm -f driver2
	
clear:
	clear