/*
	Problem : Maximum Path Sum
*/
int maxPathSumUtil(struct Node *root, int &res) {
	// This function calculates two values:
	// 1) Maximum path sum between two leaves, stored in res.
	// 2) The maximum root to leaf path sum which is returned.
	// If one side of root is empty, then it returns INT_MIN

	// Base cases
	if (root == NULL) {
		return 0;
	}
	if (root->left == NULL && root->right == NULL) {
		return root->data;
	}

	// Find maximum sum in left and right subtree. Also
	// find maximum root to leaf sums in left and right
	// subtrees and store them in ls and rs
	int ls = maxPathSumUtil(root->left, res);
	int rs = maxPathSumUtil(root->right, res);

	// If both left and right children exist
	if (root->left && root->right) {
		// Update result if needed
		res = max(res, ls + rs + root->data);

		// Return maxium possible value for root being
		// on one side
		return max(ls, rs) + root->data;
	}

	// If any of the two children is empty, return
	// root sum for root being on one side
	if (root->left == NULL) {
		return rs + root->data;
	} else {
		return ls + root->data;
	}
}

// The main function which returns sum of the maximum
// sum path between two leaves. This function mainly
// uses maxPathSumUtil()
int maxPathSum(struct Node *root)
{
	int res = INT_MIN;
	maxPathSumUtil(root, res);
	return res;
}
