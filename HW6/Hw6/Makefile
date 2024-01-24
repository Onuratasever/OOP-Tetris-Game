all: clean clear compile run

clean:
	@rm -f *.out
	@rm -f *.o

clear:
	@clear

compile:
	@g++ -std=c++11 -c driver.cpp -o driver.o
	@g++ -std=c++11 -c PFArray.cpp -o PFArray.o
	@g++ driver.o PFArray.o -o a.out

run:
	./a.out