/*
	Problem :
	The cost of a stock on each day is given in an array.
	Find the max profit that you can make by buying and selling in those days. 
*/
#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		int arr[N];
		for(int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		bool notPrinted = true;
		int flag = 0;
		for(int i = 0; i < N-1; i++) {
			if(arr[i] < arr[i+1] && notPrinted) {
				cout << "(" << i;
				notPrinted = false;
				flag = 1;
			}
			if(arr[i] > arr[i+1] && !notPrinted) {
				cout << " " << i << ") ";
				notPrinted = true;
			}
			if(i==N-2 && !notPrinted) {
				cout << " " << i+1 << ") ";
			}
		}
		if(flag == 0) {
			cout << "No Profit" << endl;
		} else {
			cout << endl;
		}
	}
	return 0;
}