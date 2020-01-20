/*
	Problem :
	Implement a Queue using 2 stacks s1 and s2.
*/
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The structure of the class is
class StackQueue{
private:   
	// These are STL stacks ( http://goo.gl/LxlRZQ )
	stack<int> s1;
	stack<int> s2;
public:
	void push(int);
	int pop();
}; */
/* The method push to push element into the queue */
void StackQueue :: push(int x) {
	s1.push(x);
}
/*The method pop which return the element popped out of the queue*/
int StackQueue :: pop() {
	if(s1.empty()) {
		return -1;
	}
	while(!s1.empty()) {
		s2.push(s1.top());
		s1.pop();
	}
	int t = s2.top();
	s2.pop();
	while(!s2.empty()) {
		s1.push(s2.top());
		s2.pop();
	}
	return t;
}
