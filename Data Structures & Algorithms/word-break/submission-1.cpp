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
        vector<int> dp(n + 1, -1);
        for(auto word : wordDict) mp[word]++;
        dfs(0, s, mp, dp);
        return (bool)dp[0];
    }
};
