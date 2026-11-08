#include <stdio.h>
enum { LIGHT = 0, FAN = 1, AC = 2, HEATER = 3, PUMP = 4 };
unsigned char switch_on(unsigned char reg, int dev) {     if (dev < 0 || dev > 7) return reg;     return (unsigned char)(reg | (1u << dev)); } unsigned char switch_off(unsigned char reg, int dev) {
    if (dev < 0 || dev > 7) return reg;     return (unsigned char)(reg & ~(1u << dev)); }
unsigned char toggle(unsigned char reg, int dev) {     if (dev < 0 || dev > 7) return reg;     return (unsigned char)(reg ^ (1u << dev)); } int is_on(unsigned char reg, int dev) {
    if (dev < 0 || dev > 7) return 0;     return (reg & (1u << dev)) != 0; }
void show(unsigned char reg) {
    for (int bit = 7; bit >= 0; --bit)         putchar(((reg >> bit) & 1u) ? '1' : '0');     putchar('\n'); } int count_on(unsigned char reg) {
    int count = 0;     for (int bit = 0; bit < 8; ++bit)         if (reg & (1u << bit)) ++count;     return count; } int main(void) {     unsigned char reg = 0;     reg = switch_on(reg, LIGHT);     reg = switch_on(reg, AC);     show(reg);                 /* 00000101 */     reg = toggle(reg, FAN);     reg = switch_off(reg, LIGHT);     show(reg);                 /* 00000110 */     printf("AC is %s, PUMP is %s\n",            is_on(reg, AC) ? "ON" : "OFF",            is_on(reg, PUMP) ? "ON" : "OFF");     printf("Devices ON: %d\n", count_on(reg));     return 0; }