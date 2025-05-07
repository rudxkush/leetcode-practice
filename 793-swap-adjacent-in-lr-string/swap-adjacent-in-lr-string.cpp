class Solution {
public:
    bool canTransform(string start, string end) {
        // instead of trying to prove it 
        // rather look for where it fails
        int i = 0;
        int j = 0;
        int n = start.size(), m = end.size();
        if(n != m) return false;
        while(i < n || j < n) {
            while(start[i] == 'X') i++;
            while(end[j] == 'X') j++;

            if(start[i] != end[j]) return false;
            if(start[i] == 'R' && i > j) return false;
            if(start[i] == 'L' && i < j) return false;
            i++, j++;
        }
        return true;
    }
};