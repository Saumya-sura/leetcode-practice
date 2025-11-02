class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
     int m=0,cs=0;
     for(int i=0;i<k;i++){
        cs +=nums[i];
     }   
     m=cs;
     for(int i=k;i<nums.size();i++){
        cs += nums[i] - nums[i-k];
        m =max(m,cs);
     }
         return (double)m/k;
    }

};