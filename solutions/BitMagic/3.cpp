/*
	Problem :
	Given a number N and a bit number K.
	Check if K-th bit of N is set or not.
	Position of set bit should be indexed starting with 0 from LSB.
*/
#include <iostream>
using namespace std;

int main() {
	//code
	int T;
	cin >> T;
	while(T--) {
		int N, K;
		cin >> N;
		cin >> K;
		// To check at kth, shift "1" to k positions
		int checker = 1 << (K);
		// Bitwise AND of checker and N will be either 0 or not.
		// Bitwise AND cuz so many zeros will help isolate our bit
		if(N&checker) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}