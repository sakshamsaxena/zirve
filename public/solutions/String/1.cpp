/*
	Problem :
	Parenthesis Checker
*/
#include <iostream>
#include <stack>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		string s;
		cin >> s;
		stack<char> line;
		int flag = 0;
		for(int i = 0; i < s.size(); i++) {
			char b = s[i];
			if(b == '(' || b == '[' || b == '{') {
				// If it's an open bracket, always push
				line.push(b);
			} else {
				// It's a closed bracket.
				if(line.size()) {
					// ... and it isn't empty
					if((b == ']' && line.top() == '[') || (b == '}' && line.top() == '{') || (b == ')' && line.top() == '(')) {
						// so match it with the top
						line.pop();
					} else {
						// and if it doesn't match with top then we know this gonna fail
						flag = 1;
						break;
					}
				} else {
					// ... and it's an empty stack
					flag = 1;
					break;
				}
			}
		}
		if(flag == 0 && line.size() == 0) {
			cout << "balanced" << endl;
		} else {
			cout << "not balanced" << endl;
		}
	}
	return 0;
}