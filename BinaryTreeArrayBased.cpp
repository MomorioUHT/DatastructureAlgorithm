#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void insertLeftKey(vector<int>& Arr, int parentIndex, int key) {
    int leftIndex = 2 * parentIndex;
    if (leftIndex < Arr.size()) {
        Arr[leftIndex] = key;
    }
}

void insertRightKey(vector<int>& Arr, int parentIndex, int key) {
    int rightIndex = (2 * parentIndex) + 1;
    if (rightIndex < Arr.size()) {
        Arr[rightIndex] = key;
    }
}

int getParentKey(vector<int>& Arr, int childIndex) {
    if (childIndex / 2 >= 1) {
        return Arr[childIndex / 2];
    }
    return -1;  // No parent exists
}

int getLeftKey(vector<int>& Arr, int currIndex) {
    int leftIndex = 2 * currIndex;
    if (leftIndex < Arr.size()) {
        return Arr[leftIndex];
    }
    return -1;  // No left child
}

int getRightKey(vector<int>& Arr, int currIndex) {
    int rightIndex = (2 * currIndex) + 1;
    if (rightIndex < Arr.size()) {
        return Arr[rightIndex];
    }
    return -1;  // No right child
}

bool isRoot(int index) {
    return index == 1;
}

bool isExternal(vector<int>& Arr, int currIndex) {
    return getLeftKey(Arr, currIndex) == -1 && getRightKey(Arr, currIndex) == -1;
}

// Calculate the depth of a node given its index
int depth(int index) {
    return int(log2(index));
}

int main() {
    vector<int> Arr(15, -1);

    // Insert root at index 1
    Arr[1] = 10;  // Root

    // Insert children
    insertLeftKey(Arr, 1, 5);  // Insert 5 as left child of root
    insertRightKey(Arr, 1, 20); // Insert 20 as right child of root

    insertLeftKey(Arr, 2, 3);  // Insert 3 as left child of node 5
    insertRightKey(Arr, 2, 7); // Insert 7 as right child of node 5

    cout << "Root: " << Arr[1] << endl;
    cout << "Left child of root: " << getLeftKey(Arr, 1) << endl;
    cout << "Right child of root: " << getRightKey(Arr, 1) << endl;

    cout << "Parent of 7: " << getParentKey(Arr, 5) << endl;
    cout << "Left child of 5: " << getLeftKey(Arr, 2) << endl;
    cout << "Right child of 5: " << getRightKey(Arr, 2) << endl;

    cout << "Depth of node with index 2: " << depth(2) << endl;

    cout << "Is node 2 external? " << (isExternal(Arr, 2) ? "Yes" : "No") << endl;
    cout << "Is node 3 external? " << (isExternal(Arr, 3) ? "Yes" : "No") << endl;

    return 0;
}
