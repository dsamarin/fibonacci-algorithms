all: fib_naive fib_bottomup fib_matrix

fib_naive: main.c fib_naive.c
	gcc main.c fib_naive.c -lgmp -O3 -o fib_naive

fib_bottomup: main.c fib_bottomup.c
	gcc main.c fib_bottomup.c -lgmp -O3 -o fib_bottomup

fib_matrix: main.c fib_matrix.c
	gcc main.c fib_matrix.c -lgmp -O3 -o fib_matrix

clean:
	rm -f fib_naive
	rm -f fib_bottomup
	rm -f fib_matrix
