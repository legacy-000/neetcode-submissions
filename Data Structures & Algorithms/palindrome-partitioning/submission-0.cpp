class Solution {
public:
    bool ispalindrome(string s,int left,int right){
        int i=0;
        int j=s.size()-1;
        while(left<=right){
            if(s[left++]!=s[right--]){
                return false;
            }
        }
        return true;
    }
    void pp(vector<vector<string>>& ans, vector<string> path, string s, int index){
        if(index==s.size()){
            ans.push_back(path);
            return;
        }
        for(int end=index;end<s.size();end++){
            if(ispalindrome(s,index,end)){
                path.push_back(s.substr(index,end-index+1));
                pp(ans,path,s,end+1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        pp(ans,path,s,0);
        return ans;
    }
};
