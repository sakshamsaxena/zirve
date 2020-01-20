/*
	Problem :
	Given two array A1[] and A2[]
	Sort A1 in such a way that the relative order among the elements will be same as those in A2.
	For the elements not present in A2, append them at last in sorted order.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int M,N;
		cin >> M >> N;
		int arr1[M];
		int arr2[N];
		for(int i = 0; i < M; i++) {
			cin >> arr1[i];
		}
		for(int i = 0; i < N; i++) {
			cin >> arr2[i];
		}
		vector<int> ans;
		for(int i = 0; i < N; i++) {
			int s = arr2[i];
			for(int j = 0; j < M; j++) {
				if(arr1[j] == s) {
					ans.push_back(s);
					arr1[j] = 0;
				}
			}
		}
		sort(arr1, arr1+M);
		for(int p = ans.size(); p < M; p++) {
			ans.push_back(arr1[p]);
		}
		for(int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
}