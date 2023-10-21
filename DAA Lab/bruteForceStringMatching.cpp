#include<iostream>
using namespace std;

int bruteForce(string text, string pattern){
	int tl = text.length();
	cout<<tl<<endl;
	int pl = pattern.length();
	cout<<pl<<endl;
	for(int i=0 ; i<=tl-pl ;i++){
		for (int j=0;j<pl;j++){
			if (text[i+j]!= pattern[j]){
				cout<<i<<endl<<j<<endl;
				break;
				
			}	  	
			if (j==(pl-1)){
				return i;
			}
	    }   
	}
	return -1;	
}

int main(){
	cout<<bruteForce("im a happy person","happy person")<<endl;
//	cout<<bruteForce("diuwhiuhwqdoi","yreiwo");
		
}
