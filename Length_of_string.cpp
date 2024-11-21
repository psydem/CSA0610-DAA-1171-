#include <stdio.h>

int stringLength(char str[]) {
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    printf("Length of the string: %d\n", stringLength(str));
    return 0;
}

