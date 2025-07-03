#include <iostream>
using namespace std;


struct Node {
    char data;
    Node* left;
    Node* right;
};
Node* newNode(char value) {
    Node* node = new Node;
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}


void preorder(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";  
    preorder(root->left);       
    preorder(root->right);      
}

int main() {

    Node* A = newNode('A');
    Node* B = newNode('B');
    Node* C = newNode('C');
    Node* D = newNode('D');
    Node* E = newNode('E');

    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;

    cout << "Preorder Traversal: ";
    preorder(A);  

    return 0;
}

