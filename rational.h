#ifndef RATIONAL_H
#define RATIONAL_H

#include <stdio.h>
#include <stdlib.h>
#include "number.h"

#define no_simplify_rational(rational) ({ \
  long int gcd = no_gcd(rational->numerator, rational->denominator); \
  if (gcd != 1) \
  { \
    rational->numerator = rational->numerator / gcd; \
    rational->denominator = rational->denominator / gcd; \
  } \
  rational; \
})  

struct no_rational
{
  long int numerator;
  long int denominator;
};

struct no_rational *no_create_rational(long int numerator, long int denominator);
struct no_rational *no_add_rationals(struct no_rational *first, struct no_rational *second);
struct no_rational *no_substract_rationals(struct no_rational *first, struct no_rational *second);
struct no_rational *no_multiply_rationals(struct no_rational *first, struct no_rational *second);
struct no_rational *no_divide_rationals(struct no_rational *first, struct no_rational *second);
struct no_rational *no_center_rationals(struct no_rational *first, struct no_rational *second);
int no_compare_rationals(struct no_rational *first, struct no_rational *second);

#endif
