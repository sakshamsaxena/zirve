/*
	Problem :
	Locate the occurrence of the string x in the string s.
	Return the integer denoting first occurrence of the string x.
*/
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The function should return position where the target string 
   matches the string str
Your are required to complete this method */
int strstr(string s, string x) {
    // Find x in s
    
    // Basic checks
    if(x.size() > s.size()) {
        return -1;
    }
    if(x.size() == s.size()) {
        if(x == s) {
            return 0;
        } else {
            return -1;
        }
    }
    
    // Get window size
    int p = s.size() - x.size() + 1;
    int l = x.size();
    for(int i = 0; i < p; i++) {
        string test = s.substr(i, l);
        if(test == x) {
            return i;
        }
    }
    return -1;
}