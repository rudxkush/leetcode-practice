class Solution {
public:
    int atMost(string& s, int k) {
        unordered_map<char, int> mp; // {char, freq}
        int l = 0, r = 0, count = 0, n = s.length();
        while (r < n) {
            mp[s[r]]++;
            while (mp.size() > k) {
                mp[s[l]]--;
                if (mp[s[l]] == 0) {
                    mp.erase(s[l]);
                }
                l++;
            }
            count += r - l + 1;
            r++;
        }
        return count;
    }
    int numberOfSubstrings(string s) { return atMost(s, 3) - atMost(s, 2); }
};