#include <stdio.h>
#include <string.h>

int simulateDFA(const char *input) {
    int state = 0;
    int length = strlen(input);

    for (int i = 0; i < length; i++) {
        char c = input[i];

        switch (state) {
            case 0:
                if (c == 'a') state = 1;
                else if (c == 'b') state = 0;
                else return 0;
                break;

            case 1:
                if (c == 'a') state = 1;
                else if (c == 'b') state = 2;
                else return 0;
                break;

            case 2:
                if (c == 'a' || c == 'b') state = 2;
                else return 0;
                break;

            default:
                return 0;
        }
    }

    return (state == 2);
}

int main() {
    char input[100];

    while (1) {
        printf("\nEnter a string (a, b) or type 'exit' to quit: ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) break;

        if (simulateDFA(input)) {
            printf("Accepted\n");
        } else {
            printf("Rejected\n");
        }
    }

    return 0;
}
