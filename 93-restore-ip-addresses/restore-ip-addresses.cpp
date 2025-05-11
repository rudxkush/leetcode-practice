class Solution {
public:
    void generateIPaddresses(string& s, vector<string>& segments, vector<string>& result, int i) {
        if (segments.size() == 4 && i == s.length()) {
            result.push_back(segments[0] + "." + segments[1] + "." + segments[2] + "." + segments[3]);
            return;
        }
        if (segments.size() == 4 || i == s.length()) {
            return; 
        }
        for (int j = 1; j <= 3 && i + j <= s.length(); j++) {
            string blah = s.substr(i, j);
            
            if (blah.length() > 1 && blah[0] == '0') { 
                continue;
            }

            int val = stoi(blah); // check valid IP (0-255)
            if (val > 255) {
                continue;
            }

            segments.push_back(blah); // Choose
            generateIPaddresses(s, segments, result, i + j); // move forward
            segments.pop_back(); // Backtrack!
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if (s.length() > 12 || s.length() < 4) {
            return {}; 
        }
        vector<string> result;
        vector<string> segments;
        generateIPaddresses(s, segments, result, 0);
        return result;
    }
};