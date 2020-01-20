/*
	Problem : 
	Determine what is the minimum time required so that all the oranges become rotten.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int R, C;
		cin >> R >> C;
		vector<vector<int>> V(R);
		for(int i = 0; i < R; i++) {
			for(int j = 0; j < C; j++) {
				int a;
				cin >> a;
				V[i].push_back(a);
			}
		}
		// Logic
		queue<int> q2;
		bool foundAOne = false;
		bool foundATwo = false;
		bool workDone = false;
		int count = 0;
		while(true) {
			// Search for 2 and 1
			for(int i = 0; i < R; i++) {
				for(int j = 0; j < C; j++) {
					// If I find a 2 ...
					if(V[i][j] == 2) {
						// Put it in a Queue
						q2.push(i);
						q2.push(j);
					}
					if(V[i][j] == 1) {
						foundAOne = true;
					}
				}
			}
			// Rot the neighbours if they are 1
			if(!q2.empty()) {
				foundATwo = true;
			}
			while(!q2.empty()) {
				int x = q2.front(); q2.pop();
				int y = q2.front(); q2.pop();
				if(x-1>=0 && V[x-1][y] == 1) {
					workDone = true;
					V[x-1][y] = 2;
				}
				if(x+1< R && V[x+1][y] == 1) {
					V[x+1][y] = 2;
					workDone = true;
				}
				if(y-1>=0 && V[x][y-1] == 1) {
					V[x][y-1] = 2;
					workDone = true;
				}
				if(y+1< C && V[x][y+1] == 1) {
					V[x][y+1] = 2;
					workDone = true;
				}
			}
			if(foundAOne && foundATwo && workDone) {
				// We found some fresh ones and rotten
				// And rotted the fresh ones
				foundAOne = false;
				foundATwo = false;
				workDone = false;
				count++;
			} else if(foundATwo && !foundAOne && !workDone){
				// We didn't find any fresh orange in search
				break;
			} else {
				// Or there are no rotten ones
				// Or we can't rot the fresh ones anymore
				count = -1;
				break;
			}
		}
		cout << ((count != 0) ? count : -1) << endl;
	}
	return 0;
}