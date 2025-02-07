#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_STATES 10
#define MAX_CHARS 128

typedef enum {
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_INVALID
} TokenType;

int transition_table[MAX_STATES][MAX_CHARS];

void initialize_table() {
    memset(transition_table, -1, sizeof(transition_table));
    
    for (int i = 'a'; i <= 'z'; i++) transition_table[0][i] = 1; // Identifiers
    for (int i = 'A'; i <= 'Z'; i++) transition_table[0][i] = 1;
    transition_table[0]['_'] = 1;
    for (int i = '0'; i <= '9'; i++) transition_table[0][i] = 2; // Numbers
    transition_table[0]['+'] = transition_table[0]['-'] = transition_table[0]['*'] = transition_table[0]['/'] = 3; // Operators
    
    for (int i = 'a'; i <= 'z'; i++) transition_table[1][i] = 1;
    for (int i = 'A'; i <= 'Z'; i++) transition_table[1][i] = 1;
    for (int i = '0'; i <= '9'; i++) transition_table[1][i] = 1;
    transition_table[1]['_'] = 1;
    
    
    for (int i = '0'; i <= '9'; i++) transition_table[2][i] = 2;
}

TokenType get_token_type(const char *token) {
    if (isalpha(token[0]) || token[0] == '_') return TOKEN_IDENTIFIER;
    if (isdigit(token[0])) return TOKEN_NUMBER;
    if (strchr("+-*/", token[0]) != NULL) return TOKEN_OPERATOR;
    return TOKEN_INVALID;
}

void tokenize(const char *input) {
    int state = 0;
    char token[256];
    int token_index = 0;

    printf("\nTokenizing: %s\n", input);

    for (int i = 0; input[i] != '\0'; i++) {
        char c = input[i];
        int next_state = transition_table[state][(int)c];

        if (next_state != -1) {
            token[token_index++] = c;
            state = next_state;
        } else {
            token[token_index] = '\0';
            if (token_index > 0) {
                TokenType type = get_token_type(token);
                printf("Token: %-10s Type: %d\n", token, type);
            }
            token_index = 0;
            state = 0;
            i--;
        }
    }

    if (token_index > 0) {
        token[token_index] = '\0';
        TokenType type = get_token_type(token);
        printf("Token: %-10s Type: %d\n", token, type);
    }
}
int main() {
    initialize_table();
    
    char input[256];
    printf("Enter input string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; 
    tokenize(input);
    return 0;
}
