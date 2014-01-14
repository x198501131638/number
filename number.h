#ifndef NUMBER_H
#define NUMBER_H

#define no_min(first, second) (first < second ? first : second)
#define no_max(first, second) (first > second ? first : second)
#define no_gcd(first, second) ({ \
  long int a = first, b = second, c = 0; \
  while (b != 0) \
  { \
    c = a % b; \
    a = b; \
    b = c; \
  } \
  a; \
})

#endif
