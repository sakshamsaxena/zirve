/*
	Problem :
	Given an input stream of n characters consisting only of small case alphabets.
	Find the first non repeating character each time a character is inserted to the stream.
*/
#include <iostream>
#include <map>
#include <queue>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		map<char,int> M;
		queue<char> Q1;
		queue<char> Q2;
		for(int i = 0; i < N; i++) {
			char c;
			cin >> c;
			if(M[c]) {
				// Char is repeating
				if(!Q1.empty() && Q1.front() == c) {
					// Our first non repeating char got repeated
					// Time to bring in the new char
					Q1.pop();
					if(Q1.empty()) {
						// We're out of em!
						cout << -1 << " ";
					} else {
						// Bring it in
						char p;
						while(!Q1.empty()) {
							p = Q1.front();
							if(M[p] >=2 ) {
								// This char has been repeated already
								Q1.pop();
							} else {
								// This looks GTG
								break;
							}
						}
						if(Q1.empty()) {
							// We're out of em!
							cout << -1 << " ";
						} else {
							cout << p << " ";
						}
					}
				} else {
					// Some other char got repeated
					M[c]++;
					if(Q1.empty()) {
						// We're out of em!
						cout << -1 << " ";
					} else {
						cout << Q1.front() << " ";
					}
				}
			} else {
				// New char
				M[c]++;
				Q1.push(c);
				cout << Q1.front() << " ";
			}
		}
		cout << endl;
	}
	return 0;
}