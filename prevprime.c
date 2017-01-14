/* mpz_nextprime(p,t) - compute the next prime > t and store that in p.

Copyright 1999-2001, 2008, 2009, 2012 Free Software Foundation, Inc.

Contributed to the GNU project by Niels Möller and Torbjorn Granlund.

This file is part of the GNU MP Library.

The GNU MP Library is free software; you can redistribute it and/or modify
it under the terms of either:

  * the GNU Lesser General Public License as published by the Free
    Software Foundation; either version 3 of the License, or (at your
    option) any later version.

or

  * the GNU General Public License as published by the Free Software
    Foundation; either version 2 of the License, or (at your option) any
    later version.

or both in parallel, as here.

The GNU MP Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received copies of the GNU General Public License and the
GNU Lesser General Public License along with the GNU MP Library.  If not,
see https://www.gnu.org/licenses/.  */

#include <gmp.h>
#include <stdio.h>

static const unsigned char primegap[] =
{
  2,2,4,2,4,2,4,6,2,6,4,2,4,6,6,2,6,4,2,6,4,6,8,4,2,4,2,4,14,4,6,
  2,10,2,6,6,4,6,6,2,10,2,4,2,12,12,4,2,4,6,2,10,6,6,6,2,6,4,2,10,14,4,2,
  4,14,6,10,2,4,6,8,6,6,4,6,8,4,8,10,2,10,2,6,4,6,8,4,2,4,12,8,4,8,4,6,
  12,2,18,6,10,6,6,2,6,10,6,6,2,6,6,4,2,12,10,2,4,6,6,2,12,4,6,8,10,8,10,8,
  6,6,4,8,6,4,8,4,14,10,12,2,10,2,4,2,10,14,4,2,4,14,4,2,4,20,4,8,10,8,4,6,
  6,14,4,6,6,8,6,12
};

#define NUMBER_OF_PRIMES 167

void
prevprime (mpz_ptr p, mpz_srcptr n)
{
  int moduli[NUMBER_OF_PRIMES];
  long long difference;
  int i;
  unsigned prime_limit;
  long prime;
  mp_size_t pn;
  mp_bitcnt_t nbits;
  long incr;
  int aux;

  /* First handle tiny numbers */
  if (mpz_cmp_ui (n, 2) < 0)
    {
      mpz_set_ui (p, 2);
      return;
    }
  mpz_sub_ui (p, n, 1);
  mpz_setbit (p, 0);

  if (mpz_cmp_ui (p, 7) <= 0)
    return;

  prime_limit = NUMBER_OF_PRIMES - 1;

  for (;;)
    {
      /* FIXME: Compute lazily? */
      prime = 3;
      for (i = 0; i < prime_limit; i++)
	{
	  moduli[i] = mpz_fdiv_ui (p, prime);
	  prime += primegap[i];
	}
#define INCR_LIMIT -0x10000	/* deep science */

      for (difference = incr = 0; incr > INCR_LIMIT; difference -= 2)
	{
	  /* First check residues */
	  prime = 3;
	  for (i = 0; i < prime_limit; i++)
	    {
	      unsigned r;
	      /* FIXME: Reduce moduli + incr and store back, to allow for
		 division-free reductions.  Alternatively, table primes[]'s
		 inverses (mod 2^16).  */
	      r = (moduli[i] + incr) % prime;
              printf("%ld %ld %u\n", prime, incr, r);
	      prime += primegap[i];

	      if (r == 0)
		goto next;
	    }
	  mpz_sub_ui (p, p, -difference);
	  difference = 0;

	  /* Miller-Rabin test */
	  if (aux)
	    return;
	next:;
	  incr -= 2;
	}
      mpz_sub_ui (p, p, -difference);
      difference = 0;
    }
}

void get_primegap(mpz_ptr g, mpz_srcptr n) {
  mpz_t prev;
  mpz_init(prev);
  mpz_nextprime(g, n);
  prevprime(prev, n);
  mpz_sub(g, g, prev);
  mpz_clear(prev);
}

void main() {
  mpz_t n, gap;
  mpz_init(n);
  mpz_init(gap);
  while (mpz_inp_str(n, stdin, 10)) {
    get_primegap(gap, n);
    mpz_out_str(stdout, 10, gap);
    printf("\n");
  }
}
