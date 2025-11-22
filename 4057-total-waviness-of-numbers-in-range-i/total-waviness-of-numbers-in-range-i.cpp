class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int waviness = 0;
        for(int i = num1; i <= num2; i++) {
            string num = to_string(i);
            for(int j = 1; j < (int) num.size() - 1; j++) {
                if(num[j] > num[j - 1] && num[j] > num[j + 1]) {
                    waviness++;
                }
                if(num[j] < num[j - 1] && num[j] < num[j + 1]) {
                    waviness++;
                }
            }
        }
        return waviness;
    }
};