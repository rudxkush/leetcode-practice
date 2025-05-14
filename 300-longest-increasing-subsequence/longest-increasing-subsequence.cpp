class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int num : nums) {
            if(res.empty() || res.back() < num) {
                res.push_back(num);
            } else {
                auto it = lower_bound(res.begin(), res.end(), num);
                *it = num;
            }
        }
        return res.size();
    }
};