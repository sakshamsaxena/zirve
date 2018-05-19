/*
	Problem :
	Given a string S, find the longest palindromic substring in S.
	Incase of conflict, return the substring which occurs first
*/
#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		string s;
		cin >> s;
		int n = s.size();
		bool arr[n][n];
		int maxlen = 1;
		int initind = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(i==j) {
					// Strings of length 1
					arr[i][i] = true;
				} else {
					arr[i][j] = false;
				}
			}
		}
		// Strings of length 2
		for(int i = 0; i < n-1; i++) {
			if(s[i] == s[i+1]) {
				if(maxlen != 2) { //take only first
					initind = i;
					maxlen = 2;
				}
				arr[i][i+1] = true;
			}
		}
		// Strings of length >2
		for(int len = 3; len <= n; len++) {
			for(int i = 0; i < n-len+1; i++) {
				int p = i; // Beginning index
				int q = i+len-1; // Ending index
				if(s[p] == s[q] && arr[p+1][q-1]) {
					// If opposite letters match and the string in between
					// does too, then we've a palindrome
					arr[p][q] = true;
					if(len > maxlen) { //take only first
						maxlen = len;
						initind = i;
					}
				}
			}
		}
		cout << s.substr(initind,maxlen) << endl;
	}
	return 0;
}