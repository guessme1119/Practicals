#include <stdio.h>
#define MAX 100
int stack[MAX], top = -1;

void push(int x) { stack[++top] = x; }

int pop() { return stack[top--]; }

int peek() { return stack[top]; }

void traverse() { for (int i = 0; i <= top; i++) printf("%d ", stack[i]); }

int search(int x) {
    for (int i = 0; i <= top; i++)
        if (stack[i] == x) return i;
    return -1;
}

int main() {
    push(11); push(12); push(13);
    printf("Stack: "); traverse(); printf("\n");
    printf("Popped: %d\n", pop());
    printf("Top element: %d\n", peek());
    printf("Search 20: %d\n", search(20));
    return 0;
}
