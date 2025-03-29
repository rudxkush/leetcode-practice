class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string repeated = A;
        int count = 1;

        // Keep appending A until it is at least the size of B
        while (repeated.size() < B.size()) {
            repeated += A;
            count++;
        }

        // If B is found inside the current repeated string, return count
        if (repeated.find(B) != string::npos) { // string::npos - represents an invalid index
            return count;
        }

        // Append A once more and check again
        repeated += A;
        count++;

        if (repeated.find(B) != string::npos) {
            return count;
        }

        return -1;
    }
};