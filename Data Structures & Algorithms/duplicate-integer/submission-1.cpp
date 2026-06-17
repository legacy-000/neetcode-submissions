class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> red;
        for(auto i: nums){
            red[i]++;
            if(red[i]>1){
                return true;
            }
        }
        return false;
    }
};