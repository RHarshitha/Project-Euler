#include<bits/stdc++.h>
#include<math.h>

using namespace std;

int main(){

	int n,val=1,sum=0;
	int i,sr,er,sc,ec;
	cin>>n;
	sr=er=sc=ec=n/2;
	int A[n][n];

	while(val<=n*n){

	for(i=sc;i<=ec;i++){
		A[sr][i]=val;
		if(sr==i||sr==n-i-1)
			sum+=val;
		val+=1;
		if(val>n*n)
		break;
	}
	ec++;

	
	if(val>n*n)
	break;

	for(i=sr;i<=er;i++){
		A[i][ec]=val;
		if(ec==i||ec==n-i-1)
			sum+=val;
		val+=1;
	}
	er++;

	for(i=ec;i>=sc;i--){
		A[er][i]=val;
		if(er==i||er==n-i-1)
			sum+=val;
		val+=1;
	}
	sc--;

	for(i=er;i>=sr;i--){
		A[i][sc]=val;
		if(sc==i||sc==n-i-1)
			sum+=val;
		val+=1;
	}
	sr--;

	}

	for(i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<A[i][j]<<"\t";
		}
		
		cout<<endl;
	}

	cout<<sum;
	return 0;
}
