class NumArray {
public:
    vector<int> arr, fenwick;

    NumArray(vector<int>& nums) {
        int n = nums.size();
        arr = nums;
        fenwick.assign(n + 1, 0);
        for (int i = 0; i < n; i++) add(i, arr[i]);
    }

    void add(int idx, int val) {
        for (int i = idx + 1; i <= arr.size(); i += i & -i)
            fenwick[i] += val;
    }

    void update(int idx, int val) {
        int diff = val - arr[idx];
        arr[idx] = val;
        add(idx, diff);
    }

    int prefixSum(int idx) {
        int res = 0;
        for (int i = idx + 1; i > 0; i -= i & -i)
            res += fenwick[i];
        return res;
    }

    int sumRange(int l, int r) {
        return prefixSum(r) - (l ? prefixSum(l - 1) : 0);
    }
};
