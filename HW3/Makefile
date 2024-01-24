all: clean driver2 driver1

driver2: driver2.cpp Tetris.cpp Tetromino.cpp
	@g++ -std=c++11 -o driver2 driver2.cpp Tetris.cpp Tetromino.cpp
	@./driver2

driver1: driver1.cpp Tetris.cpp Tetromino.cpp
	@g++ -std=c++11 -o driver1 driver1.cpp Tetris.cpp Tetromino.cpp
	./driver1

clean:
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f driver1 driver2