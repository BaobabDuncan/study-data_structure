#include <stdio.h>

void hanoi_tower(int n, char from, char temp, char to){
    if (n == 1){
        printf("\n Move disk 1 from rod %c to rod %c", from, to);
    }else{
        hanoi_tower(n -1, from, to, temp);
        printf("\n Move disk %d from rod %c to rod %c", n, from, to);
        hanoi_tower(n -1, temp, to, from);
    };
}

int main() {
    char from = 'A';
    char temp = 'B';
    char to = 'C';
    hanoi_tower(2, from, temp, to);
    return 0;
}