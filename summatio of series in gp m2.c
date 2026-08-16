#include <stdio.h>

int main() {
    int a, r, n, i;
    int term, sum = 0;

    printf("Enter first term: ");
    scanf("%d", &a);

    printf("Enter common ratio: ");
    scanf("%d", &r);

    printf("Enter number of terms: ");
    scanf("%d", &n);

    term = a;

    for (i = 1; i <= n; i++) {
        sum = sum + term;
        term = term * r;
    }

    printf("Sum of GP = %d", sum);

    return 0;
}
