class Solution {
private:
    unordered_map<int, int> memo;
    
    int getPower(int num) {
        if (num == 1) return 0;
        if (memo.find(num) != memo.end()) return memo[num];
        
        int original = num;
        int steps = 0;
        
        // Calculate steps without recursion to avoid stack overflow
        while (num != 1 && memo.find(num) == memo.end()) {
            if (num % 2 == 1) {
                num = 3 * num + 1;
            } else {
                num = num / 2;
            }
            steps++;
        }
        
        // If we found a memoized value, add the steps to reach it
        int totalSteps = steps + (num == 1 ? 0 : memo[num]);
        memo[original] = totalSteps;
        
        return totalSteps;
    }
    
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> nums;
        for (int i = lo; i <= hi; i++) {
            nums.push_back({getPower(i), i});
        }

        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), 
                   [](const pair<int, int>& a, const pair<int, int>& b) {
                       if (a.first == b.first) {
                           return a.second < b.second;
                       }
                       return a.first < b.first;
                   });
        
        return nums[k - 1].second;
    }
};