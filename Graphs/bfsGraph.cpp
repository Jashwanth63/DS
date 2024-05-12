#include <iostream>
#include <queue>
#include <list>

using namespace std;


class Graph{
	private:
		int V; //Number of Vertices
		list<int> *edges;
	public:
		Graph(int V){
			this->V = V;
			edges = new list<int>[V];
		}

		void makeEdge(int x, int y){
			edges[x].push_back(y);
			edges[y].push_back(x);
		}

		void show(){
			for(int i=0; i<this->V; i++){
				cout<<i<<": ";
				for(int edge: edges[i]){
					cout<<edge<<" ";
				}
				cout<<endl;
			}
		}
		list<int>* getList(){
			return this->edges;
		}
};


class bfs{
	private: 
		Graph g;
		int V;
		list<int> *adjList;
		queue<int> vertices;
		vector<bool> visited;
	public: 
		bfs(Graph g, int totalVertices) : g(g), V(totalVertices), adjList(g.getList()), visited(V, false){
			
		}

		void doBfs(int srcNode){
			vertices.push(srcNode);
			visited[srcNode] = true;
			while(!vertices.empty()){
				int first = vertices.front();
				cout<<first<<"->";
				vertices.pop();
				
				for(auto nbr: adjList[first]){
					if(!visited[nbr]){
						vertices.push(nbr);
						visited[nbr] = true;
					}
				}
				
			}
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
	g.show();

	bfs traverse(g, 6);
	traverse.doBfs(0);

	return 0;
}