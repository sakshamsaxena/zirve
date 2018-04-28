/*
	Probelm : 
	Given an integer N and an integer D
	Rotate the binary representation of the integer N by D digits to the left as well as right.
*/
#include <iostream>
using namespace std;
/*
For any linear shift, it is important to OR between
the normal left shift (<<) and right shift of (16-D)
spaces, for 16 bit number.
*/
int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		int D;
		cin >> N >> D;
		int ans1 = ((N << D) | (N >> (16-D)));
		int ans2 = ((N >> D) | (N << (16-D)));
		cout << ans1 << endl;
		cout << ans2 << endl;
	}
	return 0;
}