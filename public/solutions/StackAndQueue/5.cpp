/*
	Problem :
	The task is to design and implement methods of an LRU cache. 
	DID BY VECTORS AND PAIRS.
*/


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of the class is as follows
class LRUCache
{
public:
	LRUCache(int );
	int get(int );
	void set(int , int );
};*/
/*You are required to complete below methods */
/*Inititalize an LRU cache with size N */

int s;
vector<pair<int, int>> v;
vector<pair<int, int>>::iterator it;
LRUCache::LRUCache(int N)
{
	s = N;
	v.clear();
}
/*Sets the key x with value y in the LRU cache */
void LRUCache::set(int x, int y)
{
	for (it = v.begin(); it != v.end(); it++) {
		if (it->first == x) {
			v.erase(it);
			break;
		}
	}

	if (v.size() == s) {
		v.erase(v.begin());
	}
	pair<int, int> p1 = make_pair(x, y);
	v.push_back(p1);
}
/*Returns the value of the key x if
present else returns -1 */
int LRUCache::get(int x)
{
	for (it = v.begin(); it != v.end(); it++)
		if (it->first == x) {
			pair<int, int> p1 = make_pair(it->first, it->second);
			v.erase(it);
			v.push_back(p1);
			return p1.second;
		}
	return -1;
}