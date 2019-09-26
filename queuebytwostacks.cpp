// implementing a queue using two stacks.
// Cost on the push operation. 

#include <stack>
#include <iostream>

template <class usertype> 
class Queue {
	private:
		unsigned long size;
		std::stack<usertype> s1;
		std::stack<usertype> s2;

	public:
		Queue() {
			size = 0;
		}
		// push
		void push(usertype val) {
			// push the old elements first, then push the last element
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
			s2.push(val);
			size++;
			// move the elements back to form a queue order.
			while (!s2.empty()) {
				s1.push(s2.top());
				s2.pop();
			}
		}
		// pop
		void pop(void) {
			if (s1.empty()) {
				return;
			}
			s1.pop();
			size--;
		}
		// front
		usertype front(void) {
			if (s1.empty()) {
				return -1;
			}
			return s1.top();
		}
		// get size
		unsigned long get_size(void) {
			return size;
		}
};








int main(void) {
	Queue<int> q;

	for (int i = 0; i < 20; i++)
	{
		q.push(i);
	}
	
	for (int i = 0; i < 20; i++)
	{
		std::cout << q.front() << std::endl;
		q.pop();
	}

	std::cout << "size " << q.get_size() << std::endl;
	return 0;
}