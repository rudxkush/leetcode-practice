class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        int n = (int)nums.size();
        prefix.clear();
        prefix.resize(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
    }

    void update(int index, int val) {
        int m = (int) prefix.size();
        int original = (index == 0) ? prefix[0] : prefix[index] - prefix[index - 1];
        if (val == original)
            return;
        
        int modify = val - original;
        
        for (int j = index; j < m; j++) {
            prefix[j] += modify;
        }
    }

    int sumRange(int left, int right) {
        int inclusiveSum = prefix[right] - ((left == 0) ? 0 : prefix[left - 1]);
        return inclusiveSum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */