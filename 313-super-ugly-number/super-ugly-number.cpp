class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int num_of_primes = primes.size();

        vector<int> trackIncrementsOfPrimes(num_of_primes, 0);
        vector<long long> currValues(num_of_primes);
        vector<long long> ans;

        ans.push_back(1);

        for (int i = 0; i < num_of_primes; i++) {
            currValues[i] = primes[i];
        }

        long long nextNum = 1;

        for (int i = 1; i < n; i++) {
            long long mini = LLONG_MAX;

            for (long long num : currValues) {
                mini = min(mini, num);
            }

            ans.push_back(mini);
            nextNum = mini;

            for (int j = 0; j < num_of_primes; j++) {
                if (mini == currValues[j]) {
                    trackIncrementsOfPrimes[j]++;
                    currValues[j] =
                        ans[trackIncrementsOfPrimes[j]] * primes[j];
                }
            }
        }

        return (int)nextNum;
    }
};
