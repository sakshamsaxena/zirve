/*
	Problem : Find median in a stream
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	long int median = 0;
	vector<long int> temp;
	priority_queue<long int> righty;
	priority_queue<long int, vector<long int>, greater<long int>> lefty;
	while(N--) {
		long int num;
		cin >> num;
		temp.push_back(num);
		// Check heap sizes first and then push
		if(lefty.size() > righty.size()) {
			// Difference is only but yeah it means ODD length
			if(num > median) {
				// That's lefty calling, but needs readjustment
				righty.push(lefty.top());
				lefty.pop();
				lefty.push(num);
			} else {
				// That's the righty calling
				righty.push(num);
			}
			median = (lefty.top() + righty.top())/2;
		} else if(lefty.size() == righty.size()) {
			if(num > median) {
				lefty.push(num);
				median = lefty.top();
			} else {
				righty.push(num);
				median = righty.top();
			}
		} else if(lefty.size() < righty.size()) {
			// Difference is only but yeah it means ODD length
			if(num > median) {
				// That's the lefty calling
				lefty.push(num);
			} else {
				// That's rightty calling, but needs readjustment
				lefty.push(righty.top());
				righty.pop();
				righty.push(num);
			}
			median = (lefty.top() + righty.top())/2;
		}
		cout << median << endl;
	}
	return 0;
}