/*
	Problem: Find the Diameter of a Binary Tree.
	The diameter of a tree is the number of nodes on the longest
	path between two leaves in the tree.
*/
int height(Node* root, int& ans) {
	if (root == NULL) {
		return 0;
	}

	int leftHeight = height(root->left, ans);
	int rightHeight = height(root->right, ans);

	// Diameter of a tree is maximum of
	// (leftHeight + rightHeight + 1) for Each Node
	ans = max(ans, 1 + leftHeight + rightHeight);

	return 1 + max(leftHeight, rightHeight);
}

/* Computes the diameter of binary tree with given root. */
int diameter(Node* root) {
	if (root == NULL) {
		return 0;
	}
	int ans = INT_MIN; // This will store the final answer
	height(root, ans);
	return ans;
}
