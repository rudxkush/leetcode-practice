class Solution {
public:
    int n = 0;
    vector<vector<vector<int>>> dp;
    vector<int> solve(string& expression, int i, int j) {
        if(!dp[i][j].empty()) return dp[i][j];
        vector<int> results;
        bool isNumber = true;
        for (int k = i; k <= j; ++k) {
            if (!isdigit(expression[k])) {
                isNumber = false;
                break;
            }
        }

        if (isNumber) {
            results.push_back(stoi(expression.substr(i, j - i + 1)));
            return results;
        }
        for (int k = i; k <= j; k++) {
            if (isdigit(expression[k]))
                continue;

            vector<int> left = solve(expression, i, k - 1);
            vector<int> right = solve(expression, k + 1, j);
            char op = expression[k];

            for (auto l : left) {
                for (auto r : right) {
                    int ans = 0;
                    if (op == '-')
                        ans = l - r;
                    else if (op == '+')
                        ans = l + r;
                    else if (op == '*')
                        ans = l * r;
                    results.push_back(ans);
                }
            }
        }
        return dp[i][j] = results;
    }
    vector<int> diffWaysToCompute(string expression) {
        n = expression.length();
        dp.assign(n, vector<vector<int>>(n));
        return solve(expression, 0, n - 1);
    }
};
/*
                solve("2-1-1", 0, 4)
                  |
     -------------------------------------
     |                                   |
Split at '-' (index 1)           Split at '-' (index 3)
Left: solve("2")                 Left: solve("2-1")
Right: solve("1-1")              Right: solve("1")

         |                             |
     [2] returned              ------------------------
                            |                          |
                    Split at '-' (index 1)      [1] returned
                    Left: solve("2") 
                    Right: solve("1")
                          |      |
                        [2]    [1]

Now combine:               Now combine:
[2] - [1] = 1              [2] - [1] = 1  
                           [1] - [1] = 0

So total results:         So total results:
=> (2 - (1 - 1)) = 2       => ((2 - 1) - 1) = 0

Final output:
[2, 0]
*/