/*
	Problem : Left View of Binary Tree
*/
/* A binary tree node
struct Node
{
	int data;
	Node* left, * right;
};
*/
// Recursive function to print left view of a binary tree.
void leftViewUtil(struct Node *root, int level, int *max_level)
{
	// Base Case
	if (root == NULL)  return;

	// If this is the first node of its level
	if (*max_level < level)
	{
		cout << root->data << " ";
		*max_level = level;
	}

	// It will keep going left as we expect in most simple case.
	// Then, once it begins the traversal to other right nodes,
	// we would already be having the max level set, so lower
	// levels than that (covered by left nodes) will be ignored
	// and further traversal will be queued.
	leftViewUtil(root->left, level + 1, max_level);
	leftViewUtil(root->right, level + 1, max_level);
}
void leftView(Node *root)
{
	int max_level = 0;
	leftViewUtil(root, 1, &max_level);
}