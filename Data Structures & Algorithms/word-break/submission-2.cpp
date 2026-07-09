class Solution {
    int dfs(int i, string &s, unordered_map<string, int> &mp, vector<int> &dp){
        if(i == s.size()) return dp[i] = 1;
        if(dp[i] != -1) return dp[i];
        for(int j=i;j<s.size();j++){
            string curr = s.substr(i, j-i+1);
            if(mp.count(curr)){
                if(dfs(j+1, s, mp, dp)) return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_map<string, int> mp;
        vector<bool> dp(n + 1, false);
        for(auto word : wordDict) mp[word]++;
        dp[n] = true;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++) {
                string curr = s.substr(i, j-i+1);
                if(mp.count(curr)) dp[i] = dp[j+1] | dp[i];
            }
        }
        return (bool)dp[0];
    }
};
