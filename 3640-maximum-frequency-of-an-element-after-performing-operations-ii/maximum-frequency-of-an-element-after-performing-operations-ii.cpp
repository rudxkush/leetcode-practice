class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int upperLimit = *max_element(nums.begin(), nums.end()) + k;
        map<int, int> freqImpact;
        unordered_map<int, int> freqSeen;

        for (int num : nums) {
            freqSeen[num]++;

            int leftRange = max(0, num - k);
            int rightRange = min(upperLimit, num + k);

            freqImpact[leftRange]++;
            freqImpact[rightRange + 1]--;

            freqImpact[num] += 0;
        }

        int result = 1;
        int currentSum = 0;

        for (auto it = freqImpact.begin(); it != freqImpact.end(); ++it) {
            int currentNum = it->first;
            currentSum += it->second;
            it->second = currentSum;

            int existingCount = freqSeen[currentNum];
            int convertibleCount = it->second - existingCount;
            int maxPossible =
                existingCount + min(convertibleCount, numOperations);

            result = max(result, maxPossible);
        }

        return result;
    }
};
