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

int main() {
    Node* root = createNode(1);

    Node* leftChild = createLeft(2, root);
    Node* rightChild = createRight(3, root);

    Node* leftLeftChild = createLeft(4, leftChild);
    Node* leftRightChild = createRight(5, leftChild);

    Node* rightLeftChild = createLeft(6, rightChild);
    Node* rightRightChild = createRight(7, rightChild);

    createLeft(8, leftLeftChild);
    createRight(9, leftLeftChild);
    
    createLeft(10, rightRightChild);
    createRight(11, rightRightChild);

    printf("Pre-order Traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("In-order Traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postOrderTraversal(root);
    printf("\n");

    return 0;
}
