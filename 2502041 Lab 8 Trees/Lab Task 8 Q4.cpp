#include <iostream>
#include <algorithm>
using namespace std;


class Node {
public:
    int token;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        token = value;
        left = NULL;
        right = NULL;
        height = 1;
    }
};


int getHeight(Node* node) {
    if (node == NULL)
        return 0;

    return node->height;
}


int getBalance(Node* node) {
    if (node == NULL)
        return 0;

    return getHeight(node->left) -
           getHeight(node->right);
}


Node* rightRotate(Node* y) {

    Node* x = y->left;
    Node* T2 = x->right;

    
    x->right = y;
    y->left = T2;


    y->height = 1 + max(getHeight(y->left),
                        getHeight(y->right));

    x->height = 1 + max(getHeight(x->left),
                        getHeight(x->right));

    return x;
}


Node* leftRotate(Node* x) {

    Node* y = x->right;
    Node* T2 = y->left;


    y->left = x;
    x->right = T2;


    x->height = 1 + max(getHeight(x->left),
                        getHeight(x->right));

    y->height = 1 + max(getHeight(y->left),
                        getHeight(y->right));

    return y;
}


Node* insert(Node* node, int token) {

    
    if (node == NULL)
        return new Node(token);

    if (token < node->token)
        node->left = insert(node->left, token);

    else if (token > node->token)
        node->right = insert(node->right, token);

    else
        return node;

    
    node->height = 1 + max(getHeight(node->left),
                           getHeight(node->right));

    
    int balance = getBalance(node);


    if (balance > 1 && token < node->left->token)
        return rightRotate(node);

    
    if (balance < -1 && token > node->right->token)
        return leftRotate(node);

    
    if (balance > 1 && token > node->left->token) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }


    if (balance < -1 && token < node->right->token) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}


void inOrder(Node* root) {

    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->token << " ";
    inOrder(root->right);
}


void displayTree(Node* root, int space = 0) {

    if (root == NULL)
        return;

    space += 5;

    displayTree(root->right, space);

    cout << endl;

    for (int i = 5; i < space; i++)
        cout << " ";

    cout << root->token
         << " (H:" << root->height
         << ", BF:" << getBalance(root) << ")";

    displayTree(root->left, space);
}


int main() {

    Node* root = NULL;

    int tokens[] = {15, 25, 35, 45, 55, 65, 75};

    
    for (int i = 0; i < 7; i++) {
        root = insert(root, tokens[i]);
    }

    
    cout << "In-order Traversal: ";
    inOrder(root);

    cout << endl << endl;


    cout << "Final Balanced AVL Tree:";
    displayTree(root);

    cout << endl;

    return 0;
}
