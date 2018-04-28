/*
	Problem :
	Given an integer an N.
	Print the position of first set bit found from right side in the binary representation of the number.
*/
#include <iostream>
#include <cmath>
using namespace std;
/*
2's Compl : 1's Compl(Inversion) + 1(@LSB/Rightmost)
2's Compl of N-bit complements wrt to 2^N.
2's Compl of a num is that num's negative.
N + (-N) = 0 in integer, though in binary it will be -0

Logic : 
For a binary number, take it's inverse, and add 1 to it's LSB.
All the unset rightmost bits in original number became set, and
adding 1 to them resulted in 10 with 1 in carry and 0 in result.
Till a 0 is encountered, carry propagates. At first 0, which
will actually be the first set bit of original number, result
gets the carry in it. Subsequent bit are simply the complements
of the remaining bits. Thus, doing a bitwise AND will result in 
setting 0 to all as-is complemented bits (left to the newly set),
and to the right of our newly set bit, we already have 0s. Thus,
we simply find the power of 2 to which this new number is to
arrive at our anser.
*/
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