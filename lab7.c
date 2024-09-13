#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insert(Node **head, int data) {
    Node *newNode = createNode(data);
    newNode->next = *head;
    if (*head) (*head)->prev = newNode;
    *head = newNode;
}

void delete(Node **head, int key) {
    Node *temp = *head;
    while (temp && temp->data != key) temp = temp->next;
    if (!temp) return;
    if (temp->prev) temp->prev->next = temp->next;
    else *head = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    free(temp);
}

void traverse(Node *head) {
    while (head) { printf("%d ", head->data); head = head->next; }
    printf("\n");
}

void reverse(Node *head) {
    if (!head) return;
    while (head->next) head = head->next;
    while (head) { printf("%d ", head->data); head = head->prev; }
    printf("\n");
}

Node* search(Node *head, int key) {
    while (head && head->data != key) head = head->next;
    return head;
}

int main() {
    Node *head = NULL;
    insert(&head, 10); insert(&head, 20); insert(&head, 30); // Insert
    traverse(head); // Traversal
    delete(&head, 20); // Deletion
    traverse(head); reverse(head); // Traversal & Reverse
    Node *found = search(head, 10); // Search
    if (found) printf("Found: %d\n", found->data);
}
