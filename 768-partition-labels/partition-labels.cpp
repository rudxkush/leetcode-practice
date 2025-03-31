class Solution {
public:
    vector<int> partitionLabels(string s) {
        int i = 0, j = 0;
        vector<int> res;
        vector<int> mp(26, 0); // hashMap
        for (int i = 0; i < s.length(); i++) {
            mp[s[i] - 'a'] = i;
        }
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            end = max(end, mp[s[i] - 'a']);

            if (i == end) {
                res.push_back(i - start + 1);
                start = i + 1;
            }
        }

        return res;
    }
};
// vector<int> partitionLabels(string s) {
//     vector<int> partitionSizes;
//     int lastOccurrence[26] = {0}, firstOccurrence[26] = {0};
//     int partitionStart = 0, partitionEnd = 0;

//     // Store the last occurrence index of each character
//     for (int i = 0; i < s.length(); i++) {
//         lastOccurrence[s[i] - 'a'] = i;
//     }

//     for (int i = 0; i < s.length(); i++) {
//         // Store the first occurrence index of each character (if not set)
//         if (!firstOccurrence[s[i] - 'a']) {
//             firstOccurrence[s[i] - 'a'] = i;
//         }

//         // If we find a new partition start
//         if (partitionEnd < firstOccurrence[s[i] - 'a']) {
//             partitionSizes.push_back(partitionEnd - partitionStart + 1);
//             partitionStart = i;
//             partitionEnd = i;
//         }

//         // Update partition end boundary
//         partitionEnd = max(partitionEnd, lastOccurrence[s[i] - 'a']);
//     }

//     // Add the last partition if it exists
//     if (partitionEnd - partitionStart + 1 > 0) {
//         partitionSizes.push_back(partitionEnd - partitionStart + 1);
//     }

//     return partitionSizes;
// }