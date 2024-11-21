#include <stdio.h>

int reverseNumber(int n) {
    static int reverse = 0;
    if (n == 0)
        return reverse;
    reverse = reverse * 10 + (n % 10);
    return reverseNumber(n / 10);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Reverse of %d is %d\n", num, reverseNumber(num));
    return 0;
}

