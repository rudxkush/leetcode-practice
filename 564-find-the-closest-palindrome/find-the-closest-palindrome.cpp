class Solution {
public:
    // Mirror left half into right half to form palindrome
    long long makePalindrome(long long val) {
        string s = to_string(val);
        int n = s.size();
        int i = (n - 1) / 2, j = n / 2;

        while (i >= 0) {
            s[j++] = s[i--];
        }
        return stoll(s);
    }

    // Largest palindrome strictly smaller than num
    long long getPrev(long long num) {
        long long lo = 0, hi = num, best = -1;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            long long pal = makePalindrome(mid);

            if (pal < num) {
                best = pal;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return best;
    }

    // Smallest palindrome strictly greater than num
    long long getNext(long long num) {
        long long lo = num, hi = (long long)1e18, best = -1;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            long long pal = makePalindrome(mid);

            if (pal > num) {
                best = pal;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return best;
    }

    string nearestPalindromic(string s) {
        long long num = stoll(s);
        long long prevPal = getPrev(num);
        long long nextPal = getNext(num);

        if (abs(prevPal - num) <= abs(nextPal - num))
            return to_string(prevPal);
        return to_string(nextPal);
    }
};
