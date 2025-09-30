class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slots = 1;  
        int n = preorder.size();
        for (int i = 0; i < n; ) {
            if (slots == 0) return false;

            int j = i;
            while (j < n && preorder[j] != ',') j++;
            string token = preorder.substr(i, j - i);

            slots--;
            if (token != "#") slots += 2;
            i = j + 1;  
        }

        return slots == 0;  
    }
};
