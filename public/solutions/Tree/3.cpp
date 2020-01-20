/*
	Problem : Print Bottom View of a Tree
*/
void printBottomViewUtil(Node * root,
	int currentHeight,
	int horizontalDistance,
	map <int, pair <int, int>> & m) {
	// Base case
	if (root == NULL) {
		return;
	}

	if (m.find(horizontalDistance) == m.end()) {
		// If node for a particular horizontal distance is not
		// present, add to the map.
		m[horizontalDistance] = make_pair(root -> data, currentHeight);
	} else {
		// Else compare height for already present node at similar
		// horizontal distance.
		pair < int, int > p = m[horizontalDistance];
		if (p.second <= currentHeight) {
			m[horizontalDistance].second = currentHeight;
			m[horizontalDistance].first = root -> data;
		}
	}

	// Recur for left subtree
	printBottomViewUtil(root -> left, currentHeight + 1, horizontalDistance - 1, m);

	// Recur for right subtree
	printBottomViewUtil(root -> right, currentHeight + 1, horizontalDistance + 1, m);
}

void printBottomView(Node * root) {

	// Map Horizontal Distance to Data and Height.
	map < int, pair < int, int > > m;

	printBottomViewUtil(root, 0, 0, m);

	// Prints the values stored by printBottomViewUtil()
	map < int, pair < int, int > > ::iterator it;
	for (it = m.begin(); it != m.end(); ++it) {
		pair < int, int > p = it -> second;
		cout << p.first << " ";
	}
}