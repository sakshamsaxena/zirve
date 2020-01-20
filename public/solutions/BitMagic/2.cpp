/*
	Problem :
	Given two numbers M and N. 
	Find the position of rightmost different bit in binary representation of numbers.
*/
#include <iostream>
#include <cmath>
using namespace std;
/*
First, we'll XOR both to get a set bit when the bits differ.
Then, it's the previous problem : Find the position of this 
set bit. Do a 2's complement of this XOR'd result, and get 
the required position.
*/
int main() {
	int T;
	cin >> T;
	while(T--) {
		int N, M;
		cin >> N >> M;
		int X = M^N; // Bitwise XOR of N and M to get set bits only when bits differ
		int ans = log2(X&-X); // Gets the 0 based index
		ans+=1; // For Humans
		cout << ans << endl;
	}
	return 0;
}