class Solution {
public:
    void combi(vector<string>& ans,string st, vector<string> p, int row, int n){
        if(n==0){
            st.pop_back();
            return;
        }
        if(row>n){
            return;
        }
        if(st.size()==n){
            ans.push_back(st);
            return;
        } 
        for(int i=0;i<p[row].size();i++){
            st.push_back(p[row][i]);
            combi(ans,st,p,row+1,n);
            st.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mpp={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        vector<string> p;
        for(auto ch:digits){
            p.push_back(mpp[ch]);
        }
        vector<string> ans;
        int n=digits.size();      
        string st;
        combi(ans,st,p,0,n);
        return ans;
    }
};
