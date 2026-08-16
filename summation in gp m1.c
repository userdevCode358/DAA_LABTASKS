#include <stdio.h>
#include <math.h>

int main() {
    float a, r, sum;
    int n;

    printf("Enter first term: ");
    scanf("%f", &a);

    printf("Enter common ratio: ");
    scanf("%f", &r);

    printf("Enter number of terms: ");
    scanf("%d", &n);

    if (r == 1) {
        sum = a * n;
    } else {
        sum = a * (pow(r, n) - 1) / (r - 1);
    }

    printf("Sum of GP = %.2f", sum);

    return 0;
}
