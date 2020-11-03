all:
	cppcheck --enable=all --inconclusive detectCapitalUse.cpp
	g++ detectCapitalUse.cpp -o detectCapitalUse.out -Wall

clean:
	rm -f *.out
