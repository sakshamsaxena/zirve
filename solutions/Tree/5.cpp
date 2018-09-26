/*
	Problem : Lowest Common Ancestor in a BST. Find the lowest common ancestor of the two nodes.
*/
Node* LCA(Node *root, int v1, int v2)
{
	if (v1 < root->data && v2 < root->data ) {
		root = LCA(root->left, v1, v2);
	}
	if (v1 > root->data && v2 > root->data ) {
		root = LCA(root->right, v1, v2);
	}
	return root;
}