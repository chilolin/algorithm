#include <iostream>
#include <string>
using namespace std;

struct Node {
	Node *prev, *next;
	string name;

	Node(string name_ = "") : prev(NULL), next(NULL), name(name_) { }
};


struct LinkedList {
	Node* nil;

	LinkedList() {
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

	void insert(Node* v, Node* p) {
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
};

LinkedList* st;

void init() {
	st = new LinkedList();
}

bool isEmpty() {
	return st->nil == st->nil->next;
}

void push(string x) {
	Node* v = new Node(x);
	st->insert(v, st->nil->prev);
}

string pop() {
	if(isEmpty()) {
		cout << "error: stack is empty." << endl;
		return "";
	}
	string x = st->nil->prev->name;
	st->erase(st->nil->prev);
	return x;
}

int main() {
	init();

	push("1");
	push("2");
	push("3");
	push("4");

	st->printList();

	cout << pop() << endl;
	cout << pop() << endl;
	cout << pop() << endl;
	cout << pop() << endl;
	cout << pop() << endl;

	st->printList();
}