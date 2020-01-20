/*
	Problem :
	You are given two numbers A and B.
	Write a program to count number of bits needed to be flipped to convert A to B.
*/
#include <iostream>
using namespace std;
/*
Simply XOR both. Count set bits in the result.
Counting set bits is an iterative process which
involves constant ANDing with N-1, as in N-1, we
reach the first set bit, and ANDing eliminates
too. So constantly doing that would lead to final
count.
Eg, N as 1101010. N-1 will be 1101001. 
Notice the last two bits which got inverted till
the rightmost set bit. Now ANDing leads to setting
these rightmost changed bit to 0. N = 1101000. 
Note that other set bits are the same. Thus, we 
repeat this till we have absolute 0.
*/
int main() {
	int T;
	cin >> T;
	while(T--) {
	    int A, B;
	    cin >> A >> B;
	    int xo = A^B;
	    int ans = 0;
	    // Count set bits
	    while(xo) {
	        xo = xo&(xo-1);
	        ans++;
	    }
	    cout << ans << endl;
	}
	return 0;
}