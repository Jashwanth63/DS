#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;


/**
 
	This implementation using map<key, value> where key = Vertex and Value is a List of edges. 
		
	Output 1: 2, 3 means the vertex 1 is connected to 2 and 3. 
	Note: addEdge(x, y) assumes the graph is bidirectional. 

 **/


class Graph{
	private:
		int V;
		unordered_map<int, list<int>> edges;

	public:
		Graph(int V) : V(V) {}

		// Assume Bi-Directionality

		void addEdge(int x, int y) { 
			edges[x].push_back(y);
			edges[y].push_back(x);
		}

		void showList(){
			for(auto e: edges){
				cout<<e.first<<": ";
				for(auto val : e.second){
					cout<<val <<" ";
				}
				cout<<endl;
			}
		}

};


int main(){
	Graph g = Graph(3);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.showList();
	return 0;
}