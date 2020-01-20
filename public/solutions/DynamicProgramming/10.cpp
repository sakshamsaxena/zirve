/*
	Problem: Max Cost Path In Matrix Problem Variant
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		int mat[N][N];
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				cin >> mat[i][j];
			}
		}
		// Make an answer matrix and build it up
		int ans[N+1][N+1];
		// No data, no sum
		ans[0][0] = 0;
		// For all potential 1xN matrix, it will have the same cost
		for(int i = 1 ; i <= N; i++) {
			ans[0][i] = 0;//max(ans[0][i-1], mat[0][i-1]);
		}
		// Similar for Nx1 matrix
		for(int i = 1; i <= N; i++) {
			ans[i][0] = 0;//ans[i-1][0] + mat[i-1][0];
		}
		// Build up the rest of the array
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				// From where all can I reach [i][j] ?
				// Diagonal Top Left, Diagonal Top Right, Directly above
				ans[i][j] = max(max(ans[i-1][j-1],ans[i-1][j+1]),ans[i-1][j]) + mat[i-1][j-1];
			}
		}
		int res = -1;
		// For the last row, we have to find the max manually, but 
		// we know it's there!
		for(int i = 0; i <=N; i++) {
			if(res < ans[N][i]) {
				res = ans[N][i];
			}
		}
		cout << res << endl;
	}
	return 0;
}