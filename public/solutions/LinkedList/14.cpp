/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* 
The structure of the node of the queue is
struct QueueNode
{
    int data;
    QueueNode *next;
};
and the structure of the class is
class Queue {
private:
    QueueNode *front;
    QueueNode *rear;
public :
    void push(int);
    int pop();
};
 */
/* The method push to push element into the queue*/
void Queue:: push(int x)
{
    // Your Code
    QueueNode *temp = new QueueNode;
    temp->data = x;
    temp->next = NULL;
    
    if(this->rear == NULL) {
        this->front = this->rear = temp;
        return;
    }
    this->rear->next = temp;
    this->rear = temp;
}
/*The method pop which return the element poped out of the queue*/
int Queue :: pop()
{
    // Your Code
    if(this->front == NULL) {
        return -1;
    }
    QueueNode *temp = this->front;
    this->front = this->front->next;
    
    if(this->front == NULL) {
        this->rear = NULL;
    }
    return temp->data;
}