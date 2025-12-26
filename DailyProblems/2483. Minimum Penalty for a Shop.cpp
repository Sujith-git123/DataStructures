class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        vector<int> pre(n+1,0);
        vector<int> suf(n+1,0);
        for(int i=1;i<=n;++i){
            pre[i]=pre[i-1]+(customers[i-1]=='N');
        }
        for(int i=n-1;i>=0;--i){
            suf[i]=suf[i+1]+(customers[i]=='Y');
        }
        int pen=INT_MAX;
        int besthour;
        for(int i=0;i<=n;i++){
            if(pre[i]+suf[i]<pen){
                pen=pre[i]+suf[i];
                besthour=i;
            }
        }
        return besthour;
    }
};
