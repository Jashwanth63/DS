#include <iostream>
#include <vector>
#include <list>


using namespace std;

class Graph{
		int V;
		list<int> *edges;
		
	public:
		Graph(int V){
			this->V = V;
			edges = new list<int>[V]; 
		}

		void makeEdge(int x, int y){ //Assume Graph is Bi-directional
			edges[x].push_back(y);
			edges[y].push_back(x);
		} 

		void showList(){
			for(int i=0; i<this->V; i++){
				cout<<i<<":"<<" ";
				for(auto E: edges[i]){
					cout<<E<<" ";
				}
				cout<<endl;
			}
		}


		void doDFS(int source, vector<bool> &visited){
			cout<<source<<" ";
			visited[source] = true;
			for(auto x: edges[source]){
				if(!visited[x]){
					visited[x] = true;
					doDFS(x, visited);
				} 
			}
		}

		void dfs(int source){
			vector<bool> visited(this->V, false);
			doDFS(source, visited);
		}
};

int main(){
	Graph g = Graph(6);
	g.makeEdge(0, 1); 
	g.makeEdge(0, 3);
	g.makeEdge(1, 2); 
	g.makeEdge(2, 3); 
	g.makeEdge(3, 4);
	g.makeEdge(4 ,5);
	g.dfs(3);
	return 0;
}