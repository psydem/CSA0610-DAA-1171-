#include <stdio.h>

int isPerfect(int n, int i) {
    if (i == 1)
        return 1;
    if (n % i == 0)
        return i + isPerfect(n, i - 1);
    return isPerfect(n, i - 1);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num == isPerfect(num, num / 2))
        printf("%d is a Perfect Number.\n", num);
    else
        printf("%d is not a Perfect Number.\n", num);
    return 0;
}

