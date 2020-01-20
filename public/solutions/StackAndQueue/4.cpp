/*
	Problem :
	Implement a Stack in which you can get min element in O(1) time and O(1) space.
*/

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
	int getMin();
	int pop();
	void push(int);
};
*/
/*returns min element from stack*/
int _stack :: getMin()
{
	return minEle ? minEle : -1;
}
/*returns poped element from stack*/
int _stack ::pop()
{
	if(!s.empty()) {
		int p = s.top();
		s.pop();
		if(minEle == p) {
			// Find it in stack again.
			minEle = 100;
			stack<int> t;
			t = s;
			while(!t.empty()) {
				if(t.top() < minEle) {
					minEle = t.top();
				}
				t.pop();
			}
			if(s.empty()) {
				minEle = -1;
			}
		}
		return p;
	} else {
		return -1;
	}
}
/*push element x into the stack*/
void _stack::push(int x)
{
	if(s.empty()) {
		minEle = x;
	} else {
		if(minEle > x) {
			minEle = x;
		}
	}
	s.push(x);
}
