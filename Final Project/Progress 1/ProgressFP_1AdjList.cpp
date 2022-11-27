/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

// Class untuk Graph dengan Adjacency List
class Graph
{
	int V; // Jumlah vertex

    // Pointer untuk array yang mengandung Adjacency List
	vector<list<int>> adj;
public:
	Graph(int V); // Konstruktor graph dengan V sebagai jumlah Vertex

	void addEdge(int v, int w); // Fungsi untuk menambahkan Edge ke Graph

	void BFS(int s, int x); // Fungsi untuk melakukan Breadth First Search

};

Graph::Graph(int V)
{
	this->V = V;
	adj.resize(V);
}

// Fungsi untuk menambahkan Edge pada Graph
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); 
}

void Graph::BFS(int s, int x)
{
    // Menambahkan bool visited agar vertex yang sudah dikunjungi tidak dikunjungi lagi
    // Nilai awal false karena belum ada vertex yang dikunjungi diawal
	vector<bool> visited;
	visited.resize(V,false);

    // Membuat queue untuk BFS
	list<int> queue;

    // Tandai vertex sudah dikunjungi dan masukkan ke queue
	visited[s] = true;
	queue.push_back(s);

    // Tandai vertex akhir sudah dikunjungi
    // visited[x] = true;

	while(!queue.empty()) // Cek jika queue tidak kosong maka lakukan loop untuk BFS
	{
		s = queue.front(); // Lakukan dequeue untuk vertex paling awal yang ada di queue
		cout << "(V" << s << ")" << endl; // Print vertex tersebut
		queue.pop_front(); // Lakukan pop untuk menghilangkan vertex tersebut

		for (auto adjecent: adj[s])
		{
			if (!visited[adjecent] && s != x) // Cek apakah vertex tetangga (adjacent) sudah dikunjungi atau belum & cek apakah vertex tersebut merupakan ending vertex atau bukan
			{
                // Jika belum, tandai vertex sudah dikunjungi dan masukkan ke queue
				visited[adjecent] = true; 
				queue.push_back(adjecent);
			}
		}
	}
}

int main()
{
    int start, end;

	Graph g(21);
	g.addEdge(0, 1);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(3, 1);
    g.addEdge(1, 5);
    g.addEdge(5, 1);
    g.addEdge(2, 4);
    g.addEdge(4, 2);
    g.addEdge(3, 9);
    g.addEdge(9, 3);
    g.addEdge(3, 13);
    g.addEdge(13, 3);
    g.addEdge(5, 7);
    g.addEdge(7, 5);
    g.addEdge(4, 6);
    g.addEdge(6, 4);
    g.addEdge(4, 8);
    g.addEdge(8, 4);
    g.addEdge(4, 14);
    g.addEdge(14, 4);
    g.addEdge(7, 11);
    g.addEdge(11, 7);
    g.addEdge(9, 11);
    g.addEdge(11, 9);
    g.addEdge(9, 15);
    g.addEdge(15, 9);
    g.addEdge(6, 10);
    g.addEdge(10, 6);
    g.addEdge(8, 12);
    g.addEdge(12, 8);
    g.addEdge(15, 20);
    g.addEdge(20, 15);
    g.addEdge(17, 13);
    g.addEdge(13, 17);
    g.addEdge(14, 16);
    g.addEdge(16, 14);
    g.addEdge(14, 18);
    g.addEdge(18, 14);
    g.addEdge(17, 19);
    g.addEdge(19, 17);
    g.addEdge(16, 18);
    g.addEdge(18, 16);
    g.addEdge(19, 20);
    g.addEdge(20, 19);

    cout << "Enter Starting Vertex: V";
    cin >> start;

    cout << "Enter Ending Vertex: V";
    cin >> end;

    if (end < 0) // Jika vertex akhir kurang atau sama dengan 0 set nilai end menjadi NULL
        int *end = NULL;

	cout << "Following is Breadth First Traversal " << "(starting from V" << start << ") \n";
	g.BFS(start, end);

	return 0;
}
