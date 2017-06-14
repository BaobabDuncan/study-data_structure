#include <stdio.h>

double factorial_1(int n){
    if (n < 2) return 1;
    return n * factorial_1(n -1);
}

double data[5000] = {0,};
double factorial_2(int n){
    if (n < 2) return 1;
    if (data[n] == 0) {
        return data[n] = (n * factorial_2(n - 1));
    }
    return data[n];
}

int main() {
    printf("%lf \n", factorial_1(10));
    printf("%lf \n", factorial_2(10));
    return 0;
}