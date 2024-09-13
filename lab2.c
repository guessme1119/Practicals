#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else
        return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    for (i = 0; i < strlen(infix); i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else {
            while (top != -1 && precedence(infix[i]) <= precedence(stack[top])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}