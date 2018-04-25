/*
	Problem :
	Given two strings, find if a string A can be obtained by rotating string B by two places.
*/
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        string a;
        string b;
        cin >> a >> b;
        string a_ac = a.substr(2, a.size()-2) + a.substr(0,2);
        string a_c = a.substr(a.size()-2, 2) + a.substr(0, a.size()-2);
        if(b == a_ac || b == a_c) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
	return 0;
}