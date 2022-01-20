// BFS algorithm in C++
#include <bits/stdc++.h>
#include <iostream>
#include <list>
#include <fstream>
#include <vector>

using namespace std;

class Graph {
  int numVertices;
  int v,e;
  list<int> *adjl;  
  bool* visited;
  int** adj;
   public:
  Graph(int v);
  Graph(int v, int e);
  void addEdge(int src, int dest);
  void addEdgeM(int start, int e);
  void BFS(int startVertex);
  void DFS(int start, vector<bool>& visited);
};

// Create a graph with given vertices,
// and maintain an adjacency list
Graph::Graph(int v)
{
    this->v = v;
    adjl = new list<int>[v];
}

Graph::Graph(int v, int e)
{
    this->v = v;
    this->e = e;
    adj = new int*[v];
    for (int row = 0; row < v; row++) {
        adj[row] = new int[v];
        for (int column = 0; column < v; column++) {
            adj[row][column] = 0;
        }
    }
}

// Add edges to the graph
void Graph::addEdge(int v, int w)
{
    adjl[v].push_back(w); // Add w to v’s list.
}

void Graph::addEdgeM(int start, int e)
{
  
    // Considering a bidirectional edge
    adj[start][e] = 1;
    adj[e][start] = 1;
}

void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[v];
    for(int i = 0; i < v; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;
 
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = adjl[s].begin(); i != adjl[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

void Graph::DFS(int start, vector<bool>& visited)
{
  
    // Print the current node
    cout << start << " ";
  
    // Set current node as visited
    visited[start] = true;
  
    // For every node of the graph
    for (int i = 0; i < v; i++) {
  
        // If some node is adjacent to the current node
        // and it has not already been visited
        if (adj[start][i] == 1 && (!visited[i])) {
            DFS(i, visited);
        }
    }
}

int main() {
  ifstream in("in2.txt");
  int e,v,max;
  string s;
  in>>e>>max;
  getline(in,s);
  Graph g(max);
  Graph gM(max,e);
  for(int i = 0;i <= max;i++){
    in>>e>>v;
    getline(in,s);
    g.addEdge(e,v);
    gM.addEdgeM(e,v);
    }
  vector<bool> visited(v, false);
  cout << "BFS:" << endl;
  g.BFS(1);
  cout << endl << "DFS:" << endl;
  gM.DFS(1,visited);
  return 0;
}