#include<bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    vector<int> seg_tree;
    int n;

    long long build(vector<int> &nums, int left, int right, int node = 0) {
        if(left == right) {
            seg_tree[node] = nums[left];
            return nums[left];
        }

        int mid = left + (right - left) / 2;

        long long ans = 0;
        ans += build(nums, left, mid, 2 * node + 1);
        if(mid + 1 <= right)
            ans += build(nums, mid + 1, right, 2 * node + 2);
        
        seg_tree[node] = ans;
        return ans;
    }

    long long rangeSumHelper(int q_left, int q_right, int st, int en, int node) {
        if(st >= q_left and en <= q_right) {
            return seg_tree[node];
        }

        if(max(st, q_left) > min(en, q_right)) {
            return 0LL;
        }

        int mid = st + (en - st) / 2;
        long long ans = 0;
        ans += rangeSumHelper(q_left, q_right, st, mid, 2 * node + 1);
        if(mid + 1 <= en) {
            ans += rangeSumHelper(q_left, q_right, mid + 1, en, 2 * node + 2);
        }

        return ans;
    }

    int pointUpdateHelper(int index, int left, int right, int new_val, int node) {
        if(left == right and left == index) {
            int cur_val = seg_tree[node];
            seg_tree[node] = new_val;
            return new_val - cur_val;
        }

        int mid = left + (right - left) / 2;

        int delta = 0;
        if(index <= mid) {
            delta = this->pointUpdateHelper(index, left, mid, new_val, 2 * node + 1);
        } else {
            delta = this->pointUpdateHelper(index, mid + 1, right, new_val, 2 * node + 2);
        }

        seg_tree[node] += delta;
        return delta;
    }

public:
    SegmentTree(vector<int> nums) {
        int n = nums.size();
        seg_tree = vector<int>(4 * n, 0);
        this->build(nums, 0, n - 1);
        this->n = n;
    }

    long long rangeSum(int left, int right) {
        return this->rangeSumHelper(left, right, 0, n - 1, 0);
    }

    void pointUpdate(int index, int new_val) {
        if(index < 0 or index >= n) return;
        this->pointUpdateHelper(index, 0, n - 1, new_val, 0);
    }
};
