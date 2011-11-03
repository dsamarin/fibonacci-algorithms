Fibonacci Algorithms
====================

This repository contains example programs of different algorithms used to calculate fibonacci numbers.


Naive (`fib_naive`)
---------------------

This algorithm is based directly on the mathematical definition. It has a running time of `Θ(ϕ^n)` where n is the term of the sequence. Exponential, not good.

	function fib(n):
		if (n == 0) return 0;
		if (n == 1) return 1;
		return fib (n - 1) + fib (n - 2);


Bottom-up (`fib_bottomup`)
----------------------------

This algorithm is called the bottom-up algorithm because it iterates from 0 to n adding as it goes along. It has a running time of `Θ(n)`. It's okay but we can do better.

	function fib(n):
		if (n == 0) return 0;
		a = 1;
		b = 1;
		i = 3;
		while (i <= n):
			c = a + b;
			a = b;
			b = c;
			i = i + 1;
		return b;


Matrix multiplication (`fib_matrix`)
------------------------------------

This uses exponentiation by squaring to compute the nth power of a 2x2 matrix. It has a running time of `Θ(log n)`. It takes advantage of the theorem:

	[[F_{n+1}, F_n], [F_n, F_{n-1}]] = [[1, 1], [1, 0]] ^ n;

	function fib(n):
		matrix = [[1, 1], [1, 0]];
		matrix = matrix_pow (matrix, n); # Finding a power is O(log n) time with the exponentiation by squares method
		return matrix[1, 2];


Phi Z-component vector multiplication (`fib_vector`)
----------------------------------------------------

This is practically the same as above, but with fewer variables and simpler code. It has the same running time of `Θ(log n)`.


GMP Built-in (`fib_gmpbuiltin`)
-------------------------------

The GMP library comes with its own routine for finding the nth fibonacci sequence. However it only accepts an `unsigned long int` argument instead of its `mpz_t` integer type.
