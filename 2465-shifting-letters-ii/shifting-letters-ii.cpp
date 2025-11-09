class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diffArr(n + 1, 0);
        for (auto& sh : shifts) {
            int start = sh[0], end = sh[1], dir = sh[2];
            diffArr[start] += (dir == 1 ? 1 : -1);
            diffArr[end + 1] -= (dir == 1 ? 1 : -1);
        }
        string res = s;
        for (int i = 0, j = 0; i < n; i++) {
            j = (j + diffArr[i]) % 26;
            res[i] = 'a' + (26 + (s[i] - 'a') + j) % 26;
        }
        return res;
    }
};