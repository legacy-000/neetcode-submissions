class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        int ns=s.size();
        int nt=t.size();
        sort(t.begin(),t.end());
        sort(s.begin(),s.end());
        if(s==t){
            return true;
        }
        else{
            return false;
        }

    }
};

