#include <gmp.h>

void
fib_compute (mpz_t result, mpz_t term)
{
	mpz_t a, b, t1, t2;

	if (mpz_cmp_ui (term, 0) == 0) {
		mpz_set_ui (result, 0);
		return;
	}

	if (mpz_cmp_ui (term, 1) == 0) {
		mpz_set_ui (result, 1);
		return;
	}

	mpz_init (a);
	mpz_init (b);
	mpz_init (t1);
	mpz_init (t2);

	mpz_sub_ui (t1, term, 1);
	mpz_sub_ui (t2, term, 2);

	fib_compute (a, t1);
	fib_compute (b, t2);

	mpz_add (result, a, b);
	mpz_clear (a);
	mpz_clear (b);
	mpz_clear (t1);
	mpz_clear (t2);
}
