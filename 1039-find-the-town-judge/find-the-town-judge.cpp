class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> outDegree(n + 1, 0);
        vector<int> inDegree(n + 1, 0);
        for(auto& edge : trust) {
            outDegree[edge[0]]++;
            inDegree[edge[1]]++;
        }
        for(int i = 1; i <= n; i++) {
            if(outDegree[i] == 0 && inDegree[i] == n - 1) return i;
        }
        return -1;
    }
};
/*
        n people labelled from 1 to n
        Out of these, One of them is a town judge.

        three conditions : 
        1. Town judge trusts nobody
        2. Everybody (except for the town judge) trusts the town judge.
        3. There is exactly one person that satisfies properties 1 and 2

        two properties : 
        Trust Nobody -> Town judge
        Trust Town Judge -> Everyone

        n = 2
        trust = [[1, 2]]
        so whichever person has exactly 0 outDegrees is the town Judge. If none exist then return -1
        output = 2

        n = 3
        trust = [[1, 3], [2, 3]]
        outptu = 3
*/