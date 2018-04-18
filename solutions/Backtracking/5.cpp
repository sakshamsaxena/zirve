/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/
int countDigit(int n)
{
	if (n == 0)
		return 0;
	return 1 + countDigit(n / 10);
}
vector<string> correctVec(vector<string> t, string pre) {
	int preI = stoi(pre);
	if(pre.size() >=2 && countDigit(preI) != pre.size()) {
		vector<string> a;
		return a;
	}
	for(int k = 0; k < t.size(); k++) {
		t[k] = pre+"."+t[k];
	}
	return t;
}
vector<string> genSubIp(string s, int x) {
	int len = s.size();
	vector <string> foo;
	if(len == 0) {
		return foo;
	}
	if(x == 1) {
		// Innermost
		// Check length
		if(s.size() > 3) {
			return foo;
		}
		// Check range
		int part = stoi(s);
		if(s.size() >=2 && countDigit(part) != s.size()) {
			return foo;
		}
		if(part <= 255 && part >= 0) {
			foo.push_back(s);
			return foo;
		} else {
			return foo;
		}
	} else {
		// Make substring and recurse
		vector <string> subIps2;
		for(int j = 1; j <= 3 && j<len; j++) {
			string w = s.substr(0, j);
			string r = s.substr(j, len-j);
			// Check range
			int part = stoi(w);
			if(part <= 255 && part >= 0) {
				vector <string> temp = genSubIp(r, x-1);
				if(temp.size() != 0) {
					temp = correctVec(temp, w);
					subIps2
					.insert(subIps2.end(), temp.begin(), temp.end());
				}
			}
		}
		return subIps2;
	}
}
void printVec(vector<string> x) {
	for(int i = 0; i < x.size(); i++) {
		cout << i+1 << ". " << x[i] << endl;
	}
}
/*You are required to complete this method*/
vector<string> genIp(string s)
{
	//Vector to return
	vector <string> ans;
	
	// Basic checks
	int len = s.size();
	if(len < 4 || len > 12) {
		return ans;
	}
	
	// Start by extracting the first part
	// It's length will be in the range [1,3]
	for(int i = 1; i <= 3; i++) {
		string first = s.substr(0,i);
		if(first.size()<=3) {
			int part = stoi(first);
			if(part <=255 && part >=1) {
				string rem = s.substr(i, len-i);
				vector <string> subIps = genSubIp(rem, 3);
				subIps = correctVec(subIps, first);
				ans.insert(ans.end(), subIps.begin(), subIps.end());
			}
		}
	}
	//printVec(ans);
	return ans;
}