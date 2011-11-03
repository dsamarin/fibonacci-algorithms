#include <gmp.h>

void
fib_compute (mpz_t result, mpz_t term)
{
	if (mpz_cmp_ui (term, 0) == 0) {
		mpz_set_ui (result, 0);
		return;
	}

	mpz_t a, b, i;
	mpz_init_set_ui (a, 1);
	mpz_init_set_ui (b, 1);
	mpz_init_set_ui (i, 3);

	while (mpz_cmp (i, term) <= 0) {
		mpz_t c;
		mpz_init (c);

		mpz_add (c, a, b);
		mpz_set (a, b);
		mpz_set (b, c);
		
		mpz_add_ui (i, i, 1);
		mpz_clear (c);
	}

	mpz_set (result, b);
}
