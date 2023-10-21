#include<iostream>
using namespace std;

void bubble_sort(int arr[],int n){
	for(int i = 0;i<n-1;i++){
		for(int j=0; j<n-i-1; j++){
			if(arr[j]>arr[j+1])
			   swap(arr[j],arr[j+1]);
		}		
	}
}
int main(){
	int a1[]= {1,4,6,3,8,2,9};
	bubble_sort(a1,sizeof(a1)/sizeof(a1[0]));
	int n = sizeof(a1)/sizeof(a1[0]);
	

	int x=(++a1[0],++a1[1]);
	bool y = (true,false);
	cout<<"\n"<<x<<"\n"<<y<<endl;
	for(int i=1;i<=n,i++;){
		cout<<a1[i-1];
	}
}

// i=0
//true
// loop run
// i++
//(i=1) tr

//i=0
//i<n i++
// true 0(false)
//
