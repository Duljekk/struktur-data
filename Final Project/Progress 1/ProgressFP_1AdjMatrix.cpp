/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;
 
vector<vector<int>> adj;
 
 
// Fungsi untuk menambahkan Edge ke Graph
// Set value menjadi 1 karena di Adjacency Matrix 0 berarti tidak ada Edge dan 1 berarti ada Edge
void addEdge(int x,int y)
{
    adj[x][y] = 1;
    adj[y][x] = 1;
}
 
// Fungsi untuk melakukan Breadth First Search
void BFS(int start)
{
    // Menambahkan bool visited agar vertex yang sudah dikunjungi tidak dikunjungi lagi
    // Nilai awal false karena belum ada vertex yang dikunjungi diawal
    vector<bool> visited(adj.size(), false);
    vector<int> queue;
    queue.push_back(start);
  
    // Tandai vertex awal (start) sudah dikunjungi
    visited[start] = true;
  
    int vis;
    while (!queue.empty()) { // Cek jika queue tidak kosong maka lakukan loop untuk BFS
        vis = queue[0];
  
        // Print vertex yang sedang dikunjungi
        cout << vis << " ";
        queue.erase(queue.begin()); // Hapus vertex yang dikunjungi dari queue
  
        // Loop untuk setiap tetangga (adjacent) yang ada pada vertex tersebut
        for (int i = 0; i < adj[vis].size(); i++) {
            if (adj[vis][i] == 1 && (!visited[i])) {
  
                // Push vertex tetangga ke queue
                queue.push_back(i);
  
                // Tandai vertex sudah dikunjungi
                visited[i] = true;
            }
        }
    }
}
  
int main()
{
    // V = jumlah vertex
    int v = 21;
    int start;
 
 
    // Adjacency Matrix
    adj = vector<vector<int>>(v,vector<int>(v,0));
    
    addEdge(0, 1);
    addEdge(1, 0);
    addEdge(0, 2);
    addEdge(2, 0);
    addEdge(1, 3);
    addEdge(3, 1);
    addEdge(1, 5);
    addEdge(5, 1);
    addEdge(2, 4);
    addEdge(4, 2);
    addEdge(3, 9);
    addEdge(9, 3);
    addEdge(3, 13);
    addEdge(13, 3);
    addEdge(5, 7);
    addEdge(7, 5);
    addEdge(4, 6);
    addEdge(6, 4);
    addEdge(4, 8);
    addEdge(8, 4);
    addEdge(4, 14);
    addEdge(14, 4);
    addEdge(7, 11);
    addEdge(11, 7);
    addEdge(9, 11);
    addEdge(11, 9);
    addEdge(9, 15);
    addEdge(15, 9);
    addEdge(6, 10);
    addEdge(10, 6);
    addEdge(8, 12);
    addEdge(12, 8);
    addEdge(15, 20);
    addEdge(20, 15);
    addEdge(17, 13);
    addEdge(13, 17);
    addEdge(14, 16);
    addEdge(16, 14);
    addEdge(14, 18);
    addEdge(18, 14);
    addEdge(17, 19);
    addEdge(19, 17);
    addEdge(16, 18);
    addEdge(18, 16);
    addEdge(19, 20);
    addEdge(20, 19);

    cout << "Enter Starting Vertex: V";
    cin >> start;

	cout << "Following is Breadth First Traversal " << "(starting from V" << start << ") \n";
   
    BFS(start, end);
    return 0;
}
