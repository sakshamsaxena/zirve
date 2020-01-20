/*
	Problem :
	Find the sum of all bits from numbers 1 to N.
*/
#include <iostream>
using namespace std;

int countSetBits(int x) {
	int count = 0;
	while(x) {
		x = x&(x-1);
		count++;
	}
	return count;
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		int ans = 0;
		for(int i = 1; i <= N; i++) {
			ans += countSetBits(i);
		}
		cout << ans << endl;
	}
	return 0;
}