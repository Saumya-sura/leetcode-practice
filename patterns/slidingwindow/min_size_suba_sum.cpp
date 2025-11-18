class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size(),l=0,r=0,s=0;
        int ml = INT_MAX;
        for(r=0;r<n;r++){
            s+= nums[r];
            while(s>=target){
                ml =min(ml,r-l+1);
                s-=nums[l];
                l++;
            }
        }
        return (ml == INT_MAX)?0:ml;
    }
};

// EX: nums = [2,3,1,2,4,3], target = 7
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.