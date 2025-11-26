class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Detect the cycle using Floyd’s Tortoise & Hare.
        int turtoise = nums[0]; 
        int hare = nums[0];
        while(true) {
            turtoise = nums[turtoise];
            hare = nums[nums[hare]];
            if(turtoise == hare) {
                break;
            }
        }
        // Find the entry point of the cycle!
        int ptr1 = nums[0];
        int ptr2 = turtoise;
        while(ptr1 != ptr2) {
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }
        return ptr1;
    }
};