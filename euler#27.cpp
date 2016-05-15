#include<bits/stdc++.h>
using namespace std;

int check(int n){
	int i;
		if(n==1)
		return 0;
		
		for(i=2;i<=n/2;i++){
			if(n%i==0)
			return 0;
		}
		cout<<n<<endl;
	return 1;
	}


int main(){

	int i,n,a,b,max=0,A,B;
	cin>>n;
	
	for(b=n;b>0;b--){
		for(a=-n;a<=n;a++){
			for(i=0;i<n;i++){
				if(check(abs(i*i+a*i+b))){
					if(i>max){
							max = i;
							A=a;
							B=b;
				}
				else
				break;	
				}
			}
		}
	}
	cout<<A<<" "<<B;	
	return 0;
}
