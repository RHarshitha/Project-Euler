#include<bits/stdc++.h>
using namespace std;

typedef vector<char> A;

A chars;


bool compare(int i,int j) {
 return (i>j);
}

int idx(char x){
	for(int i=0;i<chars.size();i++){
		if(x==chars[i])
		return i;
	}
	return -1;
}

bool search(char x, A &at){
	for(int i=0;i<at.size();i++){
		if(x==at[i])
		return true;
	}
	return false;
}

class Graph{
	int v;
	list<char> *adj; 
	public:
		Graph(int v){
			this->v= v;
			adj = new list<char>[v];
		}
		
		void addedge(int a, char b){
			adj[a].push_back(b);
		}
		
		bool checkcycleUtil(int x,bool visited[]){
			
		    if(visited[x] == false)
		    {
		        visited[x] = true;
		 
		        list<char>::iterator i;
		        for( i = adj[x].begin(); i != adj[x].end(); advance(i,1))
		        {
		            if ( !visited[idx(*i)] && checkcycleUtil(idx(*i), visited) )
		                return true;
		            else if (visited[idx(*i)])
		                return true;
		        }
		 
		    }
		    visited[x] = false; 
		    return false;
		}
		
		bool checkcycle(){

			//cout<<"In checkcycle"<<endl;
						
			bool *visited = new bool[v];
		    
		    for(int i = 0; i < v; i++){
			    visited[i] = false;
		    }
	
		    for(int i = 0; i < v; i++)
		        if (checkcycleUtil(i, visited))
		            return true;
						 
		    return false;
		}
		
				
		void topologicalsrtUtil(int x,bool visited[], vector<char> &Stack){

		    visited[x] = true;
		 
		    list<char>::iterator i;
		    for (i = adj[x].begin(); i != adj[x].end(); advance(i,1))
		        if (!visited[idx(*i)])
		            topologicalsrtUtil(idx(*i), visited, Stack);

		    Stack.push_back(chars[x]);
		}
		
		
		void topologicalsrt(){
			
			//cout<<"In topological srt"<<endl;

			vector<char> Stack;
 		    bool *visited = new bool[v];
 		    
		    for (int i = 0; i < v; i++)
		        visited[i] = false;

		    for (int i = 0; i < v; i++)
		      if (visited[i] == false)
		        topologicalsrtUtil(i, visited, Stack);

			for(int i=0;i<Stack.size();i++)
			cout<<Stack[i];
		}

};

int main(){
	int t;
	cin>>t;
	vector <A> attempts(t,A(3));
	for(int i=0;i<t;i++){
		for(int j=0;j<3;j++){
			cin>>attempts[i][j];
		}
	}
	
		for(int i=0;i<t;i++){
		for(int j=0;j<3;j++){
			if(!search(attempts[i][j],chars)){
				chars.push_back(attempts[i][j]);
			}			
		}
	}
	
	sort(chars.begin(),chars.end()); 

	Graph g(chars.size());
		
		for(int i=0;i<chars.size();i++){
			
			
			A list;
			
			for(int j=0;j<t;j++){
				if(chars[i]==attempts[j][1])
					list.push_back(attempts[j][0]);
				if(chars[i]==attempts[j][2])
					list.push_back(attempts[j][1]);
		}
			
			sort(list.begin(),list.end());
			
			for(int j=0;j<list.size();j++){
				//cout<<"adding edge"<<chars[i]<<"->"<<list[j];
				g.addedge(i,list[j]);
				
			}
		}
		
		if(g.checkcycle()){
			cout<<"SMTH WRONG"<<endl;
		}
		else{
			g.topologicalsrt();
		}
	
	return 0;
}
