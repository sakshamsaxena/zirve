/*
	Problem :
	Circular Tour / Truck Tour
	N Petrol Pumps in a circle. Find the starting station so that it can do a circle.
*/

/*
The structure of petrolPump is
struct petrolPump
{
	int petrol;
	int distance;
};*/
/*You are required to complete this method*/
int tour(petrolPump p[],int n) {
	// All the pumps will go into a Queue
	queue<petrolPump> Q1;
	queue<petrolPump> Q2;
	
	// Populate Q1 with the entire list
	// Q2 will be a clone, operations will be done on that
	for(int i = 0; i < n; i++) {
		Q1.push(p[i]);
	}
	Q2 = Q1;
	int d = 0, f = 0, t = 0, count = 0;
	while(!Q2.empty()) {
		petrolPump pp = Q2.front();
		Q2.pop();
		d = pp.distance;
		f = pp.petrol;
		t += f-d;
		if(t < 0) {
			// Pehle khatam fuel : Fail Case : Pop and Push back and reset
			petrolPump temp = Q1.front();
			Q1.pop();
			Q1.push(temp);
			Q2 = Q1;
			t = 0; f = 0; d = 0;
			count++;
			if(count == n) {
				return -1;
			}
		}
	}
	// Q2 is empty so we're good
	return count;
}