/*
	Problem :
	Given a string, print all permutations of a given string.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		do {
			cout << s << " ";
		} while (next_permutation(s.begin(), s.end()));
		cout << endl;
	}
	return 0;
}