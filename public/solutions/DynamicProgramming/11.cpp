/*
	Problem : Partition Problem Variant
	Given an array, the task is to divide it into two sets such
	that the absolute difference between their sums is minimum.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		int arr[N];
		int arraySum = 0;
		for(int i = 0; i < N; i++) {
			cin >> arr[i];
			arraySum += arr[i];
		}
		// Let's make an answer array
		// [i][j] is true when there exists some subset with sum j
		// in an array of length i.
		bool dp[N+1][arraySum+1];
		// 0 sum is possible for all lengths of array as we can make
		// an empty subset always whose sum will obviously be 0.
		for(int i = 0; i <= N; i++) {
			dp[i][0] = true;
		}
		// When there are no elements then we will not have any subset
		// with any positive sum.
		for(int i = 1; i <= arraySum; i++) {
			dp[0][i] = false;
		}
		// Filling up the matrix now
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= arraySum; j++) {
				// [i][j] will be true when :
				//1.If we have [i-1][j-arr[i-1]] as true and [i-1][j]
				//	as false; meaning that in i-1 length array we
				//	have at best only a subset with sum which is just
				//	short of the ith element.
				//2.If we already have [i-1][j] as true; meaning that
				//	in i-1 length array we already have a subset with
				//	sum j, so we would still have it in i length array.
				//	So we say that sum is achieved without ith element.
				if(j-arr[i-1] >= 0 && dp[i-1][j] == false) {
					if(dp[i-1][j-arr[i-1]]) {
						dp[i][j] = true;
					} else {
						dp[i][j] = false;
					}
				} else {
					if(dp[i-1][j]){
						dp[i][j] = true;
					} else {
						dp[i][j] = false;
					}
				}
			}
		}
		// Since we've to find minimum difference, we start with max.
		int diff = INT_MAX;
		// Now we've to look for a solution with N length array, where
		// there should exist a subset with sum j such that difference
		// between j and arraySum-j will be minimum. This implies that
		// ideally arraySum-j-j = 0 or j=arraySum/2, so we start here.
		for(int j = arraySum/2; j >= 0; j--) {
			if(dp[N][j]) {
				// min(abs((arraySum-j)-(j))) is min(abs(arraySum-2*j))
				// Ideal case is at j = arraySum/2, so best case for
				// us will be found closest to this condition.
				diff = arraySum - 2*j;
				// Hence we break at the first match when we start
				// closest from arraySum/2
				break;
			}
		}
		cout << diff << endl;
	}
	return 0;
}