class Solution {
public:
    void backtrack(vector<vector<int>>& ans, int index, vector<int>& path, int currentSum, vector<int>& nums, int target) {
        // Base Case: If we reach the target sum, record the path
        if (currentSum == target) {
            ans.push_back(path);
            return;
        }
        
        // Base Case: Stop if we exceed the target or run out of numbers
        if (currentSum > target || index == nums.size()) {
            return;
        }

        // Choice 1: Include the current element (Stay at same index to allow infinite reuse)
        path.push_back(nums[index]);
        backtrack(ans, index, path, currentSum + nums[index], nums, target);
        path.pop_back(); // Backtrack step

        // Choice 2: Exclude the current element (Move to the next index)
        backtrack(ans, index + 1, path, currentSum, nums, target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        backtrack(ans, 0, path, 0, nums, target); // Initialized currentSum to 0
        return ans;
    }
};
