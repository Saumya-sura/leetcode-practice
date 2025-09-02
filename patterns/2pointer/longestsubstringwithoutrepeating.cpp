    class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
           map<char,int>Char;
           int start=0,maxl=0;
           for(int i=0;i<s.length();++i){
            if (Char.find(s[i]) != Char.end() && Char[s[i]] >= start) {
              
                start = Char[s[i]] + 1;
            }
            
              Char[s[i]] = i;
            maxl = std::max(maxl,i-start+1);
           } 
             return maxl;
        }
    }; 