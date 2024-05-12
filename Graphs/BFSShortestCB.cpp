# include <iostream>

using namespace std;



class Graph{
	
	

	
}




int main(){
	int T;
	cin>>T;
	
	while(T--){
		Graph g = Graph();
		int V, E;
		cin>>V>>E;
		int u,v;
		for(int i=0; i<E; i++){
			cin>>u>>v;
			g.addEdge(u, v);
		}
		int s;
		cin>>s;
		g.bfsSSP(s);
	}


	return 0;
}