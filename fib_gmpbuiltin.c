#include <gmp.h>

void
fib_compute (mpz_t result, mpz_t term)
{
	mpz_fib_ui (result, mpz_get_ui (term));
}
