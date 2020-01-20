/*
	Problem : Egg Dropping Puzzle
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N, K;
		cin >> N >> K;
		// eggsAndFloors[i][j] are minimum number of trials needed
		// for i eggs and j floors
		int eggsAndFloors[N+1][K+1];
		
		// 1 trial for 1 floor, 0 trial for 0 floor.
		for(int i = 1; i <= N; i++) {
			eggsAndFloors[i][0] = 0;
			eggsAndFloors[i][1] = 1;
		}
		
		// 1 egg will require max trials that of the floor
		for(int i = 1; i <= K; i++) {
			eggsAndFloors[1][i] = i;
		}
		
		// Update the table using the algorithm
		for(int i = 2; i <= N; i++) {
			// Taken i eggs, climbing up the floors
			for(int j = 2; j <= K; j++) {
				// Assume infinite solutions for current floor
				eggsAndFloors[i][j] = INT_MAX;
				// Calculate solutions for the current floor by calculating it
				// from other solutions, that is, start dropping i eggs from 
				// each of the floor starting from 1. Indeed the solution for 
				// [i][j] is obtained by using sets of previous solutions and
				// finding the most optimal (minimum) of those.
				for(int x = 1; x <= j; x++) {
					// In a j floor building with initial i eggs : 
					// At x floor, it can break or it can not.
					// Either it breaks, so we check x-1 floors with i-1 eggs.
					// If it doesn't, then we check j-x floors with i eggs.
					int res = 1 + max(eggsAndFloors[i-1][x-1], eggsAndFloors[i][j-x]);
					// Keep finding the minimum of the results calculated
					if(res < eggsAndFloors[i][j]) {
						eggsAndFloors[i][j] = res;
					}
				}
			}
		}
		
		cout << eggsAndFloors[N][K] << endl;
	}
	return 0;
}