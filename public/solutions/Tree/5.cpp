/*
	Problem : Level Order Traversal in "Spiral" (wavey) form.
	It looks like an attenuated sine wave rotated 90 degrees counter-clockwise.
*/
void printSpiral(struct Node *root) {
	if (root == NULL) {
		return;
	}
	// Create two stacks to store alternate levels
	stack<struct Node*> s1; // For levels to be printed from right to left
	stack<struct Node*> s2; // For levels to be printed from left to right

	// Push first level to first stack 's1'
	s1.push(root);

	// Keep printing while any of the stacks has some Nodes
	while (!s1.empty() || !s2.empty()) {
		// Print Nodes of current level from s1 and push Nodes of
		// next level to s2
		while (!s1.empty()) {
			struct Node *temp = s1.top();
			s1.pop();
			cout << temp->data << " ";

			// Note that is right is pushed before left
			if (temp->right) {
				s2.push(temp->right);
			}
			if (temp->left) {
				s2.push(temp->left);
			}
		}

		// Print Nodes of current level from s2 and push Nodes of
		// next level to s1
		while (!s2.empty()) {
			struct Node *temp = s2.top();
			s2.pop();
			cout << temp->data << " ";

			// Note that is left is pushed before right
			if (temp->left) {
				s1.push(temp->left);
			}
			if (temp->right) {
				s1.push(temp->right);
			}
		}
	}
}
