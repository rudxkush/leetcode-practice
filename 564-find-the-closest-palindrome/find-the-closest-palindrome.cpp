class Solution {
public:
    long mirrorLeft(long firstHalf, bool isEven) {
        long resultNum = firstHalf;

        if (isEven == false) {
            firstHalf /= 10;
        }
        while (firstHalf > 0) {
            int digit = firstHalf % 10;
            resultNum = (resultNum * 10) + digit;
            firstHalf /= 10;
        }
        return resultNum;
    }
    string nearestPalindromic(string n) {
        int L = n.length();
        int mid = L / 2;
        int firstHalfLength = (L % 2 == 0) ? mid : (mid + 1);
        long firstHalf = stol(n.substr(0, firstHalfLength));

        vector<long> possibleResults;

        possibleResults.push_back(mirrorLeft(firstHalf, L % 2 == 0));
        possibleResults.push_back(mirrorLeft(firstHalf - 1, L % 2 == 0));
        possibleResults.push_back(mirrorLeft(firstHalf + 1, L % 2 == 0));
        possibleResults.push_back((long)pow(10, L - 1) - 1);
        possibleResults.push_back((long)pow(10, L) + 1);

        long diff = LONG_MAX;
        long result = INT_MAX;
        long orignalNum = stol(n);

        for (long num : possibleResults) {
            if (num == orignalNum)
                continue;
            if (abs(num - orignalNum) < diff) {
                diff = abs(num - orignalNum);
                result = num;
            } else if (abs(num - orignalNum) == diff) {
                result = min(result, num);
            }
        }
        return to_string(result);
    }
};