/*
	Problem :
	Given two strings, check whether two given strings are anagram of each other or not.
*/
#include <iostream>
#include <map>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
	    string a, b;
	    cin >> a >> b;
	    map<char,int> m;
	    int flag = 0;
	    if(a.size() != b.size()) {
	        cout << "NO" << endl;
	    } else {
    	    for(int i = 0; i < a.size(); i++) {
    	        m[a[i]] += 1;
    	    }
    	    for(int i = 0; i < b.size(); i++) {
    	        if(m[b[i]]>0) {
    	            m[b[i]] -=1;
    	        } else {
    	            flag = 1;
    	            break;
    	        }
    	    }
    	    if(flag == 0) {
    	        cout << "YES" << endl;
    	    } else {
    	        cout << "NO" << endl;
    	    }
	    }
	}
	return 0;
}