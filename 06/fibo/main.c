#include <stdio.h>

double fibo_1(int n) {
    if (n < 2) return n;
    return fibo_1(n - 1) + fibo_1(n - 2);
}

double data[100] = {-1,};

double fibo_2(int n) {
    if (n < 2) data[n] = n;
    else if (data[n] == 0) {
        data[n] = fibo_2(n -1)+ fibo_2(n -2);
    }
    return data[n];
}

int main() {
    printf("%lf\n", fibo_1(15));
    printf("%lf\n", fibo_2(15));
    return 0;
}