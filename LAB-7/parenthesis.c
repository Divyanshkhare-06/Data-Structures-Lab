#include <stdio.h>
#include <stdlib.h>
struct BracketNode {
    char symbol;
    struct BracketNode *next;
};
struct BracketNode *stackTop = NULL;
void pushBracket(char ch) {
    struct BracketNode *newNode = (struct BracketNode *)malloc(sizeof(struct BracketNode));
    newNode->symbol = ch;
    newNode->next = stackTop;
    stackTop = newNode;
}
void popBracket() {
    if (stackTop == NULL) return;
    struct BracketNode *temp = stackTop;
    stackTop = stackTop->next;
    free(temp);
}
int checkBracketsBalanced(char expr[], int len) {
    for (int i = 0; i < len; i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            pushBracket(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (stackTop == NULL) {
                return 0;
            }
            char topSymbol = stackTop->symbol;
            if ((ch == ')' && topSymbol == '(') ||
                (ch == '}' && topSymbol == '{') ||
                (ch == ']' && topSymbol == '[')) {
                popBracket();
            } else {
                return 0;
            }
        }
    }
    return (stackTop == NULL);
}
int main() {
    char input[100];
    int length;

    printf("Enter number of characters in the expression: ");
    scanf("%d", &length);
    getchar(); 

    printf("Enter the expression: ");
    for (int i = 0; i < length; i++) {
        scanf(" %c", &input[i]); 
    }
    input[length] = '\0';
    int isValid = checkBracketsBalanced(input, length);
    while (stackTop != NULL) {
        popBracket();
    }
    if (isValid) {
        printf("Brackets are balanced.\n");
    } else {
        printf("Brackets are not balanced.\n");
    }

    return 0;
}
