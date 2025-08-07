class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        int sum;

        while (left <= right) {
            sum = numbers[left] + numbers[right];

            if (sum == target) {
                return {left + 1, right + 1};  // 1-based indices
            } else if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }

        // As per the problem constraints, this will never be reached
        return {-1, -1};
    }
};
