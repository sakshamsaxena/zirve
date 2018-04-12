/*
	Problem:
	Given an array of size n-1 and given that there are numbers from 1 to n with one missing.
	Find the missing number.
*/

#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
	    int N;
	    cin >> N;
	    int idealSum = N*(N+1)/2;
	    int actualSum = 0;
	    for(int i=0;i<N-1;i++) {
	        int temp;
	        cin >> temp;
	        actualSum+=temp;
	    }
	    cout << (idealSum - actualSum) << endl;
	}
	return 0;
}