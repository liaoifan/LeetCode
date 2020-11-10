all:
	cppcheck --enable=all --inconclusive twoSum.c
	gcc twoSum.c -o twoSum.out -Wall
	cppcheck --enable=all --inconclusive twoSum_BruteForce.c
	gcc twoSum.c -o twoSum_BruteForce.out -Wall
clean:
	clear
	rm -f *.out
