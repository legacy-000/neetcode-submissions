class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,pair<int,int>> mpp;
        vector<int> nums2;
        for(auto c:nums){
            nums2.push_back(c);
        }
        for(auto i:nums){
            mpp[i].first++;
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            int big=INT_MIN;
            int index;
            for(auto& c: mpp){
                if(big<c.second.first && !c.second.second){
                    big=c.second.first;
                    index=c.first;
                }
            }
            mpp[index].second=1;
            ans.push_back(index);
        }
        return ans;
    }
};
