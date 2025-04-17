class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        else
            return gcd(b, a % b);
    }

    int findGCD(vector<int>& nums) {
        int maxNum = INT_MIN;
        int minNum = INT_MAX;
        for (int num : nums) {
            maxNum = max(maxNum, num);
            minNum = min(minNum, num);
        }
        return gcd(maxNum, minNum);
    }
};