#include<iostream>
#include<list>
#include<iterator>
using namespace std;

void displayAdjacentList(list<int> adjacency_list[], int y)
{
    for(int i = 0; i < y; i++) 
    {
        cout << i << "->";
        list<int> :: iterator it;
        for(it = adjacency_list[i].begin(); it != adjacency_list[i].end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
}
void add_edge(list<int> adjacency_list[], int x, int y)  //add y into the list x, and x into list y
{
    adjacency_list[x].push_back(y);
    adjacency_list[y].push_back(x);
}

int main()
{
    int y = 5; //there are 6 vertices in the graph
    //create an array of lists whose size is 6
    list<int> adjacency_list[y];
    add_edge(adjacency_list, 0, 1);
    add_edge(adjacency_list, 0, 4);
    add_edge(adjacency_list, 1, 4);
    add_edge(adjacency_list, 1, 3);
    add_edge(adjacency_list, 1, 2);
    add_edge(adjacency_list, 2, 3);
    add_edge(adjacency_list, 3, 4);
    displayAdjacentList(adjacency_list, y);
}
