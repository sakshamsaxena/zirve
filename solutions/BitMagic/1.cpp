/*
	Problem :
	Given an integer an N.
	Print the position of first set bit found from right side in the binary representation of the number.
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		if(N == 0) {
			cout << 0 << endl;
		} else {
			int ans = N&(-N); // Bitwise AND of N with it's Two's Complement
			ans = log2(ans); // Gets the 0 based index
			ans+=1; // For Humans
			cout << ans << endl;
		}
	}
	return 0;
}