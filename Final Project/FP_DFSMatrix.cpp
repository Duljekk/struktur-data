#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph {
    protected:
        int v;
        vector<vector<int>> adjMatrix;
        vector<int> DFSResult;
        int DFSWeight;

    public:
        Graph(int len) {
            v = len;
            vector<int> l (v+1, -1);
            adjMatrix.assign(v+1, l);
            DFSResult.assign(v+1, 0);
            vector<int> vec (v+1, 0);
        }
        void addEdge(int u, int v, int w);
        void DFS(int start, int end);
        void solveDFS(int start, int end, vector<int> path, vector<bool> visited, int currWeight);
};

        void Graph::addEdge(int u, int v, int w){
            adjMatrix[u][v] = w;
        }

        void Graph::DFS(int start, int end){
            cout << endl;
            cout << "Shortest Path" << endl;
            DFSWeight = INT_MAX;
            vector<int> path;
            vector<bool> visited (v+1, false);
            solveDFS(start, end, path, visited, 0 );
            
            for (int i = 0; i < DFSResult.size(); i++)
            {
                cout << DFSResult[i] << " ";
            }

            cout << endl << "Weight / Distance = " << DFSWeight << endl;
        }

        void Graph::solveDFS(int start, int end, vector<int> path, vector<bool> visited, int currWeight){
            if(start == end) {
                path.push_back(end);
                if(currWeight < DFSWeight ) {
                    DFSWeight = currWeight;
                    DFSResult = path;
                }
                cout << currWeight << " ";
                for (int i = 0; i < path.size(); i++)
                {
                    cout <<  path[i] << " ";
                }
                cout << endl;
            }
            visited[start] = true;
            path.push_back(start);
            for ( int it = 1; it <= v; it++)
            {
                if(!visited[it] && adjMatrix[start][it] != -1){
                    int wtemp = currWeight;
                    wtemp += adjMatrix[start][it];
                    solveDFS(it, end, path, visited, wtemp);
                }
            }
        };

int main(){
    int V = 21;
    int source, end;
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
    
    cout << "Enter Ending Vertex: V";
    cin >> end;

	// Function call
	g.DFS(source, end);

	return 0;
}