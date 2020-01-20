/*
	Problem : Staircase Problem Variant
*/
#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		// Let 'count' be an array where ith position will be the
		// solution for ith N.
		int count[N+1];
		// Base cases :
		count[0] = 1;
		count[1] = 1;
		count[2] = 2;
		for(int i = 3;i <=N; i++) {
			// As it follows this pattern of repeating solutions.
			// As I can reach N in a single step from N-3, N-2 and N-1.
			// Build up solutions array like we do in DP and done!
			count[i] = count[i-3]+count[i-2]+count[i-1];
		}
		cout << count[N] << endl;
	}
	return 0;
}