
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Node structure  used in the program
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom ;
}; */
/*  Function which returns the  root of 
	the flattened linked list. */
Node *merge(Node *a, Node *b)
{
	if(a==NULL) return b;
	if(b==NULL) return a;
	
	Node *result=NULL;
	if(a->data < b->data)
	{
		result=a;
		result->bottom=merge(a->bottom,b);
	}
	else
	{
		result=b;
		result->bottom=merge(a,b->bottom);
	}
	return result;
}
// This was given initially
Node *flatten(Node *root)
{
	if(root==NULL || root->next==NULL)
	{
		return root;
	}
	
	return merge(root, flatten(root->next));
}