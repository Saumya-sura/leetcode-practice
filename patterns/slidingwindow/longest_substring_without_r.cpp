class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> Cs;
        int l=0,r=0,ml=0;
        for(int r=0;r<s.size();r++){
            while(Cs.count(s[r])){
                Cs.erase(s[l]);
                l++;
            }
            Cs.insert(s[r]);
            ml=max(ml,r-l+1);
            
        }
        return ml;
    }
};