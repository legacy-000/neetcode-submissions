class Solution {
public:
    bool checkwell(string s){
        stack<char> st;
        unordered_map<char,char> mp = {
            {')','('},
            {']','['},
            {'}','{'}
        };

        for(char c : s){
            if(c=='(' || c=='[' || c=='{'){
                st.push(c);
            }
            else{
                if(st.empty() || st.top()!=mp[c])
                    return false;

                st.pop();
            }
        }

        return st.empty();
    }

    void genP(vector<string>& ans, string path, int count, int n){

        if(count==2*n){
            if(checkwell(path))
                ans.push_back(path);
            return;
        }

        path.push_back('(');
        genP(ans, path, count+1, n);
        path.pop_back();

        path.push_back(')');
        genP(ans, path, count+1, n);
        path.pop_back();
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;
        string path;

        genP(ans, path, 0, n);

        return ans;
    }
};