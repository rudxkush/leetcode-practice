class Solution {
public:
    int gcd(int x , int y){
        while(y != 0){
            int temp = y;
            y = x % y;
            x = temp;
        }
        return x;
    }
    int countBeautifulPairs(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            int firstDigit = nums[i];
            while (firstDigit > 9) firstDigit /= 10;
            for(int j = i+1; j < nums.size(); j++) {
                int lastDigit = nums[j] % 10;
                if((gcd(firstDigit, lastDigit)) == 1)count++;
            }
        }
        return count;
    }
};
/*
    x = 2
    y = 5
    gcd(x, y) ->
    until y is not 0
    we are gonna keep doing :

    temp = 5
    y = 2 mod 5 = 2
    x = 5

    temp = 2
    y = 5 mod 2 = 1
    x = 2

    temp = 1
    y = 2 mod 1 = 0
    x = 1

    Since y is now 0, the algorithm stops and returns 1 as the GCD.
*/
