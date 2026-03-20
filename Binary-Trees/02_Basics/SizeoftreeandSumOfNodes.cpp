// Problem: Sum of Nodes
// Topic: Binary Tree Basics

// Intuition:
// Sum = root + left + right

// Time Complexity: O(n)
// Space Complexity: O(h)

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Preorder display
void display(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    display(root->left);
    display(root->right);
}

// Sum of nodes
int sum(Node* root) {
    if (root == NULL) return 0;
    return root->data + sum(root->left) + sum(root->right);
}

int main() {
    Node* a = new Node(5);
    Node* b = new Node(4);
    Node* c = new Node(3);
    Node* d = new Node(6);
    Node* e = new Node(2);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;

    display(a);
    cout << "\n";

    cout << "Sum: " << sum(a) << endl;

    return 0;
}
