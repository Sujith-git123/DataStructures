class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> a;
        for(int b:nums){
            a[b]++;
            if(a[b]==n/2){
                return b;
            }
        }
        return -1;
    }
};
