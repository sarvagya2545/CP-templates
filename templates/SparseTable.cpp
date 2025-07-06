#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SparseTable {
    using F = function<T(T, T)>;
    vector<vector<T>> sparse_table;
    F get;
public:
    SparseTable(vector<T> &v, F get) {
        int n = v.size();
        int RMAX = __lg(n);
        this->get = get;
        sparse_table = vector<vector<T>> (n, vector<int> (RMAX + 1));
        for(int i = 0; i < n; i++) sparse_table[i][0] = v[i];

        for(int i = n - 1; i >= 0; i--) {
            for(int j = 1; j <= RMAX and i + (1 << j) - 1 < n; j++) {
                sparse_table[i][j] = get(
                    sparse_table[i][j - 1], 
                    sparse_table[i + (1 << (j - 1))][j - 1]
                );
            }
        }
    }

    T query(int l, int r) {
        int len = __lg(r - l + 1);
        return get(sparse_table[l][len], sparse_table[r - (1 << len) + 1][len]);
    }
};

