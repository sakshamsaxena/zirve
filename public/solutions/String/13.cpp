/*
	Problem :
	Your task  is to implement the function atoi. The function takes a string(str) as argument and converts it to an integer and returns it.
*/
int atoi(string str)
{
    int l = str.size();
    int res = 0;
    bool neg = false;
    for(int i = 0, j = l-1; i < l; i++, j--) {
        // check if number or not
        char c = str[i];
        int C = (int)c;
        if(C >= 48 && C <= 57) {
            int digit = C - 48;
            int power = (int)pow(10, j);
            res+=(digit*power);
        } else if(C == 45) {
            neg = true;
        } else {
            return -1;
        }
    }
    if(neg) {
        return -res;
    }
    return res;
}