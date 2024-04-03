#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};
typedef struct Node* queue;

bool isEmpty(queue q) {
	return (q == NULL);
}

Node* createNode(int data) {
	Node* p = new Node();
	if (p == NULL)
		return p;
	p->next = NULL;
	p->data = data;
	return p;
}



void enQueue(queue& q, int data) {
	Node* p = createNode(data);
	if (q == NULL)
		q = p;
	else {
		Node* ptr = q;
		while (ptr != NULL && ptr->next != NULL) {// tim den node cuoi cung
			ptr = ptr->next;
		}
		//ptr chinh la node cuoi cung trong dslk
		ptr->next = p;
	}
}

int peek(queue q) {
	if (!isEmpty(q))
		return q->data;
	else
		return 0;
}

int deQueue(queue& q) {
	if (!isEmpty(q)) {
		int data = q->data;
		Node* p = q;
		q = q->next;
		delete(p);
		return data;
	}
	else
		return 0;
}

int main()
{
	queue q = NULL;
	enQueue(q, 10);
	enQueue(q, 100);
	enQueue(q, 1000);
	enQueue(q, 10000);
	enQueue(q, 100000);
	enQueue(q, 1000000);
	enQueue(q, 10000000);
	cout << "QUEUE rong?" << isEmpty(q) << endl;
	cout << "First Element Of QUEUE?" << peek(q) << endl;
	while (!isEmpty(q)) {
		int data = peek(q);
		deQueue(q);
		cout << " " << data << endl;
	}
	cout << "QUEUE rong?" << isEmpty(q) << endl;
	return 0;
}