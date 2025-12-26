class Solution {
public:
    int stoneGameVIII(vector<int>& nums) {
        int n=nums.size();
        vector<long long> pre(n+1);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        vector<long long> dp(n,0);
        dp[n-2]=pre[n-1];
        for(int i=n-3;i>=0;i--){
            dp[i]=max(dp[i+1],pre[i+1]-dp[i+1]);
        }
        return dp[0];
    }
};
