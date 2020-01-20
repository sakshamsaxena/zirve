/*
    Problem :
    Given an string in roman no format (s)  your task is to convert it to integer.
*/
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        string s;
        cin >> s;
        int n = 0;
        for(int i = 0; i < s.size(); i++) {
            char r = s[i];
            // 9 is IX
            // 90 is XC
            // 900 is CM
            if(r == 'M') {
                n+=1000;
            }
            if(r == 'D') {
                n+=500;
            }
            if(r == 'C') {
                n+=100;
                if(s[i+1] == 'M') {
                    n+=800;
                    i++;
                }
                if(s[i+1] == 'D') {
                    n+=300;
                    i++;
                }
            }
            if(r == 'L') {
                n+=50;
            }
            if(r == 'X') {
                n+=10;
                if(s[i+1] == 'C') {
                    n+=80;
                    i++;
                }
                if(s[i+1] == 'L') {
                    n+=30;
                    i++;
                }
            }
            if(r == 'V') {
                n+=5;
            }
            if(r == 'I') {
                n+=1;
                if(s[i+1] == 'X') {
                    n+=8;
                    i++;
                }
                if(s[i+1] == 'V') {
                    n+=3;
                    i++;
                }
            }
        }
        cout << n << endl;
    }
	return 0;
}