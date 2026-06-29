class Solution {
public:
    void sum2(vector<vector<int>>& ans, vector<int> path,  int sum, int count, int target, vector<int>& candidates){
        if(sum==target){
            //check if path existing
            
            
                ans.push_back(path);
                return;
        }
        if(sum>target || count>=candidates.size()){
            return;
        }
        path.push_back(candidates[count]);
        sum2(ans, path, sum+candidates[count], count+1, target, candidates);
        path.pop_back();
        
        while(count+1<candidates.size() &&
              candidates[count]==candidates[count+1])
            count++;
        sum2(ans, path, sum, count+1,target, candidates);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        sum2(ans,path,0, 0, target, candidates);
        return ans;
    }
};
