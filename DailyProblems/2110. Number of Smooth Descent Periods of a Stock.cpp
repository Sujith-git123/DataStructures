class Solution {
public:
    long long getDescentPeriods(vector<int>& nums) {
        int n=nums.size();
        int j=0;
        long long count=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]-nums[i+1]!=1){
                j=i+1;
            }
            count+=(i-j+1);
        }
        return count+n;
    }
};
