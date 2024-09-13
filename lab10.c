#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node
Node* insertNode(Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left = insertNode(root->left, data);
    else
        root->right = insertNode(root->right, data);
    return root;
}

// Function to find the minimum value node
Node* findMin(Node* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

// Function to delete a node
Node* deleteNode(Node* root, int data) {
    if (root == NULL) return NULL;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to perform in-order traversal
void inOrderTraversal(Node* root) {
    if (root == NULL) return;
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

// Main function to demonstrate the BST operations
int main() {
    Node* root = NULL;

    // Inserting nodes
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    // Deleting nodes
    root = deleteNode(root, 20);
    printf("After deleting 20, in-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    root = deleteNode(root, 30);
    printf("After deleting 30, in-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    root = deleteNode(root, 50);
    printf("After deleting 50, in-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
