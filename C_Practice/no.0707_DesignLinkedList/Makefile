all:
	cppcheck --enable=all --inconclusive designLinkedList.c
	#gcc designLinkedList.c -o designLinkedList.out -Wall
	gcc -O -g -fsanitize=address designLinkedList.c -o designLinkedList.out -Wall

clean:
	clear
	m -f *.out
