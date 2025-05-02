class Solution {
public:
    bool canTransform(string start, string end) {
        int i = 0;
        int j = 0;
        int n = start.size();
        int m = end.size();
        if(n != m) return false;

        while(i < n || j < n) {
            while(start[i] == 'X') i++;
            while(end[j] == 'X') j++;

            if(start[i] != end[j]) return false;
            if(start[i] == 'R' && j < i) return false;
            if(start[i] == 'L' && j > i) return false;
            i++, j++;
        }
        return true;
    }
};