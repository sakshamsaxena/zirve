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
		int K[N+1][W+1], Keep[N+1][W+1];
		for(int w = 0; w <= W; w++) {
			K[0][w] = 0;
			Keep[0][w] = 0;
		}
		for(int i = 0; i <= N; i++) {
			K[i][0] = 0;
			Keep[i][0] = 0;
		}
		for(int i = 1; i <= N; i++) {
			for(int w = 1; w <= W; w++) {
				if(w - wt[i-1] >= 0 && val[i-1] + K[i-1][w - wt[i-1]] > K[i-1][w]) {
					K[i][w] = val[i-1] + K[i-1][w - wt[i-1]];
					Keep[i][w] = 1;
				} else {
					K[i][w] = K[i-1][w];
					Keep[i][w] = 0;
				}
			}
		}
		cout << K[N][W] << endl;
		int P = W;
		for(int i = N; i >= 1; i--) {
			if(Keep[i][P] == 1) {
				cout << "Set {" << val[i-1] << ", " << wt[i-1] << "} was kept" << endl;
				P = P - wt[i-1];
			}
		}
	}
	return 0;
}