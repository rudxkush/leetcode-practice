class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = (int) s.size();
        // if(n == 0) return 0;
        unordered_map<char, int> charFAMap; // {character, firstAppearance}
        int maxLength = 0;
        int L = 0;
        for(int R = 0; R < n; R++) {
            // If the character is already present in the map
            if(charFAMap.find(s[R]) != charFAMap.end()) {
                L = max(L, charFAMap[s[R]] + 1);
            }  
            // present or not present!
            charFAMap[s[R]] = R;
            maxLength = max(maxLength, R - L + 1);
        }
        return maxLength;
    }
};