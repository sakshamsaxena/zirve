/*
	Problem :
	Given a positive integer N, check if N is a power of 2.
*/
#include <iostream>
using namespace std;
/*
If N is of power of 2, then AND of N and N-1
will be absolute 0
*/
int main() {
	int T;
	cin >> T;
	while(T--) {
	    long int N;
	    cin >> N;
	    long int ans;
	    if(N) {
	        ans = !(N&(N-1));
	    } else {
	        ans = 0;
	    }
	    cout << ((ans) ? "YES" : "NO") << endl;
	}
	return 0;
}