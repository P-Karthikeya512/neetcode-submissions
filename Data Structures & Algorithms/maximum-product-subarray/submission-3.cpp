class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN, n = nums.size();
        int curMax = 1, curMin = 1;
        for(int i=0;i<n;i++){
            if(nums[i] == 0) {
                curMax = 1;
                curMin = 1;
            }
            int temp = curMax * nums[i];
            curMax = max({temp, nums[i] * curMin, nums[i]});
            curMin = min({temp, nums[i] * curMin, nums[i]});
            ans = max(curMax, ans);
        }
        return ans;
    }
};
