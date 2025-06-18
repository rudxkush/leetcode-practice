class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int wordLen = word.length();
        int count = 0;
        int maxCount = 0;
        int n = sequence.length();

        for (int i = 0; i <= n - wordLen; i++) {
            int temp = 0;
            while (sequence.substr(i, wordLen) == word) {
                temp++;
                i += wordLen;
            }
            maxCount = max(maxCount, temp);
            i -= temp * wordLen; 
        }

        return maxCount;
    }
};
