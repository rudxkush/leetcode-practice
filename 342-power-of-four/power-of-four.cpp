class Solution {
public:
    bool isPowerOfFour(int n) {
        /*
            n = 4^x
            taking natural log on both side

            logn base e = xlogn base 4
            x = logn base e / logn base 4
            and then we check whether x on substituting in the exp 4^x gives n
        */
        if(n <= 0) return false;
        int x = log(n) / log(4);
        if(pow(4, x) == n) {
            return true;
        }
        return false;
    }
};
