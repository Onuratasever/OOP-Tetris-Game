#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Constants for keyword and operator strings
#define KW_AND "and"
#define KW_OR "or"
#define KW_NOT "not"
#define KW_EQUAL "equal"
#define KW_LESS "less"
#define KW_NIL "nil"
// ... Define the remaining keywords and operators

// Control variables
int DFA = 0;
int control = 2;
int isInteger = 0;
int isOperator = 0;
int isKEYorID = 0;
int isIdentifier = 0;
int isDblmult = 0;
int isMult = 0;
int isComment = 0;

char token_key_id[256] = ""; // Adjust the size as needed
char token_int[256] = ""; // Adjust the size as needed
char token_operator[256] = ""; // Adjust the size as needed
char token_mult[256] = ""; // Adjust the size as needed
char token_comment[256] = ""; // Adjust the size as needed

void gppinterpreter();
void gpplexer(char *filename, int control);
void split_terminal_command(char *terCom);
void gpp_lexer_helper(char chr, char *input);
void readfile_for_command(FILE *file);
void print_lexer(char *token);
void testLexicalAnalyzer();

int main() {
    testLexicalAnalyzer();
    return 0;
}

void gppinterpreter() {
    printf("> ");
    char terCom[256]; // Adjust the size as needed
    fgets(terCom, sizeof(terCom), stdin);
    split_terminal_command(terCom);
}

void gpplexer(char *filename, int control) {
    // Implement the lexer logic for C here
    // You will need to read the file and tokenize the input

    // Example:
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        // Handle file open error
        return;
    }

    // Implement tokenization logic here
    // You can use fgets or fgetc to read characters from the file

    // Don't forget to close the file when done
    fclose(file);
}

void split_terminal_command(char *terCom) {
    // Implement the split_terminal_command function in C
    // You will need to parse the terminal command string

    // Example:
    if (strcmp(terCom, "$ g++") == 0) {
        // Handle the "$ g++" command
    } else if (strstr(terCom, "$ g++ ") != NULL) {
        // Handle the "$ g++ filename" command
    } else {
        // Handle invalid commands
    }
}

void gpp_lexer_helper(char chr, char *input) {
    // Implement the lexer helper logic in C
    // You will need to tokenize the input based on the rules

    // Example:
    if (isdigit(chr)) {
        // Handle integer characters
    } else if (isalpha(chr)) {
        // Handle identifier/keyword characters
    } else {
        // Handle operators, comments, and other characters
    }
}

void readfile_for_command(FILE *file) {
    // Implement the readfile_for_command function in C
    // You will need to skip a line after encountering a COMMENT keyword
}

void print_lexer(char *token) {
    // Implement the print_lexer function in C
    // You will need to print the token types

    // Example:
    if (isOperator) {
        if (strcmp(token, "+") == 0) {
            printf("OP_PLUS\n");
        } else if (strcmp(token, "-") == 0) {
            printf("OP_MINUS\n");
        } // Add more operator cases
    } else if (isDblmult && strcmp(token, "**") == 0) {
        printf("OP_DBLMULT\n");
    } // Add more cases for keywords, integers, etc.
}

void testLexicalAnalyzer() {
    printf("Enter '$ g++' to open terminal.\n");
    printf("Enter '$ g++ filename.g++' to execute on a file.\n\n");
    gppinterpreter();
}