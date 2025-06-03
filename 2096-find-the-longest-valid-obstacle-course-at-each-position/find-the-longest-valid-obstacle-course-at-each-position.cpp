class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n + 1, 1e9), ans;

        for(int i = 0; i < n; i++) {
            int index = upper_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[index] = nums[i];
            ans.push_back(index + 1);
        }
        return ans;
    }
};
/*
array : [3,1,5,6,4,2]
temp : [1e9, 1e9, 1e9, 1e9, 1e9, 1e9]
ans : []

index 0 :
upper_bound of 3 is at index 0
store 3 at index 0
temp : [3, 1e9, 1e9, 1e9, 1e9, 1e9]
ans : [1]

index 1 :
upper_bound of 1 is at index 0
store 1 at index 0
temp : [1, 1e9, 1e9, 1e9, 1e9, 1e9]
ans : [1, 1]

index 2 :
upper_bound of 5 is at index 1
store 5 at index 1
temp : [1, 5, 1e9, 1e9, 1e9, 1e9]
ans : [1, 1, 2]

index 3 :
upper_bound of 6 is at index 2
store 6 at index 2
temp : [1, 5, 6, 1e9, 1e9, 1e9]
ans : [1, 1, 2, 3]

index 4 :
upper_bound of 4 is at index 1
store 4 at index 1
temp : [1, 4, 6, 1e9, 1e9, 1e9]
ans : [1, 1, 2, 3, 2]

index 5 :
upper_bound of 2 is at index 1
store 2 at index 1
temp : [1, 2, 2, 1e9, 1e9, 1e9]
ans : [1, 1, 2, 3, 2, 2]
*/