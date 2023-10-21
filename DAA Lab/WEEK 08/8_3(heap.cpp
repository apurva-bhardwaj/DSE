 #include<iostream>
 using namespace std;
 void heap(int *h,int n)
 {
 	for(int i=n/2;i>=1;i--)
 	{
 		int k=i;
 		int v=h[k];
 		bool heap=false;
 		while(not heap and 2*k<=n)
 		{
 			int j=2*k;
 			if(j<n)
 			{
 				if(h[j]<h[j+1])
 					j++;
			}
			if(v>=h[j])
				heap=true;
			else
			{
				h[k]=h[j];
				k=j;
			}
		}
		h[k]=v;
	 }
 }
int deleteRoot(int *h, int n)
    {
        // Get the last element
        int lastElement = h[n];
        int del=h[1];
        // Replace root with first element
        h[1] = lastElement;
        h[n]=del;
        // Decrease size of heap by 1
        //n = n - 1;
 
        // heapify the root node
        heap(h, n-1);
 
        // return new size of Heap
        return n;
    }
 int main()
 {
 	int n;
 	cout<<"size of heap:";
 	cin>>n;
 	cout<<"enter eles\n";
 	int h[n+1];
 	for(int i=1;i<=n;i++)
 		cin>>h[i];
 	heap(h,n);
 	int n1=n;
 	for(int i=0;i<n;i++)
 		deleteRoot(h,n1--);
 	cout<<"sorted:"<<endl;
 	for(int i=1;i<=n;i++)
 		cout<<h[i]<<" ";
 }
