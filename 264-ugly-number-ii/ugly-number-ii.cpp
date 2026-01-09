class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans;
        int mulTwo = 2, mulThree = 3, mulFive = 5;
        int indTwo = 0, indThree = 0, indFive = 0;

        ans.push_back(1);
        int nextNum = 1;
        for(int i = 1; i < n; i++) {
            int mini = min({mulTwo, mulThree, mulFive});
            ans.push_back(mini);
            nextNum = mini;

            if(mini == mulTwo) {
                indTwo += 1;
                mulTwo = ans[indTwo] * 2;
            }  
            if(mini == mulThree) {
                indThree += 1;
                mulThree = ans[indThree] * 3;
            } 
            if(mini == mulFive) {
                indFive += 1;
                mulFive = ans[indFive] * 5;
            }
        } 
        return nextNum;
    }
};