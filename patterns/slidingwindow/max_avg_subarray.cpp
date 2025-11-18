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

// EX: nums = [1,12,-5,-6,50,3], k = 4 
// Output: 12.75
// Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75