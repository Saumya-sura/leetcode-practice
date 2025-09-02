

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minlen = INT_MAX;
        int cs = 0, high = 0, low = 0;

        while (high < nums.size()) {
            cs += nums[high];
            high++;

            while (cs >= target) {
                int cws = high - low;
                minlen = min(minlen, cws);
                cs -= nums[low];
                low++;
            }
        }

        return minlen == INT_MAX ? 0 : minlen;
    }
};
