#include<stdio.h>
void change(float m, int* q, int* d, int* n, int* p);
void main() {
    float money = 0.88;
    int quarters = 0, dimes = 0, nickels = 0, pennis = 0;
    change(money, &quarters, &dimes, &nickels, &pennis);
    printf("quarters : %d\ndimes : %d\nnickels : %d\npennis : %d\n", quarters, dimes, nickels, pennis);
}
void change(float m, int* q, int* d, int* n, int* p) {
    if (m >= 0.25) {
        *q = m / 0.25f;
        m = m - (0.25f * *q);
    }
    printf("%f ", m);
    if (m >= 0.10) {
        *d = m / 0.10f;
        m = m - (0.10f * *d);
    }
    printf("%f ", m);
    if (m >= 0.05) {
        *n = m / 0.05f;
        m = m - (0.05f * *n);
    }
    printf("%f ", m);
    if (m >= 0.01) {
        *p = m / 0.01f;
        m = m - (0.01f * (float)(*p));
    }
    printf("%f \n", m);
}