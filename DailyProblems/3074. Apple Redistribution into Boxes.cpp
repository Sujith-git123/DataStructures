class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(),capacity.rend());
        int s=accumulate(apple.begin(),apple.end(),0);
        int ans=0;
        int c=0;
        for(int a:capacity){
            c+=a;
            ans++;
            if(c>=s){
                return ans;
            }
        }
        return ans;
    }
};
