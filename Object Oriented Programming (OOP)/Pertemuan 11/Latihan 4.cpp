#include <iostream>
#include <iterator>
#include <list>
using namespace std;

class Vertex {
    protected:
        list<int> adj;
    
    public:
        void newEdge(int x, int y) {
            if(adj.empty()) adj.push_back(x);
            adj.push_back(y);
        }

        void printList(){

            list<int>::iterator i;

            for(i = adj.begin(); i != adj.end(); ++i)
                cout << *i << " ";
    
            cout << "\n";
        }
};

class Graph {
    protected:
        int len;
        Vertex vertex[100];
        
    public:
        Graph(int _len) {
            len = _len;
        }

        int AddNewEdgetoVertex(int x, int y) {
            vertex[x].newEdge(x,y);
            vertex[y].newEdge(y,x);
        }

        int printAllVertex() {
            for (int i = 0; i < len; i++)
                vertex[i].printList();
            
        }
};


int main()
{
    Graph graph_1(5);

    graph_1.AddNewEdgetoVertex( 0, 1);
    graph_1.AddNewEdgetoVertex( 0, 4);
    graph_1.AddNewEdgetoVertex( 1, 2);
    graph_1.AddNewEdgetoVertex( 1, 3);
    graph_1.AddNewEdgetoVertex( 1, 4);
    graph_1.AddNewEdgetoVertex( 2, 3);
    graph_1.AddNewEdgetoVertex( 3, 4);

    graph_1.printAllVertex();
}