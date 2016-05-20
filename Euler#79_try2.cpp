#include<bits/stdc++.h>
using namespace std;

typedef vector<char> A;

A chars;

int idx(char x){
	for(int i=0;i<chars.size();i++){
		if(x==chars[i])
			return i;
	}	
    return -1;
}

bool search(char x, A &chars){
	for(int i=0;i<chars.size();i++){
		if(x==chars[i])
		return true;
	}
	return false;
}

class Graph{
	int v;
	list<char> *adj;
	public:
		bool flag;
		Graph(int v){
			this->v=v;
			adj = new list<char>[v];
		}
		
		void addedge(int a, char b){
			adj[a].push_back(b);
		}
		
		void lexitoposrtutil(int x, bool *visited, A &final){
		//	cout<<"In lexitoposrt UTIL"<<chars[x]<<endl;
			visited[x]=true;
			list<char>::iterator i;
			for(i=adj[x].begin();i!=adj[x].end();advance(i,1)){
				if(!visited[idx(*i)]){
					lexitoposrtutil(idx(*i),visited,final);
				}else{
					if(!search(*i,final)){
						flag=false; //cycle detected
					}
				}
			}
			
				int max=-1;
				for(i=adj[x].begin();i!=adj[x].end();advance(i,1)){
					for(int j=0;j<final.size();j++){
						if(*i==final[j]&& j>max){
							max = j;
						}
					}
				}
			for(max=max+1;max<final.size();max++){
				if(chars[x]<final[max])
				break;
			}
			final.insert(final.begin()+max,chars[x]);
		}
            
        void lexitoposrt(){
        	//cout<<"in lexitoposrt"<<endl;
			bool *visited = new bool[v];
			A final;
			
			flag= true;
			
			for(int i=0;i<v;i++){
				visited[i]=false;
			} 
			for(int i=0;i<v;i++){
				if(!visited[i])
					lexitoposrtutil(i,visited,final);
			}
			if(flag){
				for(int i=0;i<final.size();i++){
				cout<<final[i];
			}
		}
			else{
				cout<<"SMTH WRONG";
			}
		
			
		}
		
};



int main(){
	int t;
	cin>>t;
	
	vector<A>attempts(t,A(3));
	
	for(int i=0;i<t;i++){
		for(int j=0;j<3;j++){
			cin>>attempts[i][j];
		}
	}
	
	
	for(int i=0;i<t;i++){
		for(int j=0;j<3;j++){
			if(!search(attempts[i][j],chars))
				chars.push_back(attempts[i][j]);
		}
	}
	
	sort(chars.begin(),chars.end());
	
	Graph g(chars.size());
	
	for(int i=0;i<chars.size();i++){
		A list;
		for(int j=0;j<t;j++){
			if(chars[i]==attempts[j][2]&& !search(attempts[j][1],list))
				list.push_back(attempts[j][1]);
			if(chars[i]==attempts[j][1]&& !search(attempts[j][0],list))
				list.push_back(attempts[j][0]);	
			}
			
		sort(list.begin(),list.end());
		for(int j=0;j<list.size();j++)
			//cout<<list[j]<<endl;
		for(int j=0;j<list.size();j++){
			//cout<<chars[i]<<"->"<<list[j]<<endl;
			g.addedge(i,list[j]);
		}
	}
	
	g.lexitoposrt();
	return 0;

}
