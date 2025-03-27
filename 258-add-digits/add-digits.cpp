class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        while(num > 0) {
            int unitDigit = num%10;

            sum += unitDigit;

            num /= 10;
        }
        if(sum > 9) return addDigits(sum);
        else return sum;
    }
};