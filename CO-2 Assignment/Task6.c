#include <stdio.h>
int main(void) {     long long balance, repayment, total_interest = 0;     double rate_percent;     int month = 0, limit = 360;
    printf("Principal in paise: ");
    if (scanf("%lld", &balance) != 1 || balance <= 0) return 1;     printf("Monthly interest rate (percent): ");     if (scanf("%lf", &rate_percent) != 1 ||
        rate_percent < 0.0 || rate_percent > 100.0) return 1;     printf("Fixed monthly repayment in paise: ");
    if (scanf("%lld", &repayment) != 1 || repayment <= 0) return 1;
    while (balance > 0 && month < limit) {         long long interest =             (long long)(balance * (rate_percent / 100.0) + 0.5);         long long due = balance + interest;         long long paid;
        if (repayment <= interest) {             printf("Repayment is not greater than monthly interest.\n");             return 1;         }
        paid = repayment < due ? repayment : due;         balance = due - paid;         total_interest += interest;         ++month;
        printf("Month %d: interest=%lld paise, paid=%lld paise, "                "balance=%lld paise\n", month, interest, paid, balance);     }
    if (balance == 0) {         printf("Loan repaid in %d months.\n", month);         printf("Total interest: %lld paise\n", total_interest);     } else {         printf("Safety limit reached; remaining balance=%lld paise\n", balance);     }     return 0; }
 