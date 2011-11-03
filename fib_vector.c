#include <gmp.h>

static inline void
fib_component_mul (mpz_t a, mpz_t b, mpz_t c, mpz_t d)
{
	mpz_t r, s, bd;

	mpz_init (r);
	mpz_init (s);
	mpz_init (bd);

	mpz_mul (r, a, c);
	mpz_mul (s, b, c);
	mpz_mul (bd, b, d);

	mpz_addmul (s, a, d);
	mpz_add (r, r, bd);
	mpz_add (s, s, bd);

	mpz_set (a, r);
	mpz_set (b, s);

	mpz_clear (r);
	mpz_clear (s);
	mpz_clear (bd);
}

static inline void
fib_component_pow (mpz_t a, mpz_t b, mpz_t term)
{
	mpz_t half_term;

	if (mpz_cmp_ui (term, 1) == 0) return;

	mpz_init (half_term);

	if (mpz_even_p (term)) {
		mpz_tdiv_q_2exp (half_term, term, 1);
		fib_component_pow (a, b, half_term);
		fib_component_mul (a, b, a, b);
	} else {
		mpz_t c, d;
		mpz_init_set (c, a);
		mpz_init_set (d, b);

		mpz_sub_ui (half_term, term, 1);
		mpz_tdiv_q_2exp (half_term, half_term, 1);

		fib_component_pow (a, b, half_term);
		fib_component_mul (a, b, a, b);
		fib_component_mul (a, b, c, d);

		mpz_clear (c);
		mpz_clear (d);
	}

	mpz_clear (half_term);
}

void
fib_compute (mpz_t result,
             mpz_t term)
{
	if (mpz_cmp_ui (term, 0) == 0) {
		mpz_set_ui (result, 0);
		return;
	}

	mpz_t a, b;

	mpz_init_set_si (a, 0);
	mpz_init_set_si (b, 1);

	fib_component_pow (a, b, term);
	mpz_set (result, b);

	mpz_clear (a);
	mpz_clear (b);
}
