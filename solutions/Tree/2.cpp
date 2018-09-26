/*
  Problem : Check for BST
*/
vector<int> foo;

void inorder(Node* root) {
	if (root) {
		inorder(root->left);
		foo.push_back(root->data);
		inorder(root->right);
	}
}

bool checkBST(Node* root) {
	if (!root) {
		return true;
	} else {
		foo.clear();
		inorder(root);
		for (int i = 1; i < foo.size(); i++) {
			if (foo[i] <= foo[i - 1]) {
				return false;
			}
		}
		return true;
	}
}