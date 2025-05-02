class Solution {
public:
    int sum(int a, int b) {
        while(b != 0) {
            int sum = a^b; // sum w/o carry
            int carry = (a & b) << 1; // carry calculation
            a = sum;
            b = carry;
        }
        return a;
    }
};