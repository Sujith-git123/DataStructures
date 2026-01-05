class DSU{
    public:
    vector<int> parent,size;
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }  
    }
    int find(int u){
            if(parent[u]==u){
                return u;
            }
            return parent[u]=find(parent[u]);
        }
        void Union(int u,int v){
            int up=find(u);
            int vp=find(v);
            if(up==vp)return ;
            if(size[up]<size[vp]){
                parent[up]=vp;
                size[vp]+=size[up];
            }
            else{
                parent[vp]=up;
                size[up]+=size[vp];
            }
        }
        int get(int u){
            return size[u];
        }
};
class Solution {
public:
    int valid(int n,int r,int c){
        return (r>=0 && r<n && c>=0 && c<n);
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DSU dsu(n*n);
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)continue;
                for(int k=0;k<4;k++){
                    int nr=i+dr[k];
                    int nc=j+dc[k];
                    if(valid(n,nr,nc) && grid[nr][nc]==1){
                        int node=i*n+j;
                        int adjnode=nr*n+nc;
                        dsu.Union(node,adjnode);
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)continue;
                set<int> c;
                for(int k=0;k<4;k++){
                    int nr=i+dr[k];
                    int nc=j+dc[k];
                    if(valid(n,nr,nc)){
                        if(grid[nr][nc]==1)c.insert(dsu.find(nr*n+nc));
                    }
                }
                int t=0;
                for(int a:c){
                    t+=(dsu.get(a));
                }
                ans=max(ans,t+1);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,dsu.get(i*n+j));
            }
        }
        return ans;
    }
};
