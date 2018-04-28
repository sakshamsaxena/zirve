/*
	Problem :
	Given a number N and two values L and R.
	Toggle the bits in the range L to R in the binary representation of N.
*/
#include <iostream>
using namespace std;
/*
To Toggle selectively without inversion, we 
can use XOR. XOR of any bit with 1 will result
in that bit's inversion. To keep the bit as is,
we will XOR with 0 to achieve that. Thus, we
need a new number with 1 in [L,R] and 0 in 
other places, so that we can simply XOR this 
number with our input number.
*/
int main() {
	int T;
	cin >> T;
	while(T--) {
		int N, L, R;
		cin >> N >> L >> R;
		int num1 = 1 << (R); // Got a 1 at R'th place
		int num2 = 1 << (L-1); // Got a 1 at L'th place
		// complement both for the next step
		num1--;
		num2--;
		int num = num1 ^ num2; // To get set bits only in the range
		int ans = N ^ num;
		cout << ans << endl;
	}
	return 0;
}