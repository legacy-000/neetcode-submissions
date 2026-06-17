class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string,int> indi;
    int k=1;                
    for(int i=0;i<strs.size();i++){
        string st1=strs[i];
        sort(st1.begin(),st1.end());
        if(indi[st1]==0){
        indi[st1]=k++;
        }
    }
    int n=indi.size();
    vector<vector<string>> ans(n);
    for(int i=0;i<strs.size();i++){
        string st1=strs[i];
        string st2=st1;
        sort(st1.begin(),st1.end());
        int j=indi[st1];
        ans[j-1].push_back(st2);
    }
    return ans;
    }
};
