/*
    Problem : Vertical Traversal of a Binary Tree
*/
void printVertical(Node *node, int dist, multimap<int, int> &map)
{
    // base case: empty tree
    if (node == NULL)
        return;

    // insert nodes present at current horizontal distance into the multimap
    map.insert(make_pair(dist, node->data));

    // recurse for left subtree by decreasing horizontal distance by 1
    printVertical(node->left, dist - 1, map);

    // recurse for right subtree by increasing horizontal distance by 1
    printVertical(node->right, dist + 1, map);
}
void verticalOrder(Node *root)
{
    // create an empty multimap where
    // key -> relative horizontal distance of the node from root node and
    // value -> nodes present at same horizontal distance.
    // Multimaps can have array of values for same key.
    // we can also use map<int, vector<int>> instead of multimap<int, int>
    multimap<int, int> map;

    // do pre-order traversal of the tree and fill the map
    // Pre-order, because we want to start with the root
    printVertical(root, 0, map);

    // traverse the map and print vertical nodes
    int temp = 0;
    for (multimap<int, int>::iterator it = map.begin(); it != map.end(); it++)
    {
        cout << it->second << " ";
    }
}