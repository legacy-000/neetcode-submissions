class Solution {
public:
    void subset(vector<vector<int>>& ans, vector<int>path,int count,vector<int>& nums){
        if(count==nums.size()){
            ans.push_back(path);
            return;
        }
        path.push_back(nums[count]);
        subset(ans,path,count+1,nums);
        path.pop_back();
        while(count<nums.size()-1 && nums[count]==nums[count+1]){
            count++;
        }
        subset(ans,path,count+1,nums);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        int count;
        vector<int> path;
        sort(nums.begin(),nums.end());
        subset(ans,path,0,nums);
        return ans;
    }
};
