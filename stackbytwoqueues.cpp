// implementing a stack using two queues.
// Cost on the push operation. 

#include <queue>
#include <iostream>

template <class usertype>
class Stack {
	private:
		unsigned long size;
		std::queue<usertype> q1;    // main queue
		std::queue<usertype> q2;    // auxiliary queue to circulate the last element 

	public:
		Stack() {   // default constructor
			size = 0;
		}
		// push
		void push(usertype val) {
			q2.push(val);   // holds the last pushed element
			size++;

			while (!q1.empty()) {
				q2.push(q1.front());
				q1.pop();
			}

			// swap the values, so q1 now is the stack
			std::queue<usertype> q = q1;
			q1 = q2;
			q2 = q;
		}
		// pop
		void pop(void) {
			if (q1.empty()) {
				return;
			}
			size--;
			q1.pop();
		}
		// top
		usertype top(void) {
			if (q1.empty()) {
				return -1;
			}
			return q1.front();
		}
		// return the current size
		unsigned long get_size(void) {
			return size;
		}
		// check if empty
		bool empty(void) {
			if (get_size()) {
				return false;
			}
			else {
				return true;
			}
		}
};



int main(void) {
	Stack<int> s;

	for (int i = 0; i < 20; i++)
	{
		s.push(i);
	}

	for (int i = 0; i < 20; i++)
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}

	std::cout << "size " << s.get_size() << std::endl;
	return 0;
}