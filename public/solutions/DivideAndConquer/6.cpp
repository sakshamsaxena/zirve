/*
	Problem:
	Given a stream of characters consisting only '0' and '1'.
	Print the last index of the '1' present in it.
	If not present than print "-1".
*/
#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		string s;
		cin >> s;
		int ans = -1;
		for(int i = s.size()-1; i >= 0; i--) {
			if(s[i] == '1') {
				ans = i;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}