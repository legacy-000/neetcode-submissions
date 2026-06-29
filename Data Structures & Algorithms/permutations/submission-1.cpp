class Solution {
public:
    void perm(vector<vector<int>>& ans, vector<int> path, vector<int>& nums,vector<bool> visited){
        if(path.size()==nums.size()){
            ans.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visited[i]){
                continue;
            }
            if(!visited[i]){
            path.push_back(nums[i]);
            visited[i]=true;}

            perm(ans,path,nums,visited);
            path.pop_back();
            visited[i]=false;
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        vector<bool> visited (nums.size(),false); 
        perm(ans,path,nums,visited);
        return ans;
    }
};
