#include <stdio.h>
unsigned long checks_original, checks_redesigned;
int original_prime(unsigned long n) {     checks_original = 0;     if (n < 2) return 0;
    for (unsigned long i = 2; i < n; ++i) {         ++checks_original;         if (n % i == 0) return 0;     }     return 1; } int redesigned_prime(unsigned long n) {
    checks_redesigned = 0;     if (n < 2) return 0;     for (unsigned long i = 2; i <= n / i; ++i) {         ++checks_redesigned;         if (n % i == 0) return 0;     }     return 1; } int main(void) {     unsigned long tests[] = {97, 100, 7919, 1000003};     for (int i = 0; i < 4; ++i) {         int a = original_prime(tests[i]);         int b = redesigned_prime(tests[i]);
        printf("%lu: original=%s (%lu checks), redesigned=%s (%lu checks)\n",                tests[i], a ? "prime" : "not prime", checks_original,                b ? "prime" : "not prime", checks_redesigned);     }     return 0; }
