/*
	Problem :
	Given a number N and a value K. 
	Set the Kth bit in the binary representation of N. The position of LSB is 0, and so on.
*/
#include <iostream>
using namespace std;
/*
To set a bit as 1, simply OR it with 1
*/
int main() {
	int T;
	cin >> T;
	while(T--) {
	    int N, K;
	    cin >> N >> K;
	    int num = 1 << K;
	    int ans = N|num;
	    cout << ans << endl;
	}
	return 0;
}