#include <stdio.h>
int main(void) {
    double price, gross, discount, taxable, gst, total, net;     int qty, senior;
    printf("Enter price and quantity: ");
    if (scanf("%lf %d", &price, &qty) != 2 || price < 0 || qty < 0)         return 1;
    printf("Senior citizen? (1=yes, 0=no): ");
    if (scanf("%d", &senior) != 1 || (senior != 0 && senior != 1))         return 1;
    gross = price * qty;
    discount = senior ? gross * 15.0 / 100.0 : 0.0;     taxable = gross - discount;     gst = taxable * 5.0 / 100.0;     total = taxable + gst;     net = total > 1000.0 ? total - 50.0 : total;
    printf("Gross amount: Rs %.2f\n", gross);     printf("Discount: Rs %.2f\n", discount);     printf("GST: Rs %.2f\n", gst);     printf("Total: Rs %.2f\n", total);     printf("Net payable: Rs %.2f\n", net);  
    
    return 0; }
