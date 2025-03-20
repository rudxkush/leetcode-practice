class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;  // To store all unique OR values
        unordered_set<int> prev;    // To store OR values of previous iteration
        
        for (int num : arr) {
            unordered_set<int> curr = {num}; 
            
            // For each OR value from previous iteration, OR it with current element
            for (int prevOr : prev) {
                curr.insert(prevOr | num);
            }
            
            // Update result with all new OR values
            result.insert(curr.begin(), curr.end());
            
            // Current becomes previous for next iteration
            prev = curr;
        }
        
        return result.size();
    }
};



//  // brute force solution 
//         // Time Complexity : O(N^2)
//         // Space Complexity : O(st.size())
//         unordered_set<int> st;
//         for(int i = 0; i < arr.size(); i++){ 
//             int orValue = 0;
//             for(int j = i; j < arr.size(); j++) {
//                 orValue |= arr[j];
//                 st.insert(orValue);
//             }
//         }
//         return st.size();
//     } 
