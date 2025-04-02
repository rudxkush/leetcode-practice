// class Solution {
// public:
//     vector<int> smallestSubarrays(vector<int>& A) {
//         int last[30] = {}, n = A.size();
//         vector<int> res(n, 1);
//         for (int i = n - 1; i >= 0; --i) {
//             for (int j = 0; j < 30; ++j) {
//                 if (A[i] & (1 << j))
//                     last[j] = i;
//                 res[i] = max(res[i], last[j] - i + 1);
//             }
//         }
//         return res;
//     }
// };
class Solution {
   public:
	static vector<int> smallestSubarrays(vector<int>& nums) {
		const size_t n = nums.size();
		vector<int> ans(n);

		for (int i = 0; i < n; i++) {
			ans[i] = 1;
			for (int j = i - 1; j >= 0; j--) {
				if ((nums[j] | nums[i]) == nums[j]) break;

				nums[j] |= nums[i];
				ans[j] = i - j + 1;
			}
		}

		return ans;
	}
};

// vector<int> smallestSubarrays(vector<int>& nums) {
//         vector<int> res(nums.size(), 0);
//         // maximum from that particular index
//         // brute force
//         int maxi = 0;
//         for(int i = 0; i < nums.size(); i++) {
//             int orVal = 0;
//             int length = 0;
//             for(int j = i; j < nums.size(); j++) {
//                 orVal |= nums[j];
//                 if(orVal > maxi) {
//                     length = j-i+1;
//                     maxi = orVal;
//                 }
//             }
//             res[i] = length;
//             maxi = 0;
//         }
//         return res;
//     }