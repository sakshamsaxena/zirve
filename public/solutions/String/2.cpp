/*
	Problem :
	Given a String of length N reverse the words in it. Words are separated by dots.
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
	    string s;
	    cin >> s;
	    vector<string> v;
	    string temp;
	    for(int i = 0; i < s.size(); i++) {
	        if(s[i] != '.') {
	        	// YES THIS WORKS !!!
	            temp+=s[i];
	        } else {
	            v.push_back(temp);
	            temp = "";
	        }
	    }
	    if(temp.size()) {
	        v.push_back(temp);
	    }
	    for(int i = v.size()-1; i >= 0; i--) {
	        cout << v[i] << (i != 0 ? "." : "\n");
	    }
	}
	return 0;
}