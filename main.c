#include <stdio.h>
#include <gmp.h>

#include "fib.h"

int fib_input (mpz_t term)
{
	fputs ("Enter a non-negative integer `n` to get the `nth` term: ", stdout);

	if (mpz_inp_str (term, stdin, 10)) {
		return mpz_sgn (term) != -1;
	}

	return 0;
}


void fib_print (mpz_t result, mpz_t term)
{
	gmp_printf ("F_%Zd = %Zd\n\n", term, result);
}


int main (void)
{
	mpz_t term, result;

	fputs ("The Fibonacci sequence\n", stdout);

	mpz_init (term);
	mpz_init (result);
	while (fib_input (term)) {
		fib_compute (result, term);
		fib_print (result, term);
	}
	mpz_clear (term);
	mpz_clear (result);

	putchar ('\n');

	return 0;
}
