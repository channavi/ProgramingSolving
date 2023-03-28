#include <iostream>
#include <string>

using namespace std;


struct Node {
	Node* left, * right;
	int value;
};

class BinarySearchTree {
public:
	BinarySearchTree():root(nullptr){};
	~BinarySearchTree(){};

	void addNode(int value);
	bool searchValue(int value);
	void removeNode(int value);
	void show();
private:
	Node* root;
	Node* tail;

	void inOrder(Node* current) {
		if (current != nullptr) {
			inOrder(current->left);
			cout << current->value << endl;
			inOrder(current->right);
		}
	}

	Node* searchMaxNode(Node* node) {
		if (node == NULL)
			return NULL;
		while (node->right != NULL) {
			node = node->right;
		}
		return node;
	}
	Node* removeSequence(Node* node, int _value);

	void addNode(int value) {
		Node *node = new Node();
		Node* tmpRoot = nullptr;

		node->value = value;
		if (root == nullptr)
			root = node;
		else {
			Node* ptr = root;
			while (ptr != nullptr) {
				tmpRoot = ptr;
				if (node->value < ptr->value) {
					ptr = ptr->left;
				}
				else {
					ptr = ptr->right;
				}
			}
			if (node->value < tmpRoot->value)
				tmpRoot->left = node;
			else
				tmpRoot->right = node;
		}
	}

	Node* removeSequence(Node* node, int _value) {
		if (node == nullptr) return node;
		else if (node->value > _value) {
			node->left = removeSequence(node->left, _value);
		}
		else if (node->value < _value) {
			node->right = removeSequence(node->right, _value);
		}
		else {
			Node* ptr = node;
			if (node->right == nullptr && node->left == nullptr) {
				delete node;
				node = nullptr;
			}
			else if (node->right == nullptr) {
				node = node->left;
				delete ptr;
			}
			else if (node->left == nullptr) {
				node = node->right;
				delete ptr;
			}
			else {
				ptr = searchMaxNode(node -> left);
				node->value = ptr->value;
				node->left = removeSequence(node->left, ptr->value);
			}
		}
		return node;
	}

	void removeNode(int value) {
		Node *ptr = root;
		removeSequence(ptr, value);
	}

	bool searchValue(int value) {
		Node* ptr = root;
		Node* tmpRoot = nullptr;
		while (ptr != nullptr) {
			if (ptr->value == value) {
				cout << value << "Found" << endl;
				return true;
			}
			else if (ptr->value > value)
				ptr = ptr->left;
			else
				ptr = ptr->right;
		}
		cout << value << "not Found" << endl;
		return false;
	}

	int main() {
		BinarySearchTree* BST = new BinarySearchTree();
		BST->addNode(1);
		BST->addNode(3);
		BST->addNode(6);
		BST->addNode(9);
		BST->addNode(12);
		BST->addNode(17);
		BST->addNode(23);
		BST->addNode(15);
		BST->addNode(5);

		BST->show(); cout << endl;
		BST->searchValue(4);
		BST->searchValue(17);
		BST->removeNode(22);

		BST->show();

		cout << endl;
		return 0;
	}
};