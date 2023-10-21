#include<iostream>
using namespace std;
void shiftable(string P,int table[])
{
	//int table[26];
	int m=P.size();
	for(int i=0;i<26;i++)
		table[i]=m;
	for(int j=0;j<m-1;j++)
	{
		table[int(P[j])-97]=m-1-j;
	}
}
int horsepool_matching(string P,string T)
{
	int table[26];
	shiftable(P,table);
	//for(int i=0;i<26;i++)
	//	cout<<table[i];
	int m=P.size();
	int n=T.size();
	//cout<<"n:"<<n;
	int i=m-1;
	while(i<=n-1)
	{
		int k=0;
		while(k<=m-1 && P[m-1-k]==T[i-k])
			k++;
		if(k==m)
			return i-m+1;
		else
		{
			i=i+table[int(T[i])-97];
			//cout<<"i:"<<i;
		}
	}
	return -1;
}
int main()
{
	cout<<"enter statement"<<endl;
	string P,T;
	getline(cin,T);
	cout<<"enter search text"<<endl;
	getline(cin,P);
	int s=horsepool_matching(P,T);
	cout<<"ans:"<<s;
}
