#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

int queue[SIZE], front = -1, rear = -1;

// Enqueue operation
void enqueue(int val) {
    if (rear == SIZE - 1) printf("Queue is Full\n");
    else {
        queue[++rear] = val;
        if (front == -1) front = 0;
    }
}

// Dequeue operation
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return; // or exit(1) to terminate the program
    }
    printf("Dequeued: %d\n", queue[front++]);
}

// Traverse operation
void traverse() {
    if (front == -1 || front > rear) printf("Queue is Empty\n");
    else {
        for (int i = front; i <= rear; i++) printf("%d ", queue[i]);
        printf("\n");
    }
}

// Search operation
void search(int val) {
    bool found = false;
    for (int i = front; i <= rear; i++) {
        if (queue[i] == val) {
            printf("Found: %d at position %d\n", val, i - front + 1);
            found = true;
            break;
        }
    }
    if (!found) printf("Not Found\n");
}

int main() {
    enqueue(10); enqueue(20); enqueue(30); traverse();
    dequeue(); traverse(); search(20); search(50);
    return 0;
}