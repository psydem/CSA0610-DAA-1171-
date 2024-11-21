#include <stdio.h>
#include <math.h>

int countDigits(int n) {
    if (n == 0)
        return 0;
    return 1 + countDigits(n / 10);
}

int armstrong(int n, int digits) {
    if (n == 0)
        return 0;
    int remainder = n % 10;
    return pow(remainder, digits) + armstrong(n / 10, digits);
}

int main() {
    int num, digits;
    printf("Enter a number: ");
    scanf("%d", &num);

    digits = countDigits(num);
    if (num == armstrong(num, digits)) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }
    return 0;
}

