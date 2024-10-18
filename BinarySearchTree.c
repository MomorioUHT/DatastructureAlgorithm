#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node* parent;
    struct node* left;
    struct node* right;
} Node;

Node* createNode(int x) {
    Node* node = (Node *)malloc(sizeof(Node));
    node->key = x;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* createLeft(int x, Node* parent) {
    Node* left = createNode(x);
    parent->left = left;
    left->parent = parent;
    return left;
}

Node* createRight(int x, Node* parent) {
    Node* right = createNode(x);
    parent->right = right;
    right->parent = parent;
    return right;
}

Node* getParent(Node* curr) {
    return curr->parent;
}

Node* getLeft(Node* curr) {
    return curr->left;
}

Node* getRight(Node* curr) {
    return curr->right;
}

int isRoot(Node* u) {
    return u->parent == NULL;
}

int isExternal(Node* u) {
    return u->left == NULL && u->right == NULL;
}

int depth(Node* node) {
    int depth = 0;
    while (node->parent != NULL) {
        node = node->parent;
        depth++;
    }
    return depth;
}

int height(Node* node) {
    if (node == NULL) return 0;

    int left_height = height(node->left);
    int right_height= height(node->right);

    return (left_height > right_height? left_height : right_height) + 1;
}

void expandExternal(Node* node, int leftKey, int rightKey) {
    createLeft(leftKey, node);
    createRight(rightKey, node);
}

Node* removeAboveExternal(Node* node) {
    Node* parent = node->parent;
    Node* sibling;

    if (parent->left == node) {
        sibling = parent->right;
    } else {
        sibling = parent->left;
    }

    if (parent->parent == NULL) {
        sibling->parent == NULL;
    } else {
        Node* grandParent = parent->parent;
        if (grandParent->left == parent) {
            grandParent->left = sibling;
        } else {
            grandParent->right = sibling;
        }
        sibling->parent = grandParent;
    }
    free(node);
    free(parent);
    return sibling;
}

void preOrderTraversal(Node* node) {
    printf("%d ", node->key);
    if (node->left != NULL) {
        preOrderTraversal(node->left);
    }
    if (node->right != NULL) {
        preOrderTraversal(node->right);
    }
}

void postOrderTraversal(Node* node) {
    if (node->left != NULL) {
        postOrderTraversal(node->left);
    }
    if (node->right != NULL) {
        postOrderTraversal(node->right);
    }
    printf("%d ", node->key);
}

void inOrderTraversal(Node* node) {
    if (node->left != NULL) {
        inOrderTraversal(node->left);
    }
    printf("%d ", node->key);
    if (node->right != NULL) {
        inOrderTraversal(node->right);
    }
}

//=======================================================
//BST Properties

Node* search(int key, Node* node) {
    if (node == NULL || node->key == key) return node;

    if (key < node->key) {
        return search(key, node->left);
    }
    return search(key, node->right);
}

Node* minimum(Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

Node* maximum(Node* node) {
    while (node->right != NULL) {
        node = node->right;
    }
    return node;
}

//=======================================================
//Finding Successor & Predecessor

Node* successor(Node* node) {
    if (node->right != NULL) return minimum(node->right);

    Node* ancestor = node->parent;
    while ((ancestor != NULL) && (ancestor->right == node)) {
        node = ancestor;
        ancestor = node->parent;
    }

    return ancestor;
}

Node* predecessor(Node* node) {
    if (node->left != NULL) return maximum(node->left);

    Node* ancestor = node->parent;
    while ((ancestor != NULL) && (ancestor->left == node)) {
        node = ancestor;
        ancestor = node->parent;
    }

    return ancestor;
}

int main() {
    return 0;
}