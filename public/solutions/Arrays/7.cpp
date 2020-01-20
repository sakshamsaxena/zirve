/*
	Problem :
	Write a program to print all the LEADERS in the array.
	An element is leader if it is greater than all the elements to its right side
*/
#include <iostream>
#include <vector>
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
		int max = -1;
		vector<int> ans;
		for(int i = N-1; i >= 0; i--) {
			if(arr[i] > max) {
				ans.push_back(arr[i]);
				max = arr[i];
			}
		}
		for(int i = ans.size()-1; i >=0; i--) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
