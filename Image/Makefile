





build:image.c image.h main.c
	mkdir build
	gcc -c image.c -o image.o
	gcc -c main.c -o main.o
	gcc main.o image.o -o my_filter
	mv image.o ./build
	mv main.o ./build
	mv my_filter ./build
clean:
	rm -rd build
run:
	./build/myfilter



