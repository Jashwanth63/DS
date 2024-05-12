#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
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


class ssp{
	private: 
		Graph g;
		int V;
		list<int> *adjList;
		queue<int> vertices;
		vector<int> depth;
	public: 
		ssp(Graph g, int totalVertices) : g(g), V(totalVertices), adjList(g.getList()), depth(V, -1){
			
		}

		int doBfsforSSP(int srcNode, int destNode){ //Returns shortest path dist from source to dest, Assume Source and Dest both exist
			vertices.push(srcNode);
			depth[srcNode] = 0;
			while(!vertices.empty()){
				int first = vertices.front();
				vertices.pop();
				
				for(auto nbr: adjList[first]){
					if(depth[nbr]==-1){
						vertices.push(nbr);
						depth[nbr] = depth[first] + 1;
						cout<<"Node: "<<nbr<<" at Depth "<<depth[nbr]<<" from Source" <<endl;
					}
				}
				
			}
		return depth[destNode];
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

	ssp traverse(g, 6);
	cout<<endl<<traverse.doBfsforSSP(1, 5);

	return 0;
}  