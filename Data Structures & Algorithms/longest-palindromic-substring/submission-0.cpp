class Solution {
public:
    bool ispal(const string &s) {
        int start = 0;
        int end = s.size() - 1;

        while (start < end) {
            if (s[start] != s[end])
                return false;

            start++;
            end--;
        }

        return true;
    }

    string largestpal(const string &s, int k) {
        for (int i = 0; i + k <= s.size(); i++) {
            string temp = s.substr(i, k);

            if (ispal(temp))
                return temp;
        }

        return "";
    }

    string longestPalindrome(string s) {
        int n = s.size();

        // Check lengths from largest to smallest
        for (int len = n; len >= 1; len--) {
            string res = largestpal(s, len);

            if (!res.empty())
                return res;
        }

        return "";
    }
};
