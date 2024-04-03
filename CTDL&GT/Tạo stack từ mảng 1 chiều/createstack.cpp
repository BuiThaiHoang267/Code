#include<iostream>
#include<string>
using namespace std;

int current_size = -1;
const int MAX_Size = 100;
int stack[MAX_Size];

bool isEmpty() // kiem tra stack rong
{
	return (current_size == -1);
}

bool isFull() // kiem tra stack day chua
{
	return(current_size == MAX_Size);
}

void push(int data) // day data vao stack
{
	if (!isFull()) {
		current_size++;
		stack[current_size] = data;
	}
	else
		cout << "Stack ful" << endl;
}

int top() // lay phan tu top nhung ko xoa
{
	if (!isEmpty()) {
		int data = stack[current_size];
		return data;
	}
	else
		cout << "Stack is Empty!";
}

int pop() { // lay phan top va xoa khoi stack;
	if (!isEmpty()) {
		int data = stack[current_size];
		current_size--;
		return data;
	}
	else
		cout << "Stack is Empty!";
}

int main()
{
	push(100);
	push(-225);
	push(-25);
	cout << "Top: " << top() << endl;
	pop();
	cout << "Top: " << top() << endl;
	while (!isEmpty()) {
		int data = pop();
		cout << data << " <-- ";
	}
	cout << endl;
	return 0;
}

//#include<iostream>
//using namespace std;
//
//int current_size = -1;
//const int Max_size = 100;
//int stack[Max_size];
//
//bool emptyStack() {
//	return (current_size == -1);
//}
//
//bool fullStack() {
//	return (current_size == Max_size);
//}
//
//void push(int data) {
//	if (!fullStack()) {
//		current_size++;
//		stack[current_size] = data;
//	}
//	else
//		cout << "Full Stack!" << endl;
//}
//
//int top() {
//	if (!emptyStack()) {
//		int data = stack[current_size];
//		return data;
//	}
//	else
//		cout << "Stack is empty!";
//	return 0;
//}
//
//int pop() {
//	if (!emptyStack()) {
//		int data = stack[current_size];
//		current_size--;
//		return data;
//	}
//	else
//		cout << "Stack is empty!";
//	return 0;
//}
//
//
//
//int  main() {
//	for (int i = 0; i < 10; i++)
//		push(i);
//	cout << "Top: " << top() << endl;
//	pop();
//	cout << endl;
//	cout << "Top: " << top() << endl;
//	while (!emptyStack()) {
//		int data = pop();
//		cout << data << " <-- ";
//	}
//	cout << endl;
//	return 0;
//}