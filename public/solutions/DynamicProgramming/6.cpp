/*
	Problem : Coin Change (All the ways to change N)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int M;
		cin >> M;
		int S[M];
		for(int i = 0; i < M; i++) {
			cin >> S[i];
		}
		int N;
		cin >> N;
		// Logic
		// We find solutions to sub problems.
		// We find it by iteratively calculating for each i till N
		// by taking j coin values at a time.
		int A[N+1];
		A[0] = 1;
		for(int i = 1; i <=N; i++) {
			A[i] = 0;
		}
		// We iterate over the coin value array,
		// filling up the answer array with all the possible ways
		// to form that particular value with the coins.
		for(int i = 0; i < M; i++) {
			// [j-S[i]] is the value at previous 'step' of ith coin value,
			// and the addition happens over that solutions existing value.
			// Finally, we start with the point of coin value so that
			// [j-S[i]] is meaningful.
			for(int j = S[i]; j <= N; j++) {
				A[j] += A[j-S[i]];
			}
		}
		cout << A[N] << endl;
	}
	return 0;
}