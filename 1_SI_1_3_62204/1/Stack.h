#pragma once
#include <iostream> 

int const MAX = 100;

class Stack
{
private:
	int *arr;	   
	int top;	    
	int size;

	bool full() const;
	void grow();

public:

	Stack();
	Stack(Stack const&);
	~Stack();
	Stack& operator=(Stack const &);


	bool empty() const;
	int peek() const;
	void push(int);
	int pop();

};
