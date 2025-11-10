class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> difA(n + 1, 0);
        for(auto q : queries) {
            difA[q[0]]++;
            difA[q[1] + 1]--;
        }

        int decrementThreshold = 0;
        for(int i = 0; i < n; i++) {
            decrementThreshold += difA[i];
            if(decrementThreshold < nums[i]) return false;
        }
        return true;
    }
};


/*
    4  3  2  1
   -1 -1     1  1
   -1 -2 -2  -1 0

*/