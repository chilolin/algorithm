#include <iostream>
#include <string>
using namespace std;

struct Node {
	Node *prev, *next;
	string name;

	Node(string name_ = "") : prev(NULL), next(NULL), name(name_) { }
};

Node* nil;

void init() {
	nil = new Node();
	nil->prev = nil;
	nil->next = nil;
}

void printList() {
	Node* cur = nil->next;
	for (; cur != nil; cur = cur->next) {
		cout << cur->name << " -> ";
	}
	cout << endl;
}

void insert(Node* v, Node* p = nil) {
	v->next = p->next;
	p->next->prev = v;
	p->next = v;
	v->prev = p;
}

void erase(Node* v) {
	if (v == nil) return;
	v->next->prev = v->prev;
	v->prev->next = v->next;
	delete v;
}