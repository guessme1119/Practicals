#include <stdio.h>
#include <ctype.h>
#define MAX 100

int stack[MAX], top = -1;

void push(int x) { stack[++top] = x; }
int pop() { return stack[top--]; }

int evaluatePostfix(char* exp) {
    int i = 0, val1, val2;
    while (exp[i]) {
        if (isdigit(exp[i])) push(exp[i] - '0');
        else {
            val2 = pop(); val1 = pop();
            switch (exp[i]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
        i++;
    }
    return pop();
}

int main() {
    char exp[] = "231*+9-";
    printf("Result: %d", evaluatePostfix(exp));
    return 0;
}
