#include <iostream>
#include <string>
using namespace std;


class Node {
public:
    string name;
    Node* left;
    Node* right;

    
    Node(string memberName) {
        name = memberName;
        left = NULL;
        right = NULL;
    }
};


void displayTree(Node* node) {
    if (node == NULL) {
        return;
    }

    cout << "Member: " << node->name << endl;

    if (node->left != NULL)
        cout << "Left Child: " << node->left->name << endl;
    else
        cout << "Left Child: None" << endl;

    if (node->right != NULL)
        cout << "Right Child: " << node->right->name << endl;
    else
        cout << "Right Child: None" << endl;

    cout << "------------------------" << endl;

    displayTree(node->left);
    displayTree(node->right);
}

int main() {


    Node* root = new Node("Head of Department (HOD)");

    
    root->left = new Node("Academic Coordinator");
    root->right = new Node("Administrative Coordinator");

    
    root->left->left = new Node("Faculty Member 1");
    root->left->right = new Node("Faculty Member 2");

    root->right->left = new Node("Faculty Member 3");
    root->right->right = new Node("Faculty Member 4");

    
    displayTree(root);

    return 0;
}
