#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n, resto;

    scanf("%d", &n);

    while(n/2 != 0){
        resto = n%2;
        printf("Q: %d\nR: %d\n", n, resto);
        n /= 2;
    }
    printf("Q: %d\nR: %d\n", n, resto);

    return;
}