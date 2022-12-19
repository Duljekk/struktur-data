#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// iPair ==> Integer Pair
typedef pair<int, int> iPair;

// This class represents a directed graph using
// adjacency list representation
class Graph {
	int V; // No. of vertices

	list<pair<int, int> >* adj;

public:
	Graph(int V); // Constructor

	void addEdge(int u, int v, int w);
	void djikstraAlgorithm(int s);
};

// Allocates memory for adjacency list
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

// Prints shortest paths from source to all other vertices
void Graph::djikstraAlgorithm(int source)
{
	priority_queue<iPair, vector<iPair>, greater<iPair> >
		pQueue;
	pQueue.push(make_pair(0, source));
	int distance[V];
		for(int i = 0; i<=V; i++)
		    distance[i] = 1000;
		distance[source] = 0;
	distance[source] = 0;

	while (!pQueue.empty()) {
		int u = pQueue.top().second;
		pQueue.pop();

		list<pair<int, int> >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i) {
			int v = (*i).first;
			int weight = (*i).second;

			if (distance[v] > distance[u] + weight) {
				distance[v] = distance[u] + weight;
				pQueue.push(make_pair(distance[v], v));
			}
		}
	}

	// Print shortest distances stored in distance[]
	cout << "Vertex Distance from Source" << endl;
	cout << "Source | Distance" << endl;
	for (int i = 0; i < V; ++i)
    cout << i << " | " << distance[i] << endl;
}

int main()
{
	// create the graph given in above figure
	int V = 21;
	int source;
	Graph g(V);

	// making above shown graph
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
