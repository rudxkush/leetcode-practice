class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        vector<vector<int>> digits(10, vector<int>(10, 0));
        int n = (int)nums.size();
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int place = 0;
            while (num) {
                digits[place++][num % 10]++;
                num /= 10;
            }
        }
        long long res = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                long long count = digits[i][j];
                res += ((long long)n - count ) * count;
            }
        }
        return res / 2;
    }
};