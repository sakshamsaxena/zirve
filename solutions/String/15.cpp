/*
	Problem :
	Print the longest common prefix as a string in the given array.
	If no such prefix exists print -1.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		vector<string> V(N);
		for(int i = 0; i < N; i++) {
			cin >> V[i];
		}
		if(V.size() == 1) {
			cout << V[0] << endl;
		} else {
			int bad = 0;
			int l = 0;
			for(int i = 0; i < 100; i++) {
				for(int j = 1; j < N; j++) {
					if(V[0][i] != V[j][i]) {
						bad = 1;
						break;
					}
				}
				if(bad) {
					if(l==0) {
						cout << -1 << endl;
					} else {
						string s = V[0];
						cout << s.substr(0,l) << endl;
					}
					break;
				} else {
					l++;
				}
			}
		}
	}
	return 0;
}