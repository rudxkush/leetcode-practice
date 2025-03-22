class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int> (n));
        int totalEle = n*n;
        int up = 0, down = n-1, left = 0, right = n-1;
        int val = 1;
        while(totalEle) {
            for(int i = left; i <= right; i++) {
                res[up][i] = val;
                val += 1;
                totalEle -= 1;
            }
            up++;
    		
            for(int i = up; i <= down; i++) {
    		    res[i][right] = val;
                val += 1;
                totalEle -= 1;
    	    }    
    	    right--;
    		
            for(int i = right; i >= left; i--) {
                res[down][i] = val;
                val += 1;
                totalEle -= 1;
    	    }    
    	    down--;
            
            for(int i = down; i >= up; i--) {
                res[i][left] = val;
                val += 1;
                totalEle -= 1;
    	    }
    	    left++;
        }
    return res;
    }
};