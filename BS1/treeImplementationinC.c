#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to search for an element in the BST
struct TreeNode* search(struct TreeNode* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

int main() {
    struct TreeNode* root = NULL;

    // Insert nodes into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Search for an element in the BST
    int elementToSearch;
    printf("enter the required no : ");
    scanf("%d",&elementToSearch);
    struct TreeNode* result = search(root, elementToSearch);

    if (result != NULL) {
        printf("Element %d found in the BST.\n", elementToSearch);
    } else {
        printf("Element %d not found in the BST.\n", elementToSearch);
    }

    // Remember to free the allocated memory when done with the BST
    // This should ideally be done using a separate function to free the entire BST

    return 0;
}