#include "node.h"
#include <iostream>
#ifndef ALIST.H
using namespace std;
struct List {
private:
	Node* root;
	Node* last;
	size_t size;

public:
	List() {
		root = nullptr;
		last = nullptr;
	}

	List(Product* product) {
		root = new Node(*product);
		last = root;
	}

	void Append(Product* value) {
		Node* newNode = new Node(*value);
		last->next = newNode;
		last = newNode;
	}

	void Prepend(Product* value) {
		Node* tempNode = root;
		root = new Node(*value);
		root->next = tempNode;

	}

	void InsertBefore(Product* value, int index) {
		if (index == 0 || index < 0) {
			Node* tempNode = new Node(*value);
			tempNode->next = root;
			root = tempNode;
		}
		else {
			Node* node = GetNode(index);
			Node* prevNode = GetNode(index - 1);
			Node* tempNode = new Node(*value);
			prevNode->next = tempNode;
			tempNode->next = node;
		}
	

	}

	void InsertAfter(Product* value, int index) {
		if ( index < 0) {
			Node* tempNode = new Node(*value);
			tempNode->next = root;
			root = tempNode;
		}
		else {
			Node* node = GetNode(index);
			Node* tempNode = new Node(*value);
			tempNode->next = node->next;
			node->next = tempNode;
		}

	}

	Node* GetNode(int index) const {
		if (index < 0) {
			return root;
		}
		else {
			Node* rootNode = root;
			int i = -1;
			index = index - 1;
			while (rootNode != nullptr && index != i) {
				i++;
				rootNode = rootNode->next;
			}
			return rootNode;
		}
	}

	const Product* ToArray() {

	}

	void Print() {
		while (root != nullptr) {
			std::cout << root->value.name << " " << root->value.price << "руб." << std::endl;
			root = root->next;
		}

	}
private:
	bool createFirst(Product* value) {

	}

	static Node* createNode(Product* value) {

	}
	void insert(Product* value, int index) {

	}
};

#endif // DEBUG
