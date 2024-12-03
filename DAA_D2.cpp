/*Implement program Count all possible Paths
between two Vertices.
Statement Count the total number of ways or paths
that exist between two vertices in a directed graph.
These paths don’t contain a cycle, the simple enough
reason is that a cycle contains an infinite number of
paths and hence they create a problem.
Input: Count paths between A and E
Output: Total paths between A and E are 4
Input: Count paths between A and C
Output: Total paths between A and C are 2
 */
#include <bits/stdc++.h>
using namespace std;
 
class Graph {
public:
    // Construct the graph given the number of vertices...
    Graph(int vertices);
    // Specify an edge between two vertices
    void add_edge(int src, int dst);

    int count_paths(int src, int dst, int vertices);
 
private:
    int m_vertices;
    list<int>* m_neighbours;
    void path_counter(int src, int dst, int& path_count,
                      vector<bool>& visited);
};
 
Graph::Graph(int vertices)
{
    m_vertices = vertices; // unused!!
    m_neighbours = new list<int>[vertices];
}
 
void Graph::add_edge(int src, int dst)
{
    m_neighbours[src].push_back(dst);
}
 
int Graph::count_paths(int src, int dst, int vertices)
{
    int path_count = 0;
    vector<bool> visited(vertices, false);
    path_counter(src, dst, path_count, visited);
    return path_count;
}
 

void Graph::path_counter(int src, int dst, int& path_count,
                         vector<bool>& visited)
{

    visited[src] = true;
    if (src == dst) {
        path_count++;
    }

    else {
        for (auto neighbour : m_neighbours[src]) {
            if (!visited[neighbour])
                path_counter(neighbour, dst, path_count,
                             visited);
        }
    }
    visited[src] = false;
}

int main()
{
    // Create a graph given in the above diagram - see link
    Graph g(5);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 4);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 3);
    g.add_edge(2, 1);
    g.add_edge(3, 2);
     
      // Function call
    cout << g.count_paths(0, 4, 5);
 
    return 0;
}
