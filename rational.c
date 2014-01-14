#include "./rational.h"

struct no_rational *no_create_rational(long int numerator, long int denominator)
{
  struct no_rational *new = (struct no_rational *) malloc(sizeof(struct no_rational));
  new->numerator = numerator;
  new->denominator = denominator;

  return new;
}

struct no_rational *no_add_rationals(struct no_rational *first, struct no_rational *second)
{
  return no_simplify_rational(
    no_create_rational(
      (first->numerator * second->denominator) + (first->denominator * second->numerator),
      (first->denominator * second->denominator)
    )
  );
}

struct no_rational *no_substract_rationals(struct no_rational *first, struct no_rational *second)
{
  return no_simplify_rational(
    no_create_rational(
      (first->numerator * second->denominator) - (first->denominator * second->numerator),
      (first->denominator * second->denominator)
    )
  );
}

struct no_rational *no_multiply_rationals(struct no_rational *first, struct no_rational *second)
{
  return no_simplify_rational(
    no_create_rational(
      (first->numerator * second->numerator),
      (first->denominator * second->denominator)
    )
  );
}

struct no_rational *no_divide_rationals(struct no_rational *first, struct no_rational *second)
{
  return no_simplify_rational(
    no_create_rational(
      (first->numerator * second->denominator),
      (first->denominator * second->numerator)
    )
  );
}

struct no_rational *no_center_rationals(struct no_rational *first, struct no_rational *second)
{
  struct no_rational *larger = 0, *smaller = 0;

  int result = no_compare_rationals(first, second);
  
  if (result == -1)
  {
    smaller = first;
    larger = second;
  }
  else
  if (result == +1)
  {
    larger = first;
    smaller = second;
  }
  else
  {
    return no_create_rational(first->numerator, first->denominator);
  }
  
  struct no_rational *difference = no_substract_rationals(larger, smaller);
  struct no_rational *two = no_create_rational(2, 1);
  struct no_rational *offset = no_divide_rationals(difference, two);
  struct no_rational *new = no_add_rationals(smaller, offset);

  free(difference);
  free(two);
  free(offset);

  return no_simplify_rational(new);
}

int no_compare_rationals(struct no_rational *first, struct no_rational *second)
{
  if ((first->numerator * second->denominator) < (first->denominator * second->numerator))
  {
    return -1;
  }

  if ((first->numerator * second->denominator) > (first->denominator * second->numerator))
  {
    return +1;
  }

  return 0;
}
