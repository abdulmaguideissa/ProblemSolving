// Handling ERRORS in stack operations using exceptions OOP
// concept in cpp.
#include <iostream>
#include <exception>
#include <map>

#define MAX     10    // MAX size of the stack
using namespace std;

template <class type>
class Stack {
private:
	type st[MAX];
	int top;
public:
	class FULL{};    // Exception class to message full stack
	class EMPTY{};   // Exception class to message empty class

	Stack() {		// Constructor
		top = -1;	
	}

	void push(type var) {
		if ( top >= MAX - 1 )
			throw FULL();
		else 
			st[++top] = var;
	}
	int pop() {
		int result;
		if ( top < 0 )
			throw EMPTY();
		else
			result = st[top--];
		return result;
	}
};


int main() {
	Stack <int> stack;
	try {
		stack.push(1);
		stack.push(5);
		stack.push(200);
		stack.push(152);
		stack.push(12);
		stack.push(15);
		stack.push(102);
		cout << "1 " << stack.pop() << endl;
		cout << "2 " << stack.pop() << endl;
		cout << "3 " << stack.pop() << endl;
		cout << "4 " << stack.pop() << endl;
	}
	catch ( Stack<int>::FULL ) {
		cout << "EXCEPTION: Stack Full" << endl;
	}
	catch ( Stack<int>::EMPTY ) {
		cout << "EXCEPTION: Stack Empty" << endl;
	}
	return 0;
}