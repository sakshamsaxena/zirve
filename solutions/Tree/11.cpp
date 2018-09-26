/*
	Problem : Height of Binary Tree
*/
int height(Node* root)
{
	if (root) {
		return 1 + max(height(root->left), height(root->right));
	} else {
		return 0;
	}
}