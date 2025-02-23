#include<bits/stdc++.h>
using namespace std;

template <typename T>
class SegmentTree {
private:
    // need to only define these values to use this implementation
    using F = function<T(T&, T&)>;
    int n;
    vector<T> seg_tree;
    T zero_val;
    F query_func;
    F update_func;

    void build(vector<T> &nums, int left, int right, int node = 0) {
        if(left > right) {
            return;
        }

        if(left == right) {
            seg_tree[node] = nums[left];
            return;
        }

        int mid = left + (right - left) / 2;

        build(nums, left, mid, 2 * node + 1);
        build(nums, mid + 1, right, 2 * node + 2);
        
        seg_tree[node] = query_func(seg_tree[2 * node + 1], seg_tree[2 * node + 2]);
    }

    T query(int q_left, int q_right, int st, int en, int node) {
        if(st > en) {
            return zero_val;
        }

        if(st >= q_left and en <= q_right) {
            return seg_tree[node];
        }

        if(max(st, q_left) > min(en, q_right)) {
            return zero_val;
        }

        int mid = st + (en - st) / 2;
        T ans_l = query(q_left, q_right, st, mid, 2 * node + 1);
        T ans_r = query(q_left, q_right, mid + 1, en, 2 * node + 2);
        return query_func(ans_l, ans_r);
    }

    void update(int index, int left, int right, int node, T val) {
        if(right == left) {
            update_func(seg_tree[node], val);
            return;
        }

        int mid = left + (right - left) / 2;
        if(index <= mid) {
            update(index, left, mid, 2 * node + 1, val);
        } else {
            update(index, mid + 1, right, 2 * node + 2, val);
        }

        seg_tree[node] = query_func(seg_tree[2 * node + 1], seg_tree[2 * node + 2]);
    }

public:
    SegmentTree(vector<T> nums, F query_func, F update_func, T zero_val): n(nums.size()), query_func(query_func), update_func(update_func), zero_val(zero_val) {
        seg_tree.resize(4 * n, zero_val);
        build(nums, 0, n - 1);
    }

    T query(int left, int right) {
        return query(left, right, 0, n - 1, 0);
    }

    void update(int index, T val) {
        update(index, 0, n - 1, 0, val);
    }
};
