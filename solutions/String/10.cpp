/*
	Problem :
	Given a string, remove duplicates from it. Note that original order of characters must be kept same.
*/
#include <iostream>
#include <map>
using namespace std;

int main() {
	int T;
	cin >> T >> ws;
	while(T--) {
		string s;
		getline(cin,s);
		map<char,int> m;
		string ans = "";
		for(int i = 0; i < s.size(); i++) {
			m[s[i]]+=1;
		}
		for(int i = 0; i < s.size(); i++) {
			if(m[s[i]]) {
				ans+=s[i];
				m[s[i]] = 0;
			}
		}
		cout << ans << endl;
	}
	return 0;
}