class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        vector<int> ans;
        vector<int> positive;
        long long sum = 0;
        for(int i = n; i >= 1; i--) {
            long long remainingSum = (long long) i * (i - 1) / 2;
            if(sum - i + remainingSum >= target) {
                sum = sum - i;
                ans.push_back(-i);
            } else {
                sum = sum + i;
                positive.push_back(i);
            }
        }
        // sort(ans.begin(), ans.end());
        if(sum == target) {
            reverse(positive.begin(), positive.end());
            ans.insert(ans.end(), positive.begin(), positive.end());
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