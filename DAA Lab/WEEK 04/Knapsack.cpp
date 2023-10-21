#include<iostream>
using namespace std;

//void solve2(int ci,int cwt, int cv, int wt[], int val[],int n, int cap,int answer,int bitmask);

int solve(int ci,int cwt, int cv, int wt[], int val[],int n, int cap){
	if(ci>=n){
		if(cwt<=cap){
			return cv;	
		}
		return -1;
	}
	int opt1 = solve(ci+1,cwt+wt[ci],cv+val[ci],wt,val,n,cap);	
	int opt2 = solve(ci+1,cwt,cv,wt,val,n,cap);
	return max(opt1,opt2);
}

int knapsack(int n,int wt[],int val[], int cap){
	int answer = solve(0,0,0,wt,val,n,cap);
//	solve2(0,0,0,wt,val,n,cap,answer,0);
	return answer;
	
}

//void solve2(int ci,int cwt, int cv, int wt[], int val[],int n, int cap,int answer,int bitmask){
//	if(ci>=n){
//		if(cwt<=cap){
//			if(cv==answer){
//				for(int i=0;i<n;i++){
//					if((bitmask>>i)&1){
//						cout<<i<<"\t";
//					}
//				}
//				cout<<endl;
//			}
//		}
//		return;
//	}
//	cout<<ci<<endl;
//	solve2(ci+1,cwt+wt[ci],cv+val[ci],wt,val,n,cap,answer,bitmask|(1<<ci));	
//    solve2(ci+1,cwt,cv,wt,val,n,cap,answer,bitmask);
	
//}
int main(){
	int n;
	int arr1[n];
	int arr2[n];
	int k;
	cout<<"Enter the number of elements:"<<endl;
	cin>>n;
	cout<<"Enter the weigths:";
	for(int i=0;i<n;i++){
		cin>>arr1[i];	
	}
	cout<<"Enter the values:";
		for(int j=0;j<n;j++){
		cin>>arr2[j];	
	}
	cout<<"Enter the knapsack capacity:";
	cin>>k;
//	int arr1[]={2,5,10,5};
//	int arr2[]={20,30,50,30};
	cout<<knapsack(n,arr1,arr2,k);	
}
