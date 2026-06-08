class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        int maxi = 1;
        int start = 0;

        for(int i = 0; i < n - 1; i++) {
            if(s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
                maxi = 2;
                start = i;
            }
        }

        for(int len = 3; len <= n; len++) {
            for(int j = 0; j <= n - len; j++) {

                if(dp[j + 1][j + len - 2] &&
                   s[j] == s[j + len - 1]) {

                    dp[j][j + len - 1] = 1;

                    if(len > maxi) {
                        maxi = len;
                        start = j;
                    }
                }
            }
        }

        return s.substr(start, maxi);
    }
};