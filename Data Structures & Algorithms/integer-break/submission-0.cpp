class Solution {
    int dfs(int n, int &o, vector<int> &dp){
        if(n == 1) return 1;
        if(dp[n] != -1) return dp[n];
        int ans = (n == o)?0:n;
        for(int i=1;i<=(n/2);i++){
            int curr = dfs(i, o, dp) * dfs(n - i, o, dp);
            ans = max(ans, curr);
        }
        return dp[n] = ans;
    }
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, -1);
        dfs(n, n, dp);
        return dp[n];
    }
};