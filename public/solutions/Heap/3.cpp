/*
	Problem : Your task is to implement the three methods
	insertKey,  deleteKey,  and extractMin on a Binary Min Heap
*/
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of the class is
class MinHeap
{
    int *harr;
    int capacity;
    int heap_size;
public:
MinHeap(int cap=100) {heap_size = 0; capacity = cap; harr = new int[cap];}
    int extractMin();
    void deleteKey(int i);
    void insertKey(int k);
};*/
MinHeap :: MinHeap(int cap=100) {
	heap_size = 0;
	capacity = cap;
	harr = new int[cap];
}
/* Removes min element from min heap and returns it */
int MinHeap ::  extractMin()
{
    if(heap_size <= 0) {
        return -1;
    }
    if(heap_size == 1) {
        heap_size--;
        return harr[0];
    }
    int root = harr[0];
    heap_size--;
    harr[0] = harr[heap_size];
    MinHeapify(0);
    return root;
}
/* Removes element from position x in the min heap  */
void MinHeap :: deleteKey(int i)
{
    if(i<0 or i>=heap_size){
        return;
    }
    harr[i] = -100;
    
    for(int i=heap_size/2 - 1; i >= 0; i--)
        MinHeapify(i);
    extractMin();
}
/* Inserts an element at position x into the min heap*/
void MinHeap ::insertKey(int k)
{
   // Your code here
   if(heap_size == capacity) {
       return;
   }
   harr[heap_size] = k;
   heap_size++;
   for(int i=heap_size/2 - 1; i >= 0; i--)
        MinHeapify(i);
}
void MinHeap::MinHeapify(int i)
{
    int l = 2*i + 1;
    int r = 2*i + 2;
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}