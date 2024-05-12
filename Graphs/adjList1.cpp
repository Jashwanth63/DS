#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

/**
 
	This implementation using Lists to store edges. Output 1: 2, 3 means the vertex 1 is connected to 2 and 3. 
	Note: addEdge(x, y) assumes the graph is bidirectional. 

 **/


class Graph{
		int V;

		list<int> *edges;
	public:
		Graph(int V){
			this->V = V;
			edges = new list<int>[V]; 
		}

		void addEdge(int x, int y){ //Assume Graph is Bi-directional
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


};

int main(){

	Graph g = Graph(3);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	
	g.showList();



	return 0;
}