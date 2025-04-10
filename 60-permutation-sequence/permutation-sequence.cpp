class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> numbers;
        for (int i = 1; i < n; i++) {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        string res;
        k = k - 1;
        while (true) {
            res = res + to_string(numbers[k / fact]);
            numbers.erase(numbers.begin() + k / fact);
            if (numbers.size() == 0)
                break;
            k %= fact;
            fact /= numbers.size();
        }
        return res;
    }
};
// class Solution {
// public:
//     vector<string> blah;
//     void getKthSequence(string& s, int i) {
//         if (i == s.size()) {
//             blah.push_back(s);
//             return;
//         }
//         for (int j = i; j < s.size(); j++) {
//             swap(s[i], s[j]); // choose
//             getKthSequence(s, i+1); // move forward
//             swap(s[i], s[j]); // backtrack
//         }
//     }
//     string getPermutation(int n, int k) {
//         string s;
//         for (int i = 1; i < n + 1; i++)
//             s.push_back(i + '0');
//         getKthSequence(s, 0);
//         sort(blah.begin(), blah.end());
//         return blah[k - 1];
//     }
// };