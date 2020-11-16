all:
	cppcheck --enable=all --inconclusive longestCommon.c
	gcc longestCommon.c -o longestCommon.out -Wall -O
	#gcc -O -g -fsanitize=address longestCommon.c -o longestCommon.out -Wall


clean:
	clear
	m -f *.out
