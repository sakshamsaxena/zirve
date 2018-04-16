/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* 
The structure of the node of the stack is
struct StackNode
{
	int data;
	StackNode *next;
};
and the structure of the class is
class Stack {
private:
  StackNode *top;
public :
	void push(int);
	int pop();
};
 */
/* The method push to push element into the stack */
void Stack :: push(int x)
{
	StackNode *temp = new StackNode;
	temp->data = x;
	temp->next = this->top;
	this->top = temp;
}
/*The method pop which return the element poped out of the stack*/
int Stack :: pop()
{
	if(this->top == NULL) {
		return -1;
	}
	
	StackNode *temp = this->top;
	this->top = this->top->next;
	int popped = temp->data;
	free(temp);
	return popped;
}