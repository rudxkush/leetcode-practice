class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if(numRows <= 1 || n <= numRows) return s;
        int cycle = (numRows - 1) << 1;
        string res(n, '\0');     
        int index = 0;

        for(int r = 0; r < numRows; r++) {
            for(int i = r; i < n; i += cycle) {
                res[index++] = s[i];

                if(r > 0 && r < numRows - 1) {
                    int j = i + cycle - (r << 1);
                    if(j < n) res[index++] = s[j];
                }
            }
        }
        return res;
    }
};