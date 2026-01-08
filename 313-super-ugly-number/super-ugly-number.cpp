class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n == 1) {
            return n;
        }
        vector<long long> dp = {1};
        long long a = primes.size();
        vector<long long> multiply(primes.size(), 0);

        int i = 2;
        while(i <= n){
            long long mini = INT_MAX;
            for(int j = 0; j < a; j++){
                long long a = dp[multiply[j]];
                mini = min(mini, (a * primes[j]));
            }
            
            dp.push_back(mini);
            for(int j = 0; j < a; j++){
                if(mini % primes[j] == 0){
                    multiply[j]++;
                }
            }
            i++;
        }
        return dp[n - 1];
    }
};