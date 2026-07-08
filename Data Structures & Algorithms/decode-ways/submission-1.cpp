class Solution {
    unordered_map<string, int> mp;
    int dfs(int i, int &n, string &s, vector<int> &dp){
        if(i == n) return 1;
        // if(s[i] == '0') return 0;
        int ans = 0;
        if(dp[i] != -1) return dp[i];
        if(mp.count(s.substr(i, 1))) ans += dfs(i + 1, n, s, dp);
        if(i + 1 < n && mp.count(s.substr(i, 2))) ans += dfs(i + 2, n, s, dp);
        return dp[i] = ans;
    }
public:
    int numDecodings(string s) {
        mp = {{"1", 1}, {"2", 1}, {"3", 1}, {"4", 1}, {"5", 1},
              {"6", 1}, {"7", 1}, {"8", 1}, {"9", 1}, {"10", 1},
              {"11", 1}, {"12", 1}, {"13", 1}, {"14", 1}, {"15", 1},
              {"16", 1}, {"17", 1}, {"18", 1}, {"19", 1}, {"20", 1},
              {"21", 1}, {"22", 1}, {"23", 1}, {"24", 1}, {"25", 1}, {"26", 1}
        };
        int n = s.size();
        vector<int> dp(n + 1, 0);
        // here dp denotes number of ways to decode from index i to n
        dp[n] = 1;
        for(int i=n-1;i>=0;i--){
            if(mp.count(s.substr(i, 1))) dp[i] += dp[i + 1];
            if(i + 1 < n && mp.count(s.substr(i, 2))) dp[i] += dp[i + 2];
        }
        return dp[0];
    }
};
