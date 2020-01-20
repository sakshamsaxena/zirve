/*
	Problem :
	Given a number N.
	Find the length of the longest consecutive 1's in its binary representation.
*/
#include <iostream>
using namespace std;
/*
ANDing a number with it's left shift, reduces one 1
from all such places. In the end, the longest will
be exhausted last, and that's the count we are 
keeping as our answer.
*/
int main() {
	int T;
	cin >> T;
	while(T--) {
	    int N;
	    cin >> N;
	    int ans = 0;
	    while(N) {
	        N = N&(N<<1);
	        ans++;
	    }
	    cout << ans << endl;
	}
	return 0;
}