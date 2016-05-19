#include <bits/stdc++.h>
using namespace std;

typedef long unsigned int lu;

lu sum(int a,int d,lu n){
	if(n==0)
		return 0;
	return (n*(2*a+(n-1)*d))/2;
}

int main(){
	lu t;
	cin>>t;
	lu trail[t];
	for(lu i=0;i<t;i++){
		cin>>trail[i];
	}
	
	
	for(lu i=0;i<t;i++){
		lu n= trail[i];
			lu sum3= sum(3,3,(n-1)/3),sum5= sum(5,5,(n-1)/5),sum15 = sum(15,15,(n-1)/15); 
			if(n<=15){
				if(n<=5){
					if(n<=3){
						cout<<0<<endl;
						continue;}
					cout<<sum3<<endl;
					continue;
				}
				cout<<sum3+sum5<<endl;
			}
			else
			cout<<sum3+sum5-sum15<<endl;
		}

	return 0;
}
