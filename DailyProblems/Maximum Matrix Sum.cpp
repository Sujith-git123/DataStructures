class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans=0;
        int mi=INT_MAX,c=0;
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans+=abs(matrix[i][j]);
                if(matrix[i][j]<0)c++;
                mi=min(mi,abs(matrix[i][j]));
            }
        }
        if(c&1){
            ans-=2*mi;
        }
        return ans;
    }
};
