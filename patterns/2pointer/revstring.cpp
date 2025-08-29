class Solution {
public:
    void reverseString(vector<char>& s) {
      int j=s.size()-1;
     while(i<j){
        swap(s[i],s[j]);
        i++;
        j--;
     }
    }
};