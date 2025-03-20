class Solution {
public:
    // vector<vector<string>> res;
    int count = 0;
    bool isValid(vector<string>& query, int row, int col, char choice) {
        // row & column check
        for(int i = 0; i < query.size(); i++) {
            if (query[i][col] == 'Q') return false;
     	    if (query[row][i] == 'Q') return false;
        }
        // diagonal check
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if(query[i][j] == 'Q') return false;
        }
        // anti-daigonal check
        for(int i = row, j = col; i >=0 && j < query.size(); i--, j++) {
            if(query[i][j] == 'Q') return false;
        }
    return true;
    }
    void solve(vector<string>& query, int row, int n_queens) {
        // base case
        if(row == query.size()) {
            // res.push_back(query);
            count++;
     	    return ;
        }
        // choices
        for(int col = 0; col < query[row].length(); col++) {
            if(isValid(query , row, col, 'Q')){
                query[row][col] = 'Q'; // choose
     	        solve(query, row+1, n_queens-1); // move forward
     	        query[row][col] = '.'; // backtrack
            }  
        }
    }
    int totalNQueens(int n) {
        vector<string> query(n, string(n, '.'));
        solve(query, 0, n);
        return count;     
    }
};