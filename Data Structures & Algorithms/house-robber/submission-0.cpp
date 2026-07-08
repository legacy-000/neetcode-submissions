class Solution {
public:
    int solve(int i, vector<int>& dp,vector<int>& nums,int n){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        dp[i]=max(solve(i+1,dp,nums,n),nums[i]+solve(i+2,dp,nums,n));
        return dp[i];
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        int n=nums.size();
        return max(solve(0,dp,nums,n),solve(1,dp,nums,n));
    }
};
