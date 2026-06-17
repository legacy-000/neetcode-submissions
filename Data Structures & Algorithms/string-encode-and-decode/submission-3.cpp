class Solution {
public:

    string encode(vector<string>& strs) {
        string str="";
        for(int i=0;i<strs.size();i++){
            str+=strs[i];
            str+='`';
        }
        return str;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        string st="";
        for(char c: s){
            if(c=='`'){
                strs.push_back(st);
                st="";
            }else{
                st+=c;
            }
        }
        return strs;
    }
};
