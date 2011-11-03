#include <gmp.h>

static inline void
fib_matrix_mul (mpz_t a, mpz_t b, mpz_t c, mpz_t d, mpz_t e, mpz_t f, mpz_t g, mpz_t h)
{
	mpz_t r, s, t, u;

	mpz_init (r);
	mpz_init (s);
	mpz_init (t);
	mpz_init (u);

	mpz_mul (r, a, e);
	mpz_mul (s, a, f);
	mpz_mul (t, c, e);
	mpz_mul (u, c, f);

	mpz_addmul (r, b, g);
	mpz_addmul (s, b, h);
	mpz_addmul (t, d, g);
	mpz_addmul (u, d, h);

	mpz_set (a, r);
	mpz_set (b, s);
	mpz_set (c, t);
	mpz_set (d, u);

	mpz_clear (r);
	mpz_clear (s);
	mpz_clear (t);
	mpz_clear (u);
}

static inline void
fib_matrix_square (mpz_t a, mpz_t b, mpz_t c, mpz_t d)
{
	fib_matrix_mul (a, b, c, d, a, b, c, d);
}

static inline void
fib_matrix_pow (mpz_t a, mpz_t b, mpz_t c, mpz_t d, mpz_t term)
{
	mpz_t half_term;

	if (mpz_cmp_ui (term, 1) == 0) return;

	mpz_init (half_term);

	if (mpz_even_p (term)) {
		mpz_tdiv_q_2exp (half_term, term, 1);
		fib_matrix_pow (a, b, c, d, half_term);
		fib_matrix_square (a, b, c, d);
	} else {
		mpz_t e, f, g, h;
		mpz_init_set (e, a);
		mpz_init_set (f, b);
		mpz_init_set (g, c);
		mpz_init_set (h, d);

		mpz_sub_ui (half_term, term, 1);
		mpz_tdiv_q_2exp (half_term, half_term, 1);

		fib_matrix_pow (a, b, c, d, half_term);
		fib_matrix_square (a, b, c, d);
		fib_matrix_mul (a, b, c, d, e, f, g, h);

		mpz_clear (e);
		mpz_clear (f);
		mpz_clear (g);
		mpz_clear (h);
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

	mpz_t a, b, c, d;
	mpz_init_set_ui (a, 1);
	mpz_init_set_ui (b, 1);
	mpz_init_set_ui (c, 1);
	mpz_init_set_ui (d, 0);

	fib_matrix_pow (a, b, c, d, term);
	mpz_set (result, b);

	mpz_clear (a);
	mpz_clear (b);
	mpz_clear (c);
	mpz_clear (d);
}
