/* AUTHOR:- RAJAT SHAHI */
/* THERE IS NO TALENT HERE... THIS IS HARD WORK... */

#include<bits/stdc++.h>
using namespace std;
// generic graph implementation using adjaceny map (space-optimized)

template<typename T>
class Graph
{
public:
    int V;  // number of vertices
    unordered_map<T, vector<T>> adj; // adjacency list

    // constructor for graph
    Graph(int n)
    {
        // default constructor for unordered_map
        // because we dont have to take the number of edges
    }

    // adding edge between two vertices
    void add_edge(T source, T dest, bool bidir = true)
    {
        adj[source].push_back(dest);
        if(bidir == true) // if bidirectional graph
        {
            adj[dest].push_back(source);
        }
    }

    // printing the general graph
    // i will use this only if i have to see the adjacent
    // vertex of every vertex in the graph
    void print_graph()
    {
        // go to every vertex of graph and print its details

        for(const auto row : this->adj)
        {
            cout << row.first << "---> ";

            for(const auto element : row.second)
            {
                cout << element << " ";
            }
            cout << endl;
        }
    }
};


int main(int argc, char const *argv[])
{
    int vertices;
    cout << "enter the number of cities" << endl;
    cin >> vertices;
    Graph<string> g(vertices);

    int edges;
    cout << "enter the number of edges" << endl;
    cin >> edges;

    for(int i = 0; i < edges; i++)
    {
        string s, d;
        cin >> s >> d;
        bool flag;
        cin >> flag;
        g.add_edge(s, d, flag);
    }

    g.print_graph();
    return 0;
}
