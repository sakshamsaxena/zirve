/*
	Problem : Check if given Binary Tree is Height Balanced or Not
*/
int height(Node* root) {
  if(root)
	return 1 + max(height(root->left), height(root->right));
  else
	return 0;
}
bool isBalanced(Node *root)
{
	// A tree is height balanced if
	// difference between heights of left and right subtrees
	// is not more than 1 for all nodes of tree.
	if(root == NULL) {
		return true;
	}
	return isBalanced(root->left) && isBalanced(root->right) && (abs(height(root->left) - height(root->right)) <= 1);
}
