class Solution {
public:
    long long maximumHappinessSum(vector<int>& nums, int k) {
        long long s=0;
        sort(nums.rbegin(),nums.rend());
        for(int i=0;i<k;i++){
            s+=(nums[i]-i>=0)?nums[i]-i:0;
        }
        return s;
    }
};
