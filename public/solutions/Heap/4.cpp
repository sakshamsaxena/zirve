/*
	Problem : Given a string with repeated characters
	Task is to rearrange characters in a string such that no 2 adjacent characters are same.
*/
#include <iostream>
#include <map>
using namespace std;
// No need of PQ
int main() {
	int T;
	cin >> T;
	while(T--) {
		string s;
		cin >> s;
		map<char, int> m;
		int max = 0;
		for(int i = 0; i < s.size(); i++) {
			m[s[i]]++;
			if(m[s[i]] > max) {
				max = m[s[i]];
			}
		}
		int a = s.size();
		int lim;
		// Max frequent char should be able to spread evenly
		if(a%2) {
			lim = (a-1)/2 + 1;
		} else {
			lim = a/2;
		}
		if(max <= lim) {
			cout << 1 << endl;
		} else {
			cout << 0 << endl;
		}
	}
	return 0;
}