#include <iostream>
 
using namespace std;
 
class GraphAdjList
{
    int V;
    int *head;
    struct Edge
    {
        int v, next;
    } *edges;
    int edge_cnt;
 
public:
    GraphAdjList(int V)
    {
        this->V = V;
        head = new int[V];
        edges = new Edge[V * 2];
        edge_cnt = 0;
        for (int i = 0; i < V; i++)
            head[i] = -1;
    }
 
    void addEdge(int u, int v)
    {
        edges[edge_cnt].v = v;
        edges[edge_cnt].next = head[u];
        head[u] = edge_cnt++;
    }
 
    void printGraph()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << " ---> ";
            for (int j = head[i]; j != -1; j = edges[j].next)
                cout << edges[j].v << " ";
            cout << endl;
        }
    }
};
 

class GraphAdjMatrix
{
    int V;
    int **adj;
 
public:
    GraphAdjMatrix(int V)
    {
        this->V = V;
        adj = new int *[V];
        for (int i = 0; i < V; i++)
        {
            adj[i] = new int[V];
            for (int j = 0; j < V; j++)
                adj[i][j] = 0;
        }
    }
 
    void addEdge(int u, int v)
    {
        adj[u][v] = 1;
    }
 
    void printGraph()
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
                cout << adj[i][j] << " ";
            cout << endl;
        }
    }
};
 
int main()
{
    GraphAdjList g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(0, 4);
    g1.addEdge(1, 2);
    g1.addEdge(1, 3);
    g1.addEdge(1, 4);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
    cout << "Graph representation using adjacency list:\n";
    g1.printGraph();
 
    GraphAdjMatrix g2(5);
    g2.addEdge(0, 1);
    g2.addEdge(0, 4);
    g2.addEdge(1, 2);
    g2.addEdge(1, 3);
    g2.addEdge(1, 4);
    g2.addEdge(2, 3);
    g2.addEdge(3, 4);
    cout << "Graph representation using adjacency matrix:\n";
    g2.printGraph();
    return 0 ; 
}

