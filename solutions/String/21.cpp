/*
	Problem :
	Traverse a 4x4 matrix of integers in spiral form.
*/
#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int arr[4][4];
		for(int i = 0; i < 4; i++) {
			for(int j = 0; j < 4; j++) {
				cin >> arr[i][j];
			}
		}
		int a = 0, b = 3, c = 3, d = 0, i = 0;
		while(a<c && d <b) {
			for(i=a; i <= b; i++) {
				cout << arr[a][i] << " ";
			}// 1 2 3 4
			a++;
			for(i=a; i<=c;i++) {
				cout << arr[i][c] << " ";
			}// 8 12 16
			b--;
			for(i=b; i>=d; i--) {
				cout << arr[c][i] << " ";
			}// 15 14 13
			c--;
			for(i=c; i>=a; i--) {
				cout << arr[i][d] << " ";
			}
			d++;
		}
		cout << endl;
	}
	return 0;
}