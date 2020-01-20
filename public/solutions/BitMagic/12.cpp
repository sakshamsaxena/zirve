/*
	Problem :
	Given a number, check whether it is sparse or not.
	A number is said to be a sparse number if no two or more consecutive bits are set.
*/
#include <iostream>
using namespace std;
/*
If no two or more set bits are there, then
on ANDing it's left shift with itself will
give absolute 0. 
*/
int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		int num = N << 1;
		if(N&num) {
			cout << 0 << endl;
		} else {
			cout << 1 << endl;
		}
	}
	return 0;
}