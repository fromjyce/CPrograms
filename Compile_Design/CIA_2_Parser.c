#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* ========== CONSTANTS AND MACROS ========== */
#define MAX_RULES 10          // Maximum number of grammar rules
#define MAX_SYMBOLS 10        // Maximum symbols in a production
#define MAX_TERMINALS 10      // Maximum terminal symbols
#define MAX_NONTERMINALS 10   // Maximum non-terminal symbols

/* ========== DATA STRUCTURES ========== */

// Structure to represent a grammar rule
typedef struct {
    char lhs;                   // Left-hand side (non-terminal)
    char rhs[MAX_SYMBOLS][MAX_SYMBOLS];  // Right-hand side productions
    int num_productions;        // Number of productions for this non-terminal
} Rule;

// Structure for parsing table entries
typedef struct {
    char non_terminal;          // Non-terminal symbol
    char terminal;              // Terminal symbol
    char production[MAX_SYMBOLS]; // Production to apply
} TableEntry;

/* ========== GLOBAL VARIABLES ========== */
Rule grammar[MAX_RULES];        // Array to store grammar rules
int num_rules = 0;             // Current number of rules

// Terminal symbols in the grammar
char terminals[MAX_TERMINALS] = {'i', '+', '-', '*', '/', '(', ')', '$'};
int num_terminals = 8;         // Number of terminals

// Non-terminal symbols in the grammar
char non_terminals[MAX_NONTERMINALS] = {'E', 'T', 'F'};
int num_non_terminals = 3;     // Number of non-terminals

TableEntry parsing_table[MAX_NONTERMINALS * MAX_TERMINALS]; // Parsing table
int num_table_entries = 0;     // Number of entries in parsing table

// Stack for predictive parsing
char stack[100];               // Stack array
int top = -1;                  // Stack top pointer

/* ========== FUNCTION PROTOTYPES ========== */
void initializeGrammar();       // Initialize grammar rules
void printGrammar();           // Print grammar rules
void addToTable(char non_term, char term, char *prod); // Add entry to parsing table
void createParsingTable();      // Build the LL(1) parsing table
void printParsingTable();       // Display parsing table
void parseInput(char *input);   // Parse input string
void push(char c);              // Push to stack
char pop();                     // Pop from stack
char stackTop();                // Get top of stack
bool isTerminal(char c);        // Check if symbol is terminal
bool isNonTerminal(char c);     // Check if symbol is non-terminal
void printStack();              // Print stack contents
void printRemainingInput(char *input, int ptr); // Print remaining input
char* findProduction(char non_term, char term); // Find production in parsing table

/* ========== MAIN FUNCTION ========== */
int main() {
    // Initialize the grammar with production rules
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

/* ========== GRAMMAR INITIALIZATION ========== */
// Initialize grammar with arithmetic expression rules
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
                printf(" | ");  // Separate productions with pipe
            }
        }
        printf("\n");
    }
}

/* ========== PARSING TABLE CONSTRUCTION ========== */
// Add an entry to the parsing table
void addToTable(char non_term, char term, char *prod) {
    parsing_table[num_table_entries].non_terminal = non_term;
    parsing_table[num_table_entries].terminal = term;
    strcpy(parsing_table[num_table_entries].production, prod);
    num_table_entries++;
}

// Create the LL(1) parsing table
void createParsingTable() {
    // Productions for E -> TQ
    addToTable('E', 'i', "TQ");   // E can start with 'i'
    addToTable('E', '(', "TQ");   // E can start with '('
    
    // Productions for Q -> +TQ | -TQ | ε
    addToTable('Q', '+', "+TQ");  // On '+', choose +TQ
    addToTable('Q', '-', "-TQ");  // On '-', choose -TQ
    addToTable('Q', ')', "");     // On ')', choose ε (empty)
    addToTable('Q', '$', "");     // On '$', choose ε (empty)
    
    // Productions for T -> FR
    addToTable('T', 'i', "FR");   // T can start with 'i'
    addToTable('T', '(', "FR");   // T can start with '('
    
    // Productions for R -> *FR | /FR | ε
    addToTable('R', '*', "*FR");  // On '*', choose *FR
    addToTable('R', '/', "/FR");  // On '/', choose /FR
    addToTable('R', '+', "");     // On '+', choose ε
    addToTable('R', '-', "");     // On '-', choose ε
    addToTable('R', ')', "");     // On ')', choose ε
    addToTable('R', '$', "");     // On '$', choose ε
    
    // Productions for F -> (E) | i
    addToTable('F', '(', "(E)");  // On '(', choose (E)
    addToTable('F', 'i', "i");    // On 'i', choose i
}

/* ========== PARSING TABLE DISPLAY ========== */
// Print the parsing table
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

/* ========== PREDICTIVE PARSING ========== */
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
    
    // Successful parse
    printf("$\t\t$\t\tAccept\n");
    printf("\nInput successfully parsed!\n");
}

/* ========== PARSING TABLE LOOKUP ========== */
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

/* ========== STACK OPERATIONS ========== */
// Push symbol onto stack
void push(char c) {
    if (c == '\0') return;  // Don't push empty string
    stack[++top] = c;
}

// Pop symbol from stack
char pop() {
    if (top == -1) return '\0';  // Stack underflow
    return stack[top--];
}

// Get top of stack without popping
char stackTop() {
    if (top == -1) return '\0';  // Empty stack
    return stack[top];
}

/* ========== HELPER FUNCTIONS ========== */
// Check if symbol is a terminal
bool isTerminal(char c) {
    for (int i = 0; i < num_terminals; i++) {
        if (terminals[i] == c) return true;
    }
    return false;
}

// Check if symbol is a non-terminal
bool isNonTerminal(char c) {
    for (int i = 0; i < num_non_terminals; i++) {
        if (non_terminals[i] == c) return true;
    }
    return false;
}

// Print current stack contents
void printStack() {
    for (int i = 0; i <= top; i++) {
        printf("%c", stack[i]);
    }
}

// Print remaining input string
void printRemainingInput(char *input, int ptr) {
    for (int i = ptr; input[i] != '\0'; i++) {
        printf("%c", input[i]);
    }
}