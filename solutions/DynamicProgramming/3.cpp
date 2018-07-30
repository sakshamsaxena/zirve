/*
	Problem : Knapsack Problem
	http://www.es.ele.tue.nl/education/5MC10/Solutions/knapsack.pdf
*/
#include<iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int W, N;
		cin >> N >> W;
		int val[N], wt[N];
		for(int i = 0; i < N; i++) {
			cin >> val[i];
		}
		for(int i = 0; i < N; i++) {
			cin >> wt[i];
		}
		int K[N+1][W+1];
		for(int w = 1; w <= W; w++) {
			K[0][w] = 0;
		}
		for(int i = 0; i <= N; i++) {
			K[i][0] = 0;
		}
		for(int i = 1; i <= N; i++) {
			for(int w = 1; w <= W; w++) {
				if(w - wt[i-1] >= 0) {
					int a = val[i-1] + K[i-1][w - wt[i-1]];
					int b = K[i-1][w];
					K[i][w] = max(a,b);
				} else {
					K[i][w] = K[i-1][w];
				}
			}
		}
		cout << K[N][W] << endl;
	}
	return 0;
}