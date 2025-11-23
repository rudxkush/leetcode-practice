class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        vector<int> ans;
        long long sum = 0;
        for(int i = n; i >= 1; i--) {
            long long remainingSum = (long long) i * (i - 1) / 2;
            if(sum - i + remainingSum >= target) {
                sum = sum - i;
                ans.push_back(-i);
            } else {
                sum = sum + i;
                ans.push_back(i);
            }
        }
        sort(ans.begin(), ans.end());
        if(sum == target) {
            return ans;
        }
        return {};
    }
};

// target = 15
// n = 5

// -5 4 3 2 1
//  i

// sum = 0 (0 - 5 + 10 >= target)

// 10 - 5 = 5