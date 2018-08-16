/*
	Problem : Tom and Jerry
*/
#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		/*
		Proof :
		"Optimal" strategy is to subtract the minimum factor from N,
		which is 1. Only in that case we can have a deterministic
		result.
		
		1. For Odd N : Even number of steps to reach the end.
		2. For Even N : Odd number of steps to reach the end.
		*/
		cout << (N-1)%2 << endl;
	}
	return 0;
}