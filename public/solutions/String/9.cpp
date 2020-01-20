/*
	Problem : Length of Longest Common Substring
*/
#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int X, Y;
		cin >> X >> Y;
		int map[X+1][Y+1];
		int ans = 0;
		string x,y;
		cin >> x >> y;
		for(int i = 0; i <= X; i++) {
			for(int j = 0; j <=Y; j++) {
				if(i == 0 || j == 0) {
					map[i][j] = 0;
				} else {
					if(x[i-1] == y[j-1]) {
						map[i][j] = map[i-1][j-1] + 1;// Diagonally above
						ans = max(ans, map[i][j]);
					} else {
						map[i][j] = 0;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}