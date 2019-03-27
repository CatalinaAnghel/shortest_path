all: project

project: main.o matrix.o shortest_length_path.o
	gcc main.o matrix.o shortest_length_path.o -o project

main.o: main.c
	gcc -c main.c

matrix.o: matrix.c
	gcc -c matrix.c

shortest_length_path.o: shortest_length_path.c
	gcc -c shortest_length_path.c

clean:
	rm *o project