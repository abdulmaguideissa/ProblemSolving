#include <iostream>
#define MAX    10


template <class Type>
class Stack {
private:
	Type st[MAX];		// Stack array of any type.
	long top;
public:
	Stack() {
		top = -1;
	}
	void push(Type value) {
		st[++top] = value;
	}
	Type pop() {
		return st[top--];
	}

};


int main() {
	Stack <float> stack;
	stack.push(100.0);
	stack.push(20.36);
	std::cout << stack.pop << std::endl;

}