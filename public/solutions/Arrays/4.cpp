/*
	Problem:
	Sort an array of 0's,1's and 2's in ascending order.
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		string zeros = "";
		string ones = "";
		string twos = "";
		for(int i = 0; i < N; i++) {
			int num;
			cin >> num;
			if(num == 0)
				zeros+="0 ";
			if(num == 1)
				ones+="1 ";
			if(num == 2)
				twos+="2 ";
		}
		cout << zeros << ones << twos << endl;
	}
	return 0;
}