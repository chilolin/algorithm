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

LinkedList* qu;

void init() {
	qu = new LinkedList();
}

bool isEmpty() {
	return qu->nil == qu->nil->next;
}

void enqueue(string x) {
	Node* v = new Node(x);
	qu->insert(v, qu->nil->prev);
}

string dequeue() {
	if(isEmpty()) {
		cout << "error: queue is empty." << endl;
		return "";
	}
	string x = qu->nil->next->name;
	qu->erase(qu->nil->next);
	return x;
}

int main() {
	init();

	enqueue("1");
	enqueue("2");
	enqueue("3");
	enqueue("4");

	qu->printList();

	cout << dequeue() << endl;
	cout << dequeue() << endl;
	cout << dequeue() << endl;
	cout << dequeue() << endl;
	cout << dequeue() << endl;

	qu->printList();
}