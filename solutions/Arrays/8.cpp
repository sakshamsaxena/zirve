/*
	Problem:
	Given arrival and departure times of all trains that reach a station.
	Find the minimum number of platforms required so that no train waits.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
bool myfunc(pair<int, char> temp1, pair<int, char> temp2) {
	if(temp1.first < temp2.first) {
		return true;
	}
	if(temp1.first > temp2.first) {
		return false;
	}
	if(temp1.first == temp2.first) {
		if(temp1.second == 'd' && temp2.second == 'a') {
			return true;
		}
		if(temp1.second == 'a' && temp2.second == 'd') {
			return false;
		}
		if(temp1.second == temp2.second) {
			return true;
		}
	}
}
int main() {
	int T;
	cin >> T;
	while(T--) {
		int N, n;
		cin >> N;
		n = 2*N;
		vector<pair<int, char>> times;
		pair<int, char> temp;
		for(int i = 0; i < N; i++) {
			int t;
			cin >> t;
			temp = make_pair(t, 'a');
			times.push_back(temp);
		}
		for(int i = 0; i < N; i++) {
			int t;
			cin >> t;
			temp = make_pair(t, 'd');
			times.push_back(temp);
		}
		sort(times.begin(), times.end(), myfunc);
		int max = 1;
		int platforms = 0;
		for(int i = 0; i < n; i++) {
			if(times[i].second == 'a') {
				platforms++;
			}
			if(times[i].second == 'd') {
				platforms--;
			}
			if(max < platforms) {
				max = platforms;
			}
		}
		cout << max << endl;
	}
	return 0;
}