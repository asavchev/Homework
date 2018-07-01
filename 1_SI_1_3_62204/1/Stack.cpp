#include "stdafx.h"
#include "Stack.h"

Stack::Stack()
{
	size = MAX;
	arr = new int[size];
	top = -1;
}

Stack::Stack(Stack const& s) : size(s.size), top(s.top)
{
	delete[] arr;
	arr = new int[size];
	for (int i = 0; i <= top; i++)
		arr[i] = s.arr[i];
}

Stack& Stack::operator=(Stack const& s) {
	if (this != &s) {
		size = s.size;
		top = s.top;
		delete[] arr;
		arr = new int[size];
		for (int i = 0; i <= top; i++)
			arr[i] = s.arr[i];
	}
	return *this;
}

void Stack::grow()
{
	int *newArr = new int[2 * size];
	for (int i = 0; i < size; i++)
		newArr[i] = arr[i];
	delete[] arr;
	arr = newArr;
	size *= 2;
}

Stack::~Stack()
{
	delete[] arr;
}

bool Stack::empty() const
{
	return top == -1;
}

int Stack::peek() const
{
	if (empty()) {
		std::cout << "Stack empty";
		return 0;
	}

	return arr[top];
}

void Stack::push(int x) {
	if (full()) {
		grow();
	}
	arr[++top] = x;
}

bool Stack::full() const {
	return top == size - 1;
}

int Stack::pop() {
	if (empty()) {
		std::cout << "Error: cannot use pop() when Stack is empty!";
		return 0;
	}
	return arr[top--];
}
