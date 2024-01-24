all: clean clear compile run

clean:
	@rm -f *.out
	@rm -f *.o

clear:
	@clear

compile:
	@g++ -std=c++11 -c driver.cpp -o driver.o
	@g++ -std=c++11 -c DayOfYearSet.cpp -o set.o
	@g++ driver.o set.o -o Set.out

run:
	./Set.out >> res.txt
	./Set.out