class Solution {
public:
    void sortColors(vector<int>& nums) { 
        sort(nums.begin(), nums.end());
    }
};

// void sortColors(vector<int>& nums) {
//     // Dutch National Flag
//     int low = 0;
//     int high = nums.size() - 1;
//     int i = 0;

//     while (i <= high) {
//         if (nums[i] == 0) {
//             swap(nums[i], nums[low]);
//             low++;
//             i++;
//         } else if (nums[i] == 2) {
//             swap(nums[i], nums[high]);
//             high--;
//         } else {
//             i++;
//         }
//     }
// }
// """
// [2, 0, 2, 1, 1, 0]
// low = 0, high = 5, i = 0
// while i <= high
//    if nums[i] == 0
//       swap(nums[i], nums[l]); 
//       l++;
//       i++;
//    if nums[i] == 2
//       swap(nums[i], nums[high]);
//       high--;
//       i++;
//    else 
//       i++;

// """