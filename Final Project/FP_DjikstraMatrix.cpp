#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> iPair;

class Graph{
	int V;
	int adjMatrix[21][21] ={
          {0, 0},
          {0, 0}
    };
	public:
	Graph(int v){
	    V = v;
	}
    void addEdge(int u, int v, int w);
    void djikstraAlgorithm(int source);
};

	void Graph::addEdge(int u, int v, int w){
	    adjMatrix[u][v] = w;
	}

	void Graph::djikstraAlgorithm(int source){
    priority_queue<iPair, vector<iPair>, greater<iPair> >
        q;
		q.push(make_pair(0, source));
		int distance[V];
		for(int i = 0; i < V; i++){
		    distance[i] = 1000;
		}
		distance[source] = 0;

		while(!q.empty()){
			int u = q.top().second;
			q.pop();
			for(int i = 1; i < V; i++){
				int v = i;
				int w = adjMatrix[u][i];
				if(distance[v] > distance[u] + w && w != 0){
					distance[v] = distance[u] + w;
					q.push(make_pair(distance[v], v));
				}
			}
		}
		printf("Vertex Distance from Source\n");
    	for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, distance[i]);
	};


int main()
{
	int V = 21;
	int source;
	Graph g(V);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 5);
    g.addEdge(1, 5, 1);
    g.addEdge(2, 4, 3);
    g.addEdge(3, 9, 3);
    g.addEdge(3, 13, 6);
    g.addEdge(5, 7, 4);
    g.addEdge(4, 6, 1);
    g.addEdge(4, 8, 6);
    g.addEdge(4, 14, 7);
    g.addEdge(7, 11, 7);
    g.addEdge(11, 9, 5);
    g.addEdge(9, 15, 9);
    g.addEdge(6, 10, 1);
    g.addEdge(8, 12, 2);
    g.addEdge(15, 20, 8);
    g.addEdge(13, 17, 3);
    g.addEdge(14, 16, 4);
    g.addEdge(14, 18, 4);
    g.addEdge(17, 19, 5);
    g.addEdge(16, 18, 5);
    g.addEdge(19, 20, 2);

	cout << "Enter Starting Vertex: V";
    cin >> source;
	// Function call
	g.djikstraAlgorithm(source);

	return 0;
}
