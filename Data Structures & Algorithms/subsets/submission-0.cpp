class Solution {
public:
    void subset(vector<vector<int>>& ans, vector<int> path,int count, vector<int>& nums){
        int n=path.size();
        if(count==nums.size()){
            ans.push_back(path);
            return;
        }
        path.push_back(nums[count]);
        subset(ans,path,count+1,nums);
        path.pop_back();
        subset(ans,path,count+1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>path;
        subset(ans,path,0,nums);
        return ans;
    }
};
