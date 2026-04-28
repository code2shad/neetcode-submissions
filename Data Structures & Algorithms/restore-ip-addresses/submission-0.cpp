class Solution {
public:
    vector<string> res;
        // Helper to check if a segment is valid
    bool valid(const string &s, int start, int len) {
        if (start + len > s.size()) return false;

        // Leading zero check
        if (len > 1 && s[start] == '0') return false;

        int num = stoi(s.substr(start, len));
        return num <= 255;
    }

    void backtrack(string &s, int index, int parts, string curr) {
        // If we used 4 parts and consumed all characters
        if (parts == 4 && index == s.size()) {
            curr.pop_back();        // remove last dot
            res.push_back(curr);
            return;
        }

        // If parts exceed or string finished early
        if (parts == 4 || index == s.size())
            return;

        // Try segments of length 1,2,3
        for (int len = 1; len <= 3; len++) {
            if (!valid(s, index, len)) continue;

            string segment = s.substr(index, len);
            backtrack(s, index + len, parts + 1, curr + segment + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0, 0, "");
        return res;
    }
};