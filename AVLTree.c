#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node* left;
    struct node* right;
    struct node* parent;
    int height;
} Node;

int max(int a, int b) {
    return (a > b)? a : b;
}

int height(Node* node) {
    if (node == NULL) return -1;

    return node->height;
}

int getBalance(Node* node) {
    if (node == NULL) return -1;

    return (node->left->height - node->right->height);
}

Node* createNode(int x) {
    Node* node = (Node *)malloc(sizeof(Node));
    node->key = x;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->height = 0;
    return node;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* b = y->left;

    y->left = x;
    x->parent = y;

    x->right = b;
    b->parent = x;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

Node* rightRotate(Node* x) {
    Node* y = x->left;
    Node* b = y->right;

    y->right = x;
    x->parent = y;

    x->left = b;
    b->parent = x;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));   

    return y;
}

Node* insert(Node* node, int key) {
    if (node == NULL) {
        return createNode(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
        node->left->parent = node;
    } else if (key > node->key) {
        node->right = insert(node->right, key);
        node->right->parent = node;
    } else {
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));

    //Check the balance
    int balance = getBalance(node);

    
    if (balance > 1 && key < node->left->key) { // Left left case
        return rightRotate(node);
    }
    if (balance < -1 && key > node->right->key) { // Right right case
        return leftRotate(node);
    }
    if (balance > 1 && key > node->left->key) { // Left right case
        node->left = leftRotate(node->left); 
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) { // Right left case
        node->right = rightRotate(node->right); 
        return leftRotate(node);
    }

    return node;

}


int main() {
    return 0;
}