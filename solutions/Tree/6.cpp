/*
	Problem : Connect Nodes at Same Level.
	Node structure is extended to reference another
	horizontal Node which is exactly right to it.
*/
void connect(struct Node* root) {
	// Extends Level Order Traversal
	queue < Node * > q;

	// Push root node as usual
	q.push(root);

	// Push NULL to represent end of current level
	q.push(NULL);

	// Do Level order of tree using NULL markers
	while (!q.empty()) {
		Node *p = q.front();
		q.pop();
		if (p != NULL) {
			// next element in queue represents next
			// node at current Level
			p->nextRight = q.front();

			// push left and right children of current
			// node
			if (p->left)
				q.push(p->left);
			if (p->right)
				q.push(p->right);
		} else if (!q.empty()) {
			// if queue is not empty, push NULL to mark
			// nodes at this level are visited
			q.push(NULL);
		}
	}
}
