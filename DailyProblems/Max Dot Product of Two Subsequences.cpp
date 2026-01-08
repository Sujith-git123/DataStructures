class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1e6));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                dp[i][j]=max({dp[i][j],nums1[i]*nums2[j],nums1[i]*nums2[j]+dp[i+1][j+1],dp[i+1][j],dp[i][j+1]});
            }
        }
        return dp[0][0];
    }
};
