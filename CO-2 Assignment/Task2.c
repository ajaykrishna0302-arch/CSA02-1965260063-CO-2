#include <stdio.h>
static int verify_card(int card_valid, int *calls) {     ++*calls;                 /* represents a slow server check */     return card_valid; }
int main(void) {     int calls_a = 0, calls_b = 0, calls_nested = 0;     int passengers = 1000;
    int concessions_a = 0, concessions_b = 0, concessions_nested = 0;
    for (int i = 0; i < passengers; ++i) {         int senior = (i % 4 == 0);         int eligible = (i % 3 == 0);         int card = (i % 10 == 0);
        concessions_a += ((senior && eligible) ||                           verify_card(card, &calls_a));
        concessions_b += (verify_card(card, &calls_b) ||                           (senior && eligible));
        if (senior && eligible)             ++concessions_nested;
        else if (verify_card(card, &calls_nested))             ++concessions_nested;     }
    printf("Order A verification calls: %d\n", calls_a);     printf("Order B verification calls: %d\n", calls_b);     printf("Nested-if verification calls: %d\n", calls_nested);     printf("Concessions: %d, %d, %d\n",
           concessions_a, concessions_b, concessions_nested);     return 0; }
