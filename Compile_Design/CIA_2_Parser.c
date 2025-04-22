#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// E → TQ  
// Q → +TQ | -TQ | ε  
// T → FR  
// R → *FR | /FR | ε  
// F → (E) | i

#define MAX_RULES 10          // MAX grammar rules
#define MAX_SYMBOLS 10        // MAX symbols
#define MAX_TERMINALS 10      // MAX terminals
#define MAX_NONTERMINALS 10   // MAX non-terminals
typedef struct {
    char lhs;                   // LHS - NON TERMINAL
    char rhs[MAX_SYMBOLS][MAX_SYMBOLS];  // RHS
    int num_productions;        // No of productions
} Rule;

typedef struct {
    char non_terminal;          // Non-terminal symbol
    char terminal;              // Terminal symbol
    char production[MAX_SYMBOLS]; // Production to apply
} TableEntry;

Rule grammar[MAX_RULES];        // Grammar arrays rules
int num_rules = 0;             // curr rules

char terminals[MAX_TERMINALS] = {'i', '+', '-', '*', '/', '(', ')', '$'};
int num_terminals = 8;         // No of terminals

char non_terminals[MAX_NONTERMINALS] = {'E', 'T', 'F'};
int num_non_terminals = 3;     // No of non-terminals

TableEntry parsing_table[MAX_NONTERMINALS * MAX_TERMINALS]; // Parsing table
int num_table_entries = 0;     // No. of entries in parsing table

char stack[100];               // Stack array
int top = -1;                  // Stack top pointer

void initializeGrammar();
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

int main() {
    initializeGrammar();
    printf("Grammar Rules:\n");
    printGrammar();
    
    // Create the LL(1) parsing table
    createParsingTable();
    printf("\nParsing Table:\n");
    printParsingTable();
    
    // Get input string from user and parse it
    char input[100];
    printf("\nEnter input string to parse (e.g., i+i*i$): ");
    scanf("%s", input);
    
    printf("\nParsing steps for input '%s':\n", input);
    parseInput(input);
    
    return 0;
}

void initializeGrammar() {
    // Rule 1: E -> TQ (where Q represents E')
    grammar[0].lhs = 'E';
    strcpy(grammar[0].rhs[0], "TQ");
    grammar[0].num_productions = 1;
    
    // Rule 2: Q -> +TQ | -TQ | ε
    grammar[1].lhs = 'Q';
    strcpy(grammar[1].rhs[0], "+TQ");  // Addition
    strcpy(grammar[1].rhs[1], "-TQ");  // Subtraction
    strcpy(grammar[1].rhs[2], "");     // Epsilon production
    grammar[1].num_productions = 3;
    
    // Rule 3: T -> FR (where R represents T')
    grammar[2].lhs = 'T';
    strcpy(grammar[2].rhs[0], "FR");
    grammar[2].num_productions = 1;
    
    // Rule 4: R -> *FR | /FR | ε
    grammar[3].lhs = 'R';
    strcpy(grammar[3].rhs[0], "*FR");  // Multiplication
    strcpy(grammar[3].rhs[1], "/FR");  // Division
    strcpy(grammar[3].rhs[2], "");     // Epsilon production
    grammar[3].num_productions = 3;
    
    // Rule 5: F -> (E) | i
    grammar[4].lhs = 'F';
    strcpy(grammar[4].rhs[0], "(E)");  // Parenthesized expression
    strcpy(grammar[4].rhs[1], "i");    // Identifier
    grammar[4].num_productions = 2;
    
    num_rules = 5;  // Total number of rules
}

/* ========== GRAMMAR DISPLAY ========== */
// Print all grammar rules
void printGrammar() {
    for (int i = 0; i < num_rules; i++) {
        printf("%c -> ", grammar[i].lhs);
        for (int j = 0; j < grammar[i].num_productions; j++) {
            printf("%s", grammar[i].rhs[j]);
            if (j != grammar[i].num_productions - 1) {
                printf(" | ");
            }
        }
        printf("\n");
    }
}

// Add an entry to the parsing table
void addToTable(char non_term, char term, char *prod) {
    parsing_table[num_table_entries].non_terminal = non_term;
    parsing_table[num_table_entries].terminal = term;
    strcpy(parsing_table[num_table_entries].production, prod);
    num_table_entries++;
}

// Create the LL(1) parsing table
void createParsingTable() {
    // for E -> TQ
    addToTable('E', 'i', "TQ");   // E can start with 'i'
    addToTable('E', '(', "TQ");   // E can start with '('
    
    // for Q -> +TQ | -TQ | ε
    addToTable('Q', '+', "+TQ");  // On '+', choose +TQ
    addToTable('Q', '-', "-TQ");  // On '-', choose -TQ
    addToTable('Q', ')', "");     // On ')', choose ε (empty)
    addToTable('Q', '$', "");     // On '$', choose ε (empty)
    
    // for T -> FR
    addToTable('T', 'i', "FR");   // T can start with 'i'
    addToTable('T', '(', "FR");   // T can start with '('
    
    // for R -> *FR | /FR | ε
    addToTable('R', '*', "*FR");  // On '*', choose *FR
    addToTable('R', '/', "/FR");  // On '/', choose /FR
    addToTable('R', '+', "");     // On '+', choose ε
    addToTable('R', '-', "");     // On '-', choose ε
    addToTable('R', ')', "");     // On ')', choose ε
    addToTable('R', '$', "");     // On '$', choose ε
    
    // for F -> (E) | i
    addToTable('F', '(', "(E)");  // On '(', choose (E)
    addToTable('F', 'i', "i");    // On 'i', choose i
}

void printParsingTable() {
    printf("Non-terminal\tTerminal\tProduction\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i < num_table_entries; i++) {
        printf("%c\t\t%c\t\t%s\n", 
               parsing_table[i].non_terminal,
               parsing_table[i].terminal,
               parsing_table[i].production);
    }
}

// Parse input string using LL(1) parsing table
void parseInput(char *input) {
    // Initialize stack with $ and start symbol E
    push('$');
    push('E');
    
    int input_ptr = 0;            // Input pointer
    char current_input = input[input_ptr]; // Current input symbol
    
    printf("Stack\t\tInput\t\tAction\n");
    printf("--------------------------------------------\n");
    
    // Continue parsing until stack is empty
    while (stackTop() != '$') {
        // Print current parsing state
        printStack();
        printf("\t\t");
        printRemainingInput(input, input_ptr);
        printf("\t\t");
        
        char top = stackTop();    // Get top of stack
        
        if (top == current_input) {
            // Terminal match - pop and advance input
            printf("Match '%c'\n", top);
            pop();
            input_ptr++;
            current_input = input[input_ptr];
        } else if (isTerminal(top)) {
            // Terminal mismatch - syntax error
            printf("\nError: Terminal mismatch. Expected '%c', found '%c'\n", 
                   top, current_input);
            exit(1);
        } else {
            // Non-terminal - use parsing table
            char *production = findProduction(top, current_input);
            if (production == NULL) {
                // No production found - syntax error
                printf("\nError: No production for %c on input '%c'\n", 
                       top, current_input);
                exit(1);
            }
            
            printf("Apply %c -> %s\n", top, production);
            
            // Replace non-terminal with production
            pop();
            
            // Push production symbols in reverse order
            if (strlen(production) > 0) {
                for (int i = strlen(production) - 1; i >= 0; i--) {
                    push(production[i]);
                }
            }
        }
    }
    
    // Check if entire input was consumed
    if (current_input != '$') {
        printf("\nError: Input not fully consumed\n");
        exit(1);
    }
    
    printf("$\t\t$\t\tAccept\n");
    printf("\nInput successfully parsed!\n");
}

// Find production for given non-terminal and terminal
char* findProduction(char non_term, char term) {
    for (int i = 0; i < num_table_entries; i++) {
        if (parsing_table[i].non_terminal == non_term && 
            parsing_table[i].terminal == term) {
            return parsing_table[i].production;
        }
    }
    return NULL;  // No production found
}

// Push into stack
void push(char c) {
    if (c == '\0') return; 
    stack[++top] = c;
}

// Pop from stack
char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

// Get top of stack
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