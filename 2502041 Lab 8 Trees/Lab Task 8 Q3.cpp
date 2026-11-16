#include <iostream>
#include <string>
using namespace std;


class Node {
public:
    string folderName;
    Node* left;
    Node* right;

    
    Node(string name) {
        folderName = name;
        left = NULL;
        right = NULL;
    }
};


void inOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    inOrder(root->left);
    cout << root->folderName << " ";
    inOrder(root->right);
}


void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->folderName << " ";
    preOrder(root->left);
    preOrder(root->right);
}


void postOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->folderName << " ";
}

int main() {

    
    Node* root = new Node("Computer");

    
    root->left = new Node("Documents");
    root->right = new Node("Downloads");

    root->left->left = new Node("Assignments");
    root->left->right = new Node("Projects");

    root->right->left = new Node("Images");
    root->right->right = new Node("Videos");

    
    cout << "In-order Traversal: ";
    inOrder(root);

    cout << endl;

    
    cout << "Pre-order Traversal: ";
    preOrder(root);

    cout << endl;


    cout << "Post-order Traversal: ";
    postOrder(root);

    cout << endl;

    return 0;
}
