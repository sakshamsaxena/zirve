/*
	Problem : Convert a Tree to Doubly Linked List.
	Sequence should be In-Order.
*/
// root --> Root of Binary Tree
// head_ref --> Pointer to head node of created doubly linked list
void BToDLL(Node* root, Node** head_ref) {
	// Base cases
	if (root == NULL) {
		return;
	}

	// Aim is to update left and right Nodes to
	// previous and next Nodes of a DLL so that they
	// are In Order.

	// We do a Reverse In Order Traversal because
	// we are converting the tree from that end,
	// while setting DLL from there to the actual
	// position where it is required to be.

	// Recursively convert right subtree
	BToDLL(root->right, head_ref);

	// Root's right is NULL, so we update it with
	// wherever we are with the DLL.
	root->right = *head_ref;

	// If the above happens for a real integer,
	// then change left pointer of previous head.
	// Tree Nodes tend to go south, so that's why
	// we do this to make them go north.
	if (*head_ref != NULL) {
		(*head_ref)->left = root;
	}

	// Change head of Doubly linked list
	*head_ref = root;

	// Recursively convert left subtree
	BToDLL(root->left, head_ref);
}
