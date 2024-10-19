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
    return (a > b) ? a : b;
}

int height(Node* node) {
    if (node == NULL) return -1; // Return -1 for NULL nodes

    return node->height;
}

int getBalance(Node* node) {
    if (node == NULL) return 0; // Return 0 for NULL nodes

    return (height(node->left) - height(node->right));
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
    if (y == NULL) return x; // Prevent dereferencing NULL
    Node* b = y->left;

    y->left = x;
    x->parent = y;

    x->right = b;
    if (b != NULL) {
        b->parent = x; // Check for NULL before accessing parent
    }

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

Node* rightRotate(Node* x) {
    Node* y = x->left;
    if (y == NULL) return x; // Prevent dereferencing NULL
    Node* b = y->right;

    y->right = x;
    x->parent = y;

    x->left = b;
    if (b != NULL) {
        b->parent = x; // Check for NULL before accessing parent
    }

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

Node* insert(Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
        root->left->parent = root;
    } else if (key > root->key) {
        root->right = insert(root->right, key);
        root->right->parent = root;
    } else {
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));

    // Check the balance
    int balance = getBalance(root);

    if (balance > 1 && key < root->left->key) { // Left left case
        return rightRotate(root);
    }
    if (balance < -1 && key > root->right->key) { // Right right case
        return leftRotate(root);
    }
    if (balance > 1 && key > root->left->key) { // Left right case
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && key < root->right->key) { // Right left case
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preOrder(Node* node) {
    if (node == NULL) return;

    printf("%d ", node->key);
    preOrder(node->left);
    preOrder(node->right);
}

int main() {
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    /* The constructed AVL Tree would be
                30
               /  \
             20   40
            /  \     \
           10  25    50
    */

    printf("Preorder traversal : \n");
    preOrder(root);
    return 0;
}
