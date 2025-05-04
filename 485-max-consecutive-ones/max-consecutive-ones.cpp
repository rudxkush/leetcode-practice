class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxAdjOnes = -1;
        int countAdjOnes = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                countAdjOnes++;
            } else {
                maxAdjOnes = max(countAdjOnes, maxAdjOnes);
                countAdjOnes = 0;
            }
        }
        maxAdjOnes = max(countAdjOnes, maxAdjOnes);
        return maxAdjOnes;
    }
};