#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int *arr;
    int top;
} Stack;

void init(Stack *s, int size) {
    s->arr = (int *)malloc(size * sizeof(int));
    s->top = -1;
}

void push(Stack *s, int value) {
    s->arr[++(s->top)] = value;
}

int pop(Stack *s) {
    return s->arr[(s->top)--];
}

void move(Stack *src, Stack *dest, char s, char d) {
    int pole1Top = pop(src);
    int pole2Top = pop(dest);

    if (pole1Top == -1) {
        push(src, pole2Top);
        printf("Move disk %d from %c to %c\n", pole2Top, d, s);
    } else if (pole2Top == -1 || pole1Top < pole2Top) {
        push(dest, pole2Top);
        push(dest, pole1Top);
        printf("Move disk %d from %c to %c\n", pole1Top, s, d);
    } else {
        push(src, pole1Top);
        push(src, pole2Top);
        printf("Move disk %d from %c to %c\n", pole2Top, d, s);
    }
}

void hanoi(int n, Stack *src, Stack *aux, Stack *dest) {
    char s = 'A', d = 'C', a = 'B';
    for (int i = n; i >= 1; i--) push(src, i);
    int totalMoves = (1 << n) - 1;

    for (int i = 1; i <= totalMoves; i++) {
        if (i % 3 == 1) move(src, dest, s, d);
        else if (i % 3 == 2) move(src, aux, s, a);
        else move(aux, dest, a, d);
    }
}

int main() {
    int n = 3;  // Number of disks
    Stack src, aux, dest;
    init(&src, n); init(&aux, n); init(&dest, n);

    hanoi(n, &src, &aux, &dest);
    return 0;
}
