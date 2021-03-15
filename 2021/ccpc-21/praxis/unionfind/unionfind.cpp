/* 
* Adjacency List Graph
* Modified from: https://www.geeksforgeeks.org/graph-and-its-representations/ & from hash table
*/ 
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
// remove if necessary
// #pragma once
using namespace std;

class Graph_l {
    protected:
        bool directed;
        // hash table list
        std::vector<int> *adj;
        int size;
        bool flag = false;
    public:
        // contructor, first arg directed or undirected, next is the number of vertices
        Graph_l(bool, int);
        // overloads main contructor, default undirected, arg is the number of vertices
        Graph_l(int);
        // destructor
        ~Graph_l();

        // add edge
        void add_edge(int source, int destination);
        // TODO: add list of pairs?
        // void add_edges(std::pairs);
        void delete_edge(int source, int destination);

        // gets size of graph (ie number of vertices)
        int get_size();
        // print
        void print();
        // print all edges to a vertix
        void print_edges(int);
};

Graph_l::Graph_l(int v) {
    directed = true;
    size = v;
    adj = new std::vector<int>[v];
}
Graph_l::Graph_l(bool dir, int v) {
    directed = dir;
    size = v;
    adj = new std::vector<int>[v];
}
Graph_l::~Graph_l() {
    delete[] adj;
}

void Graph_l::add_edge(int source, int destination) {
    adj[source].push_back(destination);
    // if undirected, also do the reverse
    if (!directed) adj[destination].push_back(source);
}

void Graph_l::delete_edge(int source, int destination) {
    // iterate through table by rows
    std::vector<int> :: iterator i;
    for (i = adj[source].begin(); i != adj[source].end(); i++) {
        if (*i == destination) break;
    }

    if (i != adj[source].end()) adj[source].erase(i);
    // if undirected, do the reverse
    if (!directed && !flag) {
        flag = !flag;
        delete_edge(destination, source);
        flag = !flag;
    }
}

void Graph_l::print() {
    for (int i = 0; i<size; i++) {
        std::cout << i;
        for (auto item: adj[i]) {
            std::cout << " -> " << item;
        }
        std::cout << std::endl;
    }
}
void Graph_l::print_edges(int edge) {
    std::cout << edge;
    for (auto item: adj[edge]) {
        std::cout << " -> " << item;
    }
    std::cout << std::endl;
}
int Graph_l::get_size() {
    return size;
}

class Graph_bfs: public Graph_l {
    protected:
        bool helper_bfs(int, int, std::vector<int>&, std::vector<int>&);
    public:
        // inheritance
        Graph_bfs(bool a, int b): Graph_l(a, b){};
        Graph_bfs(int b): Graph_l(b){};
        // BFS, given starting node, returns vector of ints
        std::vector<int> bfs(int);
        // stores bfs order in second arg, a vector of int, no returns
        void bfs(int, std::vector<int>&);
        // returns shortest length path given start and end node
        int bfs(int, int);
        // returns shortest path length and stores the path in an 
        // vector given by the third arg in the order of source node to end node 
        int bfs_path(int, int, std::vector<int>&);
        // returns the shortest path as a vector
        std::vector<int> bfs_path(int, int);
};

void Graph_bfs::bfs(int start, std::vector<int>&path) {
    std::vector<bool> visited(size);
    std::fill_n(visited.begin(), size, false);
    // might as well use vectors
    // bool *visited = new bool[size];
    // // zeros bool array
    // memset(visited, 0, sizeof(bool) * (size));

    std::queue<int> list;

    // starting node
    visited[start] = true;
    list.push(start);

    // while queue is not empty
    while (!list.empty()) {
        // sets new node as first in queue
        start = list.front();
        // prints order
        path.push_back(start);
        // dequeues
        list.pop();

        // gets all adjacent vertices
        for (std::vector<int>::iterator i = adj[start].begin(); i != adj[start].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                list.push(*i);
            }
        }
    }
}

std::vector<int> Graph_bfs::bfs(int start) {
    std::vector<int> path;
    bfs(start, path);
    return path;
}

int Graph_bfs::bfs(int start, int end) {
    std::vector<int> path;
    return bfs_path(start, end, path);
}

int Graph_bfs::bfs_path(int start, int end, std::vector<int> &path) {
    std::vector<int> dist(size);
    std::vector<int> pred(size);
    // zeros bool and int array
    fill_n(dist.begin(), size, INT_MAX);
    fill_n(pred.begin(), size, -1);

    if (!helper_bfs(start, end, pred, dist)) {
        // not connected, return max int
        return INT_MAX;
    }

    // debugs
    // for(int i=0; i<pred.size(); ++i) std::cout << pred[i] << ' ';
    // std::cout << '\n';
    // for(int i=0; i<dist.size(); ++i) std::cout << dist[i] << ' ';

    int trace = end;
    path.push_back(trace);
    while (pred[trace] != -1) {
        path.push_back(pred[trace]);
        trace = pred[trace];
    }
    // reverse order of path
    std::reverse(path.begin(), path.end());
    return dist[end];
}

bool Graph_bfs::helper_bfs(int start, int end, std::vector<int> &pred, std::vector<int> &dist) {
    std::vector<bool> visited(size);
    // zeros bool array
    fill_n(visited.begin(), size, false);

    // starting node
    std::queue<int> list;
    visited[start] = true;
    dist[start] = 0;
    list.push(start);

    // while queue is not empty
    while (!list.empty()) {
        // sets new node as first in queue
        int u = list.front();
        // dequeues
        list.pop();

        // gets all adjacent vertices
        for (int i = 0; i < adj[u].size(); i++) {
            // if not visited
            int current = adj[u][i];
            if (!visited[current]) {
                visited[current] = true;
                dist[current] = dist[u]+1;
                pred[current] = u;
                list.push(current);

                if (current == end) {
                    return true;
                }
            }
        }
    }

    return false;
}



int main() {
    int n, q;
    cin >> n >> q;

    Graph_bfs list_g(false, n);

    for (int i = 0; i < q; ++i) {
        char x;
        int a, b;
        cin >> x >> a >> b;

        if (x == '?') {
            vector<int> in;
            list_g.bfs_path(a,b,in);
            // base case
            if (find(in.begin(), in.end(), b) != in.end()) {
                cout << "yes\n";
            } else {
                if (a == b) {
                    cout << "yes\n";
                } else {
                    cout << "no\n";

                }
            }
        } else {
            list_g.add_edge(a, b);
        }
    }
    return 0;
}
