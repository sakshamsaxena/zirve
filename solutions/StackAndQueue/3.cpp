/*
	Problem :
	Implement a Stack using 2 queue q1 and q2.
*/
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The structure of the class is
class QueueStack{
private:
	queue<int> q1;
	queue<int> q2;
public:
	void push(int);
	int pop();
};
 */
/* The method push to push element into the stack */
void QueueStack :: push(int x) {
	q1.push(x);
	while(!q2.empty()) {
		q1.push(q2.front());
		q2.pop();
	}
	queue<int> T = q1;
	q1 = q2;
	q2 = T;
}
/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop() {
	if(q2.empty()) {
		return -1;
	} else {
		int a = q2.front();
		q2.pop();
		return a;
	}
}
