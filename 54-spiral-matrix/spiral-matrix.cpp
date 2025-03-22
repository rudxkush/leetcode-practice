class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& query) {
        vector<int> res;
        if (query.empty()) return res;
        int n = query.size(), m = query[0].size(), totalEle = n*m;
        int up = 0, down = n-1, left = 0, right = m-1;
        while(res.size() < totalEle) {
            for(int i = left; i <= right && res.size() < totalEle; i++) {
                res.push_back(query[up][i]);
            }
            up++;
    		
            for(int i = up; i <= down && res.size() < totalEle; i++) {
    		    res.push_back(query[i][right]);
    	    }    
    	    right--;
    		
            for(int i = right; i >= left && res.size() < totalEle; i--) {
                res.push_back(query[down][i]);
    	    }    
    	    down--;
            
            for(int i = down; i >= up && res.size() < totalEle; i--) {
                res.push_back(query[i][left]);
    	    }
    	    left++;
        }
    return res;  
    }
};