#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list<int> adjacent[21];
	public:
	Graph(int v){
	    V = v;
	}
    void addEdge(int u, int v);
    bool BFSPath(int source, int end, int pred[], int distance[]);
    void BFSDist(int source, int end);
};

	void Graph::addEdge(int u, int v){
	    adjacent[u].push_back(v);
	}

	bool Graph::BFSPath(int source, int end, int pred[], int distance[]){
	queue<int> q;
	bool visited[V] = {false};
	distance[21] = {0};
	pred[21] = {-1};
	visited[source] = true;
	distance[source] = 0;
	q.push(source);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto const &i: adjacent[u]){
			if(visited[i] == false){
				visited[i] = true;
				distance[i] = distance[u] + 1;
				pred[i] = u;
				cout << u << " " << i << endl;
				q.push(i);
				if(i == end) return true;
			}
		}
	}
	return false;
    }

    void Graph::BFSDist(int source, int end){
	int pred[V], distance[V];
	BFSPath(source, end, pred, distance);
	vector<int> path;
	int c = end;
	path.push_back(c);
	while(pred[c] != 0){
		path.push_back(pred[c]);
		c = pred[c];
	}
	cout << "Shortest Path is : " << endl; 
	for(int i = path.size() - 1; i >= 0; i--){
			cout << path[i] << " ";
		}
};

int main(){
	int source, end;

    Graph g(21);

	g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 5);
    g.addEdge(2, 4);
    g.addEdge(3, 9);
    g.addEdge(3, 13);
    g.addEdge(5, 7);
    g.addEdge(4, 6);
    g.addEdge(4, 8);
    g.addEdge(4, 14);
    g.addEdge(7, 11);
    g.addEdge(11, 9);
    g.addEdge(9, 15);
    g.addEdge(6, 10);
    g.addEdge(8, 12);
    g.addEdge(15, 20);
    g.addEdge(13, 17);
    g.addEdge(14, 16);
    g.addEdge(14, 18);
    g.addEdge(17, 19);
    g.addEdge(16, 18);
    g.addEdge(19, 20);

    cout << "Enter Starting Vertex: V";
    cin >> source;
    
    cout << "Enter Ending Vertex: V";
    cin >> end;

    cout << "Source | Path" << endl;
	g.BFSDist(source, end);

	return 0;
}