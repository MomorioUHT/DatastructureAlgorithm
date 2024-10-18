#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node* parent;
    struct node* leftChild;
    struct node* rightSibling;
} Node;

//====================================================
//Struct a tree
Node* createRoot(int x) {
    Node* root = (Node *)malloc(sizeof(Node));
    root->key = x;
    root->parent = NULL;
    root->leftChild = NULL;
    root->rightSibling = NULL;
    return root;
}

Node* createNodeWithParent(int x, Node* parent) {
    Node* node = (Node *)malloc(sizeof(Node));
    node->key = x;
    node->parent = parent;
    node->leftChild = NULL;
    node->rightSibling = NULL;
    return node;    
}

Node* createNode(int key, Node* parent) {
    Node* current = createNodeWithParent(key, parent);

    if (current->parent->leftChild == NULL) {
        current->parent->leftChild = current;
    } else {
        Node* iterator = parent->leftChild;
        while (iterator->rightSibling != NULL) {
            iterator = iterator->rightSibling;
        }
        iterator->rightSibling = current;
    }

    return current;
}   
//====================================================

//====================================================
//Normal Tree Traversals

void preOrderTraversal(Node* node) {
    printf("%d ", node->key);
    Node* child = node->leftChild;
    while (child) {
        preOrderTraversal(child);
        child = child->rightSibling;
    }
}

void postOrderTraversal(Node* node) {
    Node* child = node->leftChild;
    while (child) {
        postOrderTraversal(child);
        child = child->rightSibling;
    }
    printf("%d ", node->key);
}
//====================================================

//====================================================
//Etc

Node* getParent(Node* node) {
    return node->parent;
}

Node* getChild(Node* node, int k) {
    Node* curr = node->leftChild;
    for (int i = 0; i < k; i++) {
        curr = curr->rightSibling;
    }
    return curr;
}   

int isRoot(Node* node) {
    return node->parent == NULL;
}

int isExternal(Node* node) {
    return node->leftChild == NULL;
}

int depth(Node* node) {
    int depth = 0;
    while (node->parent != NULL) {
        node = node->parent;
        depth++;
    }
    return depth;
}



//====================================================

int main() {
    Node* node1 = createRoot(1);
    Node* node2 = createNode(2, node1);
    Node* node3 = createNode(3, node1);
    Node* node4 = createNode(4, node2);
    Node* node5 = createNode(5, node1);
    Node* node6 = createNode(6, node1);
    Node* node7 = createNode(7, node3);
    Node* node8 = createNode(8, node7);
    Node* node9 = createNode(9, node7);
    Node* node10 = createNode(10, node3);
    Node* node11 = createNode(11, node3);
    Node* node12 = createNode(12, node11);

    printf("Preorder Traversal from Root\n");
    preOrderTraversal(node1);

    printf("\n");

    printf("Postorder Traversal from Root\n");
    postOrderTraversal(node1);
}