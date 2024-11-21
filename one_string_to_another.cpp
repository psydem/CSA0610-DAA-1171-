#include <stdio.h>
#include <string.h>

void copyString(char source[], char destination[], int index) {
    if (source[index] == '\0') {
        destination[index] = '\0';
        return;
    }
    destination[index] = source[index];
    copyString(source, destination, index + 1);
}

int main() {
    char source[100], destination[100];
    printf("Enter a string to copy: ");
    scanf("%s", source);

    copyString(source, destination, 0);
    printf("Copied string: %s\n", destination);
    return 0;
}

