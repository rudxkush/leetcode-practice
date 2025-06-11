class Solution {
public:
    int n = 0;
    vector<vector<int>> dp;
    int solve(vector<int>& nums, int i, int j) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int left = nums[i] - solve(nums, i + 1, j);
        int right = nums[j] - solve(nums, i, j - 1);

        return dp[i][j] = max(left, right);
    }
    bool predictTheWinner(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, vector<int>(n, -1));
        return solve(nums, 0, n - 1) >= 0;
    }
};
/*
                         solve(0, 2)
                          /       \
        --------------------------------------------
        |                                          |
  Pick 0: nums[0]=1                          Pick 2: nums[2]=2
   solve(1, 2)                                 solve(0, 1)
    /     \                                    /     \
   /       \                                  /       \
nums[1]=5  nums[2]=2                      nums[0]=1   nums[1]=5
solve(2,2) solve(1,1)                     solve(1,1)  solve(0,0)
   |          |                              |            |
  [2]        [5]                            [5]          [1]

Now combine:                               Now combine:
→ Pick 1: 5 - 2 = 3                        → Pick 0: 1 - 5 = -4  
→ Pick 2: 2 - 5 = -3                       → Pick 1: 5 - 1 = 4  

solve(1,2) = max(3, -3) = 3                solve(0,1) = max(-4, 4) = 4

Back to root:                              Back to root:
→ Pick 0: 1 - 3 = -2                       → Pick 2: 2 - 4 = -2


Final Result:
solve(0, 2) = max(-2, -2) = -2 → Player 1 **cannot win**

*/