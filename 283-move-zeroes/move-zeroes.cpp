class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        while(j < n) {
            if(nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
            }
            j++;
        }
    } 
};

/*
    0  1. 0. 3. 12
    i.
       j 
    1. 0. 0. 3. 12
       i
             j 
    1. 3. 0. 0. 12
          i
                j 
    1. 3. 12. 0. 0
          i
                 j 
*/