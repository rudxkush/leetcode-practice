class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if(n % 2 == 1) return false; // for odd length strings

        int openBrackets = 0, unlocked = 0;
        for(int i = 0; i < n; i++) {
            if(locked[i] == '0') {
                unlocked++;
            } else if(s[i] == '(') {
                openBrackets++;
            } else if(s[i] == ')') {
                if(openBrackets) {
                    openBrackets--;
                } else if(unlocked) {
                    unlocked--;
                } else {
                    return false;
                }
            }
        }

        int balance = 0;
        for(int i = n-1; i >= 0; i--) {
            if(locked[i] == '0') { 
                unlocked--;
                balance--;
            } else if(s[i] == '(') {
                balance++;
                openBrackets--;
            } else if(s[i] == ')') {
                balance--;
            } 
            if(balance > 0) {
                return false;
            }
        }
        if(openBrackets > 0) {
            return false;
        }
        return true;
    }
};