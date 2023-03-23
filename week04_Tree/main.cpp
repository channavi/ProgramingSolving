#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int value;
    Node* parent;
    vector<Node*> children;

    Node(int val) {
        value = val;
        parent = nullptr;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        root = nullptr;
    }

    void insert(int val, Node* parent) {
        Node* newNode = new Node(val);
        newNode->parent = parent;
        parent->children.push_back(newNode);
    }
};

int main() {
    Tree tree;

    Node* n1 = new Node(1);
    tree.root = n1;

    tree.insert(2, n1);
    tree.insert(3, n1);

    Node* n4 = new Node(4);
    tree.insert(5, n4);
    tree.insert(6, n4);
    tree.insert(7, n4);
    tree.insert(4, n1);

    cout << tree.root->children[0]->value << endl; // 2
    cout << tree.root->children[1]->value << endl; // 3
    cout << tree.root->children[2]->value << endl; // 4
    cout << tree.root->children[2]->children[0]->value << endl; // 5
    cout << tree.root->children[2]->children[1]->value << endl; // 6
    cout << tree.root->children[2]->children[2]->value << endl; // 7

    return 0;
}