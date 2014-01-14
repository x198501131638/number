#include <assert.h>
#include "../rational.h"

struct no_rational *new = 0;
int result = 0;

void run_create_rational(void)
{
  new = no_create_rational(0x5, 0x0);
  assert(new->numerator == 0x5);
  assert(new->denominator == 0x0);

  new = no_create_rational(0x0, 0x5);
  assert(new->numerator == 0x0);
  assert(new->denominator == 0x5);

  new = no_create_rational(0x2, 0x4);
  assert(new->numerator == 0x2);
  assert(new->denominator == 0x4);

  new = no_create_rational(0x6, 0x4);
  assert(new->numerator == 0x6);
  assert(new->denominator == 0x4);

  new = no_create_rational(0x9, 0x1);
  assert(new->numerator == 0x9);
  assert(new->denominator == 0x1);

  new = no_create_rational(0xF, 0x1);
  assert(new->numerator == 0xF);
  assert(new->denominator == 0x1);

  new = no_create_rational(0x10, 0x8);
  assert(new->numerator == 0x10);
  assert(new->denominator == 0x8);
}

void run_add_rationals(void)
{
  new = no_add_rationals(no_create_rational(0x1, 0x2), no_create_rational(0x2, 0x5));
  assert(new->numerator == 0x9);
  assert(new->denominator == 0xA);
}

void run_substract_rationals(void)
{
  new = no_substract_rationals(no_create_rational(0x3, 0x4), no_create_rational(0x1, 0x5));
  assert(new->numerator == 0xB);
  assert(new->denominator == 0x14);
}

void run_multiply_rationals(void)
{
  new = no_multiply_rationals(no_create_rational(0x1, 0x2), no_create_rational(0x2, 0x5));
  assert(new->numerator == 0x2);
  assert(new->denominator == 0xA);
}

void run_divide_rationals(void)
{
  new = no_divide_rationals(no_create_rational(0x1, 0x2), no_create_rational(0x1, 0x6));
  assert(new->numerator == 0x6);
  assert(new->denominator == 0x2);
}

void run_center_rationals(void)
{
  new = no_center_rationals(no_create_rational(0x2, 0x1), no_create_rational(0x4, 0x1));
  assert(new->numerator == 0x3);
  assert(new->denominator == 0x1);
}

void run_compare_rationals(void)
{
  result = no_compare_rationals(no_create_rational(0x1, 0x1), no_create_rational(0x2, 0x1));
  assert(result == -1);

  result = no_compare_rationals(no_create_rational(0x2, 0x1), no_create_rational(0x1, 0x1));
  assert(result == +1);

  result = no_compare_rationals(no_create_rational(0x1, 0x1), no_create_rational(0x1, 0x1));
  assert(result == 0);
}

int main(void)
{
  run_create_rational();
  run_add_rationals();
  run_substract_rationals();
  run_multiply_rationals();
  run_divide_rationals();
  run_center_rationals();
  run_compare_rationals();

  return 0;
}
