/*
	Problem :
	Given an array A[] of N integers where each value represents number of chocolates in a packet.
	Each packet can have variable number of chocolates.
	There are m students, the task is to distribute chocolate packets such that :
	1. Each student gets one packet.
	2. The difference between the number of chocolates 
	in packet with maximum chocolates and packet with minimum chocolates is minimum.
	Output this min difference.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N, M;
		cin >> N;
		int arr[N];
		for(int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		cin >> M;
		if(M == 1) {
			cout << 0 << endl;
		} else {
			sort(arr,arr+N);
			int min = 100000;
			int ind = -1;
			for(int i = 0; i < N-M+1; i++) {
				if(arr[i+M-1] - arr[i] < min) {
					min = arr[i+M-1] - arr[i];
					ind = i;
				}
			}
			cout << min << endl;
		}
	}
	return 0;
}