class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        prefix.assign(nums.size(), 0);
        prefix[0] = nums[0];
        for(int i = 1; i < (int)prefix.size(); i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return prefix[right];
        else return prefix[right] - prefix[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */