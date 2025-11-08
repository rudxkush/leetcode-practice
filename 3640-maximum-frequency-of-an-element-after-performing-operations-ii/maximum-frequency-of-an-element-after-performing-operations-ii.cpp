class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        int maxElement = 0;
        for(int it : nums) {
            maxElement = max(it, maxElement);
        }
        map<int, int> diffArray;
        unordered_map<int, int> freq;
        for(int i = 0; i < n; i++) {
            freq[nums[i]]++; // mark frequency of nums's element

            int start = (nums[i] - k < 0) ? 0 : nums[i] - k;
            int end = (nums[i] + k > maxElement) ? maxElement : nums[i] + k;

            diffArray[start]++; // mark the start
            diffArray[end + 1]--; // mark the end
            diffArray[nums[i]] += 0; // high probability for nums's element to be our answer
        }

        int answer = 1;
        int cummulativeSum = 0;
        for(auto& [target, diff] : diffArray) {
            diff += cummulativeSum;
            int target_frequency_in_nums = freq[target];
            int operationsRequired = diff - target_frequency_in_nums;
            int operation_within_threshold = (operationsRequired <= numOperations) ? operationsRequired : numOperations;
            answer = max(answer, operation_within_threshold + target_frequency_in_nums);
            cummulativeSum = diff;
        }
        return answer;
    }
};