/*
algorithm to get shortest paths from source to all the nodes
works for negative edges too.

Conditions:
  a) graph must be DIRECTED graph
  b) graph can have -ve edges, but must not have negative cycle
if the graph is undirected, convert it to directed by
adding two directed edges between two vertices with same weight at opposite direction


Approach:
1. order of edges doesnt matter
2. Relax all the edges N-1 times sequentially
Do the following, n-1 times, where n is number of vertices
  for all edges do: (if u-(wt)->v is an edge)
    if (dist[u] + wt < dist[v]) dist[v] = dist[u] + wt;


How to detect -ve cycle?
follow the approach.
If there is any further dist[i] reducing on the nth iteration
=>. then -ve cycle exists.

TC - O(E.V)
*/

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    // Code here
    int INF = 1e8;
    vector<int>dist(V,INF);
    dist[S] = 0;

    for (int i = 1; i <= V-1; ++ i) {
        for (auto & edge: edges) {
            int from = edge[0];
            int to = edge[1];
            int wt = edge[2];
            if (dist[from] != INF and dist[from] + wt < dist[to]) {
                dist[to] = dist[from] + wt;
            }
        }
    }

    for (auto & edge: edges) {
        int from = edge[0];
        int to = edge[1];
        int wt = edge[2];
        if (dist[from] != INF and dist[from] + wt < dist[to]) {
            return {-1};
        }
    }
    return dist;
}
