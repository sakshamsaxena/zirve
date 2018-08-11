/*
	Problem : Box Stacking.
	Uses basic logic and LIS concept.
*/
/*The function takes an array of heights, width and
length as its 3 arguments where each index i value
determines the height, width, length of the ith box.
Here n is the total no of boxes.*/
bool comp(vector<int> v1, vector<int> v2) {
	return v2[1]*v2[2] < v1[1]*v1[2]; // comparing area
}
int maxHeight(int height[],int width[],int length[],int n) {
	// Make a vector of 3n length, of pairs.
	vector<vector<int>> v;
	for(int i = 0; i < n; i++) {
		int a = height[i];
		int b = max(width[i],length[i]);
		int c = min(width[i],length[i]);
		vector<int> _v;
		_v.push_back(a);
		_v.push_back(b);
		_v.push_back(c);
		v.push_back(_v);
	}
	for(int i = 0; i < n; i++) {
		int a = width[i];
		int b = max(height[i],length[i]);
		int c = min(height[i],length[i]);
		vector<int> _v;
		_v.push_back(a);
		_v.push_back(b);
		_v.push_back(c);
		v.push_back(_v);
	}
	for(int i = 0; i < n; i++) {
		int a = length[i];
		int b = max(width[i],height[i]);
		int c = min(width[i],height[i]);
		vector<int> _v;
		_v.push_back(a);
		_v.push_back(b);
		_v.push_back(c);
		v.push_back(_v);
	}
	sort(v.begin(), v.end(), comp);
	int h[3*n];
	for(int i = 0; i < 3*n; i++) {
		// cout << "{" << v[i][1] << ", " << v[i][2] << ", " << v[i][0] << "}, ";
		h[i] = v[i][0];
	}
	int max = -1;
	for(int i = 1; i < 3*n; i++) {
		for(int j = 0; j < i; j++) {
			if(v[i][1] < v[j][1] && v[i][2] < v[j][2] && h[i] < h[j]+v[i][0]) {
				h[i] = h[j]+v[i][0];
			}
		}
		if(max < h[i]) {
			max = h[i];
		}
	}
	
	return max;
}