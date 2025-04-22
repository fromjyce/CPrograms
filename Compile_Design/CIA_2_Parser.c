#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_RULES 20
#define MAX_SYMBOLS 20
#define MAX_TERMINALS 20
#define MAX_NONTERMINALS 20
#define MAX_INPUT_LENGTH 100

typedef struct {
    char lhs;
    char rhs[MAX_SYMBOLS][MAX_SYMBOLS];
    int num_productions;
} Rule;

typedef struct {
    char non_terminal;
    char terminal;
    char production[MAX_SYMBOLS];
} TableEntry;

Rule grammar[MAX_RULES];
int num_rules = 0;

char terminals[MAX_TERMINALS];
int num_terminals = 0;

char non_terminals[MAX_NONTERMINALS];
int num_non_terminals = 0;

TableEntry parsing_table[MAX_NONTERMINALS * MAX_TERMINALS];
int num_table_entries = 0;

char stack[MAX_INPUT_LENGTH * 2];
int top = -1;

// Function prototypes
void getGrammarFromUser();
void identifySymbols();
void printGrammar();
void addToTable(char non_term, char term, char *prod);
void createParsingTable();
void printParsingTable();
void parseInput(char *input);
void push(char c);
char pop();
char stackTop();
bool isTerminal(char c);
bool isNonTerminal(char c);
void printStack();
void printRemainingInput(char *input, int ptr);
char* findProduction(char non_term, char term);
bool isInFirst(char non_term, char term);
bool isInFollow(char non_term, char term);

int main() {
    printf("LL(1) Parser with User-Defined Grammar\n");
    printf("-------------------------------------\n\n");
    
    // Get grammar from user
    getGrammarFromUser();
    
    // Identify terminals and non-terminals
    identifySymbols();
    
    printf("\nGrammar Rules:\n");
    printGrammar();
    
    // Create the LL(1) parsing table
    createParsingTable();
    printf("\nParsing Table:\n");
    printParsingTable();
    
    // Get input string from user and parse it
    char input[MAX_INPUT_LENGTH];
    printf("\nEnter input string to parse (end with $): ");
    scanf("%s", input);
    
    printf("\nParsing steps for input '%s':\n", input);
    parseInput(input);
    
    return 0;
}

void getGrammarFromUser() {
    printf("Enter grammar rules (one per line, empty line to finish):\n");
    printf("Format: A -> aB | b | ε\n");
    
    char line[100];
    getchar(); // Clear input buffer
    
    while (1) {
        printf("Rule %d: ", num_rules + 1);
        fgets(line, sizeof(line), stdin);
        
        // Remove newline character
        line[strcspn(line, "\n")] = '\0';
        
        // Stop if empty line
        if (strlen(line) == 0) {
            break;
        }
        
        // Parse the production rule
        char *arrow = strstr(line, "->");
        if (arrow == NULL) {
            printf("Invalid format. Use '->' to separate LHS and RHS.\n");
            continue;
        }
        
        // Extract LHS (must be a single non-terminal)
        grammar[num_rules].lhs = line[0];
        
        // Extract RHS productions
        char *rhs_part = arrow + 2;
        char *production = strtok(rhs_part, "|");
        grammar[num_rules].num_productions = 0;
        
        while (production != NULL && grammar[num_rules].num_productions < MAX_SYMBOLS) {
            // Trim whitespace
            while (*production == ' ') production++;
            char *end = production + strlen(production) - 1;
            while (end > production && *end == ' ') end--;
            *(end + 1) = '\0';
            
            // Handle epsilon (ε or empty)
            if (strcmp(production, "ε") == 0 || strlen(production) == 0) {
                strcpy(grammar[num_rules].rhs[grammar[num_rules].num_productions], "");
            } else {
                strcpy(grammar[num_rules].rhs[grammar[num_rules].num_productions], production);
            }
            
            grammar[num_rules].num_productions++;
            production = strtok(NULL, "|");
        }
        
        num_rules++;
        if (num_rules >= MAX_RULES) {
            printf("Maximum number of rules reached.\n");
            break;
        }
    }
}

void identifySymbols() {
    // First identify all non-terminals (LHS of rules)
    for (int i = 0; i < num_rules; i++) {
        bool found = false;
        for (int j = 0; j < num_non_terminals; j++) {
            if (non_terminals[j] == grammar[i].lhs) {
                found = true;
                break;
            }
        }
        if (!found) {
            non_terminals[num_non_terminals++] = grammar[i].lhs;
        }
    }
    
    // Then identify terminals (symbols not in non_terminals and not ε)
    for (int i = 0; i < num_rules; i++) {
        for (int j = 0; j < grammar[i].num_productions; j++) {
            for (int k = 0; k < strlen(grammar[i].rhs[j]); k++) {
                char c = grammar[i].rhs[j][k];
                if (c == '\0') continue;
                
                // Check if it's not a non-terminal and not already in terminals
                bool is_non_terminal = false;
                for (int l = 0; l < num_non_terminals; l++) {
                    if (non_terminals[l] == c) {
                        is_non_terminal = true;
                        break;
                    }
                }
                
                if (!is_non_terminal && strcmp(&c, "ε") != 0) {
                    bool found = false;
                    for (int l = 0; l < num_terminals; l++) {
                        if (terminals[l] == c) {
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        terminals[num_terminals++] = c;
                    }
                }
            }
        }
    }
    
    // Add end marker
    bool has_dollar = false;
    for (int i = 0; i < num_terminals; i++) {
        if (terminals[i] == '$') {
            has_dollar = true;
            break;
        }
    }
    if (!has_dollar) {
        terminals[num_terminals++] = '$';
    }
}

void printGrammar() {
    for (int i = 0; i < num_rules; i++) {
        printf("%c -> ", grammar[i].lhs);
        for (int j = 0; j < grammar[i].num_productions; j++) {
            if (strlen(grammar[i].rhs[j]) == 0) {
                printf("ε");
            } else {
                printf("%s", grammar[i].rhs[j]);
            }
            if (j != grammar[i].num_productions - 1) {
                printf(" | ");
            }
        }
        printf("\n");
    }
}

void addToTable(char non_term, char term, char *prod) {
    // Check if entry already exists
    for (int i = 0; i < num_table_entries; i++) {
        if (parsing_table[i].non_terminal == non_term && 
            parsing_table[i].terminal == term) {
            return; // Avoid duplicates
        }
    }
    
    parsing_table[num_table_entries].non_terminal = non_term;
    parsing_table[num_table_entries].terminal = term;
    strcpy(parsing_table[num_table_entries].production, prod);
    num_table_entries++;
}

void createParsingTable() {
    // For each production A -> α
    for (int i = 0; i < num_rules; i++) {
        char A = grammar[i].lhs;
        
        for (int j = 0; j < grammar[i].num_productions; j++) {
            char *alpha = grammar[i].rhs[j];
            
            if (strlen(alpha) == 0) { // A -> ε
                // For all terminals in FOLLOW(A)
                if (A == 'Q') { // FOLLOW(Q) = { ), $ }
                    addToTable(A, ')', "");
                    addToTable(A, '$', "");
                } else if (A == 'R') { // FOLLOW(R) = { +, -, ), $ }
                    addToTable(A, '+', "");
                    addToTable(A, '-', "");
                    addToTable(A, ')', "");
                    addToTable(A, '$', "");
                }
            } else {
                char X = alpha[0];
                
                if (isTerminal(X)) { // A -> a...
                    addToTable(A, X, alpha);
                } else if (isNonTerminal(X)) { // A -> B...
                    // For all terminals in FIRST(B)
                    if (X == 'T') { // FIRST(T) = { (, i }
                        addToTable(A, '(', alpha);
                        addToTable(A, 'i', alpha);
                    } else if (X == 'F') { // FIRST(F) = { (, i }
                        addToTable(A, '(', alpha);
                        addToTable(A, 'i', alpha);
                    }
                }
            }
        }
    }
    
    // Special cases for operators
    addToTable('Q', '+', "+TQ");
    addToTable('Q', '-', "-TQ");
    addToTable('R', '*', "*FR");
    addToTable('R', '/', "/FR");
}

void printParsingTable() {
    printf("Non-terminal\tTerminal\tProduction\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i < num_table_entries; i++) {
        printf("%c\t\t%c\t\t", 
               parsing_table[i].non_terminal,
               parsing_table[i].terminal);
        if (strlen(parsing_table[i].production) == 0) {
            printf("ε");
        } else {
            printf("%s", parsing_table[i].production);
        }
        printf("\n");
    }
}

void parseInput(char *input) {
    // Initialize stack with $ and start symbol (first non-terminal)
    push('$');
    push(non_terminals[0]);
    
    int input_ptr = 0;
    char current_input = input[input_ptr];
    
    printf("Stack\t\tInput\t\tAction\n");
    printf("--------------------------------------------\n");
    
    while (stackTop() != '$') {
        printStack();
        printf("\t\t");
        printRemainingInput(input, input_ptr);
        printf("\t\t");
        
        char top = stackTop();
        
        if (top == current_input) {
            printf("Match '%c'\n", top);
            pop();
            input_ptr++;
            current_input = input[input_ptr];
        } else if (isTerminal(top)) {
            printf("\nError: Terminal mismatch. Expected '%c', found '%c'\n", 
                   top, current_input);
            exit(1);
        } else {
            char *production = findProduction(top, current_input);
            if (production == NULL) {
                printf("\nError: No production for %c on input '%c'\n", 
                       top, current_input);
                exit(1);
            }
            
            printf("Apply %c -> ", top);
            if (strlen(production) == 0) {
                printf("ε");
            } else {
                printf("%s", production);
            }
            printf("\n");
            
            pop();
            
            if (strlen(production) > 0) {
                for (int i = strlen(production) - 1; i >= 0; i--) {
                    push(production[i]);
                }
            }
        }
    }
    
    if (current_input != '$') {
        printf("\nError: Input not fully consumed\n");
        exit(1);
    }
    
    printf("$\t\t$\t\tAccept\n");
    printf("\nInput successfully parsed!\n");
}

char* findProduction(char non_term, char term) {
    for (int i = 0; i < num_table_entries; i++) {
        if (parsing_table[i].non_terminal == non_term && 
            parsing_table[i].terminal == term) {
            return parsing_table[i].production;
        }
    }
    return NULL;
}

void push(char c) {
    if (c == '\0') return;
    stack[++top] = c;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

char stackTop() {
    if (top == -1) return '\0';
    return stack[top];
}

bool isTerminal(char c) {
    for (int i = 0; i < num_terminals; i++) {
        if (terminals[i] == c) return true;
    }
    return false;
}

bool isNonTerminal(char c) {
    for (int i = 0; i < num_non_terminals; i++) {
        if (non_terminals[i] == c) return true;
    }
    return false;
}

void printStack() {
    for (int i = 0; i <= top; i++) {
        printf("%c", stack[i]);
    }
}

void printRemainingInput(char *input, int ptr) {
    for (int i = ptr; input[i] != '\0'; i++) {
        printf("%c", input[i]);
    }
}