/*
	Problem : Check if a tree is symmetric or not
*/
bool _isSymmetric(struct Node*r1, Node*r2) {
	// Both NULL is also symmetry
	if (r1 == NULL && r2 == NULL) {
		return true;
	}
	// Either NULL is not symmetric
	if (r1 == NULL || r2 == NULL) {
		return false;
	}
	// Different keys isn't symmetric
	if (r1->key != r2->key) {
		return false;
	}
	// Recur till (ideally) we reach leaves at same time to return null
	// Also note that we're basically checking if two subtrees are identical or not
	// by traversing one tree in opposite direction than the first.
	return _isSymmetric(r1->right, r2->left) && _isSymmetric(r1->left, r2->right);
}

bool isSymmetric(struct Node* root) {
	if (root == NULL) {
		return true;
	}
	// Symmmetric Nodes are both NULL
	if (root->right == NULL && root->left == NULL) {
		return true;
	}
	// Either of the symmetric node is NULL
	if (root->right == NULL || root->left == NULL) {
		return false;
	}
	// Defer to a separate recursive function for subtrees
	return _isSymmetric(root->right, root->left);
}