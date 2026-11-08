#include <stdio.h>
unsigned long checks; int prime_original(unsigned long n) {     checks = 0;     if (n < 2) return 0;     for (unsigned long i = 2; i < n; ++i) {         ++checks;         if (n % i == 0) return 0;     }     return 1; }
int prime_for(unsigned long n) {
    checks = 0;     if (n < 2) return 0;
    for (unsigned long i = 2; i <= n / i; ++i) {         ++checks;         if (n % i == 0) return 0;     }     return 1; }
int prime_while(unsigned long n) {     unsigned long i = 2;     checks = 0;     if (n < 2) return 0;     while (i <= n / i) {         ++checks;         if (n % i == 0) return 0;         ++i;     }     return 1; }
int prime_do(unsigned long n) {     unsigned long i = 2;     checks = 0;     if (n < 2) return 0;     do {         if (i > n / i) break;
        ++checks;
        if (n % i == 0) return 0;         ++i;     } while (i <= n / i);     return 1; } int main(void) {     unsigned long values[] = {97, 100, 7919, 1000003};     for (int k = 0; k < 4; ++k) {         int result = prime_for(values[k]);         printf("%lu %s divisions = %lu\n", values[k],                result ? "prime" : "not prime", checks);     }     return 0; }
