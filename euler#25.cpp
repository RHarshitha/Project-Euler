#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,i;
	cin>>t;
	int test[t];
	for(i=0;i<t;i++)
	cin>>test[i];
	for(i=0;i<t;i++){
		int n=test[i];
		double a=(1+sqrt(5))/2,b=(1-sqrt(5))/2,i,mod=pow(10,n-1);
		for(i=1;;i++){
			 double fn= (pow(a,i)-pow(b,i))/sqrt(5);
			if((int)(fn/mod)!=0)
			break;
		}
		cout<<i<<endl;
	}
	return 0;
}
