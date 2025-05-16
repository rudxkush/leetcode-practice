class Solution {
public:
    vector<string> ans;
    void generateParenthesisHelper(int n, string s, int open, int close) {
        if(open == close && open + close == n*2) {
            ans.push_back(s);
            return ;
        }

        if(open < n)
            generateParenthesisHelper(n, s + "(", open + 1, close); 


        if(close < open) 
            generateParenthesisHelper(n, s + ")", open, close + 1);
    }
    vector<string> generateParenthesis(int n) { 
        generateParenthesisHelper(n, "", 0, 0);
        return ans;
    }
};