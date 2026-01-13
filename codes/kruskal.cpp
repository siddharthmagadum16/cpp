#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct unionfind {
    vector<int> p;
    unionfind(int N) {
        p = vector<int>(N, -1);
    }
    int root(int x) {
        if (p[x] < 0) {
            return x;
        } else {
            p[x] = root(p[x]);
            return p[x];
        }
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x != y) {
            if (p[x] < p[y]) {
                swap(x, y);
            }
            p[y] += p[x];
            p[x] = y;
        }
    }
};

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int main() {
    int N = 4; // Number of vertices
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    // Step 1: Sort edges by weight
    sort(edges.begin(), edges.end());

    unionfind dsu(N);
    vector<Edge> mst;
    int mst_weight = 0;

    // Step 2: Iterate through sorted edges
    for (const auto& e : edges) {
        if (!dsu.same(e.u, e.v)) {
            dsu.unite(e.u, e.v);
            mst.push_back(e);
            mst_weight += e.weight;
        }
    }

    // Output results
    cout << "Edges in MST:" << endl;
    for (const auto& e : mst) {
        cout << e.u << " - " << e.v << " : " << e.weight << endl;
    }
    cout << "Total MST Weight: " << mst_weight << endl;

    return 0;
}