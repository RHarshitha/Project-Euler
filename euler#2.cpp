#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ll t;
	cin>>t;
	ll tst[t];
	for(ll i = 0;i<t;i++)
	cin>>tst[i];
	
	for(ll i=0;i<t;i++){
		ll n = tst[i],a=1,b=1,c=a+b,sum=0;
		while(c<n){
			if(c%2==0)
				sum+=c;
			a=b,b=c,c=a+b;
		}
		cout<<sum<<endl;
	}
	return 0;
}
