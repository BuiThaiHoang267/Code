//#include<iostream>
//using namespace std;
//
//struct Node {
//	int data;
//	Node* next;
//};
//
//typedef struct Node* stack;
//
//bool isEmpty(stack s) {
//	return (s == NULL);
//}
//
//Node* createNode(int data) {
//	Node* p = new Node();
//	if (p == NULL) {
//		return NULL;
//	}
//	p->data = data;
//	p->next = NULL;
//
//	return p;
//}
//
//void push(stack& s, int data) {
//	Node* ptr = createNode(data);// tao node moi
//	if (isEmpty(s)) {
//		s = ptr;
//	}
//	else {
//		ptr->next = s;
//		s = ptr;
//	}
//}
//
//int top(stack s) {
//	if (!isEmpty(s)) {
//		return s->data;
//	}
//	else {
//		cout << "Stack is empty!" << endl;
//	}
//}
//
//int pop(stack& s) {
//	if (!isEmpty(s)) {
//		int data = s->data;
//		Node* x = s;
//		s = s->next;
//		delete(x);// giai phong bo nho
//		return data;
//	}
//	else {
//		cout << "Stack is empty!" << endl;
//	}
//}
//
//int main() {
//	stack s=NULL;
//	push(s, 100);
//	push(s, -99);
//	push(s, 35);
//	push(s, 26);
//
//	cout << "TOP: " << top(s) << endl;
//	pop(s);// xoa mot ptu tren top stack
//
//	while (!isEmpty(s)) {
//		int data = top(s);
//		pop(s);
//		cout << data << " <-- ";
//	}
//
//	cout << endl;
//	return 0;
//}

#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};
typedef struct Node* stack;

bool emptyStack(stack s) {
	return (s == NULL);
}

Node* createNode(int data) {
	Node* ptr = new Node();
	if (ptr == NULL)
		return NULL;
	ptr->data = data;
	ptr->next = NULL;
	return ptr;
}

void push(stack& s,int data) {
	Node* p = createNode(data);
	if(emptyStack(s))
		s=p;
	else
	{
		p->next = s;
		s = p;
	}
}
int top(stack s) {
	if (!emptyStack(s))
		return s->data;
	else
		cout << "Stack is empty!" << endl;
}

int pop(stack& s) {
	if (!emptyStack(s)) {
		int data = s->data;
		Node* x = s;
		s = s->next;
		delete(x);
		return data;
	}
	else
		cout << "Stack is empty!" << endl;
}

int main() {
	stack s = NULL;
	for (int i = 0; i < 10; i++)
		push(s, i + 1);
	cout << "Top: " << top(s) << endl;
	cout << "Pop: " << pop(s) << endl;
	cout << "Top: " << top(s) << endl;

	while (!emptyStack(s)) {
		int data = pop(s);
		cout << data << "<--";
	}
	cout << endl;
	return 0;
}