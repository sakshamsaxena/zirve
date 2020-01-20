/*
	Problem :
	Given an unsigned integer, swap all odd bits with even bits.
*/
#include <iostream>
using namespace std;
/*
Look closely, if you can isolate odd and even bits,
you'll see that it's just shifting right the even
bits and shifting left of odd bits and adding them
up again to make the new number. To get all odd bits,
we can AND the number with 21845(0101010101010101),
and for even bits, with 43690(1010101010101010). Add
them up to form the complete number using OR.
*/
int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		// Right shift even digit
		// Left shift odd digit
		// Add these using OR
		cout << (((N&21845)<<1)|((N&43690)>>1)) << endl;
	}
	return 0;
}