
build: linkedlist.h linkedlist.c main.c
	mkdir build
	gcc -c linkedlist.c -o linkedlist.o
	gcc -c main.c -o main.o
	gcc linkedlist.o main.o -o main
	mv linkedlist.o main.o main ./build

clean:
	rm -rd ./build
