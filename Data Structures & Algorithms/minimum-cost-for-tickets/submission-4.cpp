class Solution {
    int dfs(int day, int &mx_day, vector<int> &days, vector<int> &costs, vector<int> &dp){
        if(day > mx_day) return 0;

        if(dp[day] != -1) return dp[day];

        // if we have choosen the one day ticket then we have to go to the day that is greater or equal to day + no_of_choosen_days
        int one_day = costs[0];
        auto it1 = lower_bound(days.begin(), days.end(), day + 1);
        if(it1 != days.end()) one_day += dfs(*it1, mx_day, days, costs, dp);
        
        // now same for a week
        int one_week = costs[1];
        auto it2 = lower_bound(days.begin(), days.end(), day + 7);
        if(it2 != days.end()) one_week += dfs(*it2, mx_day, days, costs, dp);

        // now for a month
        int one_month = costs[2];
        auto it3 = lower_bound(days.begin(), days.end(), day + 30);
        if(it3 != days.end()) one_month += dfs(*it3, mx_day, days, costs, dp);
        
        return dp[day] = min({one_day, one_week, one_month});
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int start = days[0], mx_day = days.back();
        vector<int> dp(mx_day + 31, 0);
        vector<int> mp(mx_day + 1, 0);
        for(int i : days) mp[i]++;
        for(int day = mx_day; day >= start; day--){
            if(mp[day] == 0){
                dp[day] = dp[day + 1];
                continue;
            }

            // if we have choosen the one day ticket then we have to go to the day that is greater or equal to day + no_of_choosen_days
            int one_day = costs[0];
            one_day += dp[day + 1];
            
            // now same for a week
            int one_week = costs[1];
            one_week += dp[day + 7];

            // now for a month
            int one_month = costs[2];
            one_month += dp[day + 30];

            dp[day] = min({one_day, one_week, one_month});
        }
        return dp[start];
    }
};