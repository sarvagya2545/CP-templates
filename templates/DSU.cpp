#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent = vector<int> (n);
        iota(parent.begin(), parent.end(), 0);
        rank = vector<int> (n, 1);
    }

    int root(int x) {
        if(x == parent[x]) return x;
        // return root(parent[x]);
        return parent[x] = root(parent[x]);
    }

    int join(int x, int y) {
        int u = root(x), v = root(y);
        if(u == v) return 0;

        if(rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        if(rank[u] == rank[v]) rank[v]++;
        return 1;
    }
};