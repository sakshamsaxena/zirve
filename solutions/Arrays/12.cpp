#include <iostream>
using namespace std;

int main() {
	//code
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int arr[N];
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		// initialize output
		int result = 0;

		// maximum element on left and right
		int left_max = 0, right_max = 0;

		// indices to traverse the array
		int lo = 0, hi = N - 1;

		while (lo <= hi) {
			if (arr[lo] < arr[hi]) {
				if (arr[lo] > left_max)
					// update max in left
					left_max = arr[lo];
				else
					// water on curr element = max - curr
					result += left_max - arr[lo];
				lo++;
			}
			else {
				if (arr[hi] > right_max)
					// update right maximum
					right_max = arr[hi];
				else
					result += right_max - arr[hi];
				hi--;
			}
		}
		cout << result << endl;
	}
	return 0;
}