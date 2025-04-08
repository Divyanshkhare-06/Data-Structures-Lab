#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct CharNode {
    char token;
    struct CharNode *next;
};

struct IntNode {
    int number;
    struct IntNode *next;
};

struct CharNode *charStack = NULL;
struct IntNode *intStack = NULL;

 
void pushChar(char ch) {
    struct CharNode *newNode = (struct CharNode *)malloc(sizeof(struct CharNode));
    newNode->token = ch;
    newNode->next = charStack;
    charStack = newNode;
}

void popChar() {
    if (charStack == NULL) return;
    struct CharNode *temp = charStack;
    charStack = charStack->next;
    free(temp);
}

void pushInt(int val) {
    struct IntNode *newNode = (struct IntNode *)malloc(sizeof(struct IntNode));
    newNode->number = val;
    newNode->next = intStack;
    intStack = newNode;
}

int popInt() {
    if (intStack == NULL) {
        printf("Error: Invalid postfix expression.\n");
        exit(1);
    }
    struct IntNode *temp = intStack;
    int value = temp->number;
    intStack = intStack->next;
    free(temp);
    return value;
}

int getPriority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void convertInfixToPostfix(char infix[], char postfix[], int len) {
    int j = 0;
    for (int i = 0; i < len; i++) {
        char ch = infix[i];
        if (isdigit(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            pushChar(ch);
        } else if (ch == ')') {
            while (charStack != NULL && charStack->token != '(') {
                postfix[j++] = charStack->token;
                popChar();
            }
            if (charStack != NULL) popChar(); // Remove '('
        } else {
            while (charStack != NULL && getPriority(charStack->token) >= getPriority(ch)) {
                postfix[j++] = charStack->token;
                popChar();
            }
            pushChar(ch);
        }
    }
    while (charStack != NULL) {
        postfix[j++] = charStack->token;
        popChar();
    }
    postfix[j] = '\0';
}

int evaluatePostfix(char postfix[]) {
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        if (isdigit(ch)) {
            pushInt(ch - '0'); 
        } else {
            int b = popInt();
            int a = popInt();
            switch (ch) {
                case '+': pushInt(a + b); break;
                case '-': pushInt(a - b); break;
                case '*': pushInt(a * b); break;
                case '/':
                    if (b == 0) {
                        printf("Error: Division by zero.\n");
                        exit(1);
                    }
                    pushInt(a / b);
                    break;
                default:
                    printf("Error: Unknown operator '%c'\n", ch);
                    exit(1);
            }
        }
    }

    int result = popInt();
    if (intStack != NULL) {
        printf("Error: Extra operands in postfix expression.\n");
        exit(1);
    }
    return result;
}

int main() {
    char infixExpr[100], postfixExpr[100];
    int length;

    printf("Enter the length of the infix expression: ");
    scanf("%d", &length);

    printf("Enter the infix expression (no spaces): ");
    for (int i = 0; i < length; i++) {
        scanf(" %c", &infixExpr[i]);  
    }
    infixExpr[length] = '\0';

    convertInfixToPostfix(infixExpr, postfixExpr, length);
    printf("Postfix expression: %s\n", postfixExpr);

    int finalResult = evaluatePostfix(postfixExpr);
    printf("Result: %d\n", finalResult);

    return 0;
}
