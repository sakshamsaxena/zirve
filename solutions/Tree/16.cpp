/*
	Problem: Serialize and Desearlize Binary Tree
*/

void serialize(Node *root, vector<int> &A) {
	if (root == NULL) {
		A.push_back(-1);
		return;
	}
	A.push_back(root->data);
	serialize(root->left, A);
	serialize(root->right, A);
}

int ind;

Node *makeTree(Node *root, vector<int> A) {
	if (ind == A.size())
		return NULL;
	if (A[ind] == -1) {
		ind++;
		return NULL;
	}

	// Make a new Node
	root = new Node;
	root->data = A[ind];
	root->left = NULL;
	root->right = NULL;

	// Increment Index
	ind++;

	// Make subtrees
	root->left = makeTree(root->left, A);
	root->right = makeTree(root->right, A);
	return root;
}

Node *deSerialize(vector<int> &A) {
	ind = 0;
	Node *root = NULL;
	return makeTree(NULL, A);
}
