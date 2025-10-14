class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        int largestOdd = pow(3, 19);
        return (largestOdd % n)== 0;
    }
};