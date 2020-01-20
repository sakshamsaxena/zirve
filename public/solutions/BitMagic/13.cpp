/*
	Problem :
	In a party everyone is in couple except one.
	People who are in couple have same numbers. Find out the person who is not in couple.
*/
#include <iostream>
using namespace std;
/*
XORing a sequence of numbers works the same.
If there are duplicates then it will give 0.
Anything XORd with a 0 gives back the number.
Since all are duplicates except one, the
duplicates will produce 0 and finally it will
XOR with the odd one out to produce the same
number, which will be our result.
*/
int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		int arr[N];
		int res = 0;
		for(int i = 0; i < N; i++) {
			cin >> arr[i];
			res = res^arr[i];
		}
		cout << res << endl;
	}
	return 0;
}