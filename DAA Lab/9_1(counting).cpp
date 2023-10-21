#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"enter size:";
	cin>>n;
	int a[n],S[n];
	cout<<"enter eles:"<<endl;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int count[n];
	for(int i=0;i<n;i++)
		count[i]=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]<a[j])
				count[j]=count[j]+1;
			else
				count[i]=count[i]+1;
		}
	}
	for(int i=0;i<n;i++)
		S[count[i]]=a[i];
	cout<<"sorted:\n";
	for(int i=0;i<n;i++)
		cout<<S[i];
}
