class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;              // pointer for 0
        int mid = 0;              // pointer for 1
        int high = nums.size() - 1; // pointer for 2

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } 
            else if (nums[mid] == 1) {
                mid++;
            } 
            else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
