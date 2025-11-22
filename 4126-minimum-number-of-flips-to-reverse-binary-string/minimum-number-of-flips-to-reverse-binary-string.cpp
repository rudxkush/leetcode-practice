class Solution {
public:
    int minimumFlips(int n) {
        // convert it into a binary string
        string binary;
        while(n) {
            binary += ('0' + (n % 2));
            n = n / 2;
        }
        // cout << binary << endl;
        // Get the number of operations needed in order to make it symmetric!
        int strLength = (int) binary.length();
        int operation = 0;
        for(int i = 0; i < strLength; i++) {
            if(binary[i] != binary[strLength - i - 1]) {
                operation++;
            }
        }
        return operation;
    }
};