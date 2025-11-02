class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false; // ✅ edge case check

        vector<int> c1(26, 0);
        vector<int> c2(26, 0);

        for (int i = 0; i < s1.size(); i++) {
            c1[s1[i] - 'a']++;
            c2[s2[i] - 'a']++;
        }

        for (int i = 0; i <= s2.size() - s1.size(); i++) {
            if (c1 == c2) return true;

            // Slide the window
            if (i + s1.size() < s2.size()) {
                c2[s2[i] - 'a']--;                  // remove old char
                c2[s2[i + s1.size()] - 'a']++;      // add new char
            }
        }

        return false;
    }
};
