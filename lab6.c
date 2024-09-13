#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(Node** head, int data) {
    Node* newNode = create(data);
    newNode->next = *head;
    *head = newNode;
}

void delete(Node** head, int key) {
    Node* temp = *head, *prev = NULL;
    if (temp && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp) {
        prev->next = temp->next;
        free(temp);
    }
}

void traverse(Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int search(Node* head, int key) {
    while (head) {
        if (head->data == key)
            return 1;
        head = head->next;
    }
    return 0;
}

void reverse(Node** head) {
    Node *prev = NULL, *current = *head, *next = NULL;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main() {
    Node* head = NULL;
    
    insert(&head, 3); // Inserting nodes
    insert(&head, 2);
    insert(&head, 1);
    
    printf("List: ");
    traverse(head); // Traversing list
    
    delete(&head, 2); // Deleting a node
    printf("After Deletion: ");
    traverse(head);
    
    printf("Search 3: %s\n", search(head, 3) ? "Found" : "Not Found");
    
    reverse(&head); // Reversing list
    printf("Reversed List: ");
    traverse(head);
    
    return 0;
}
