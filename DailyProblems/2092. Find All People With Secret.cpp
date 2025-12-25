class Solution {
    class DSU {
        vector<int> parent, size;
    public:
        DSU(int n) {
            parent.resize(n);
            size.resize(n, 1);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
        int find(int u) {
            if (parent[u] == u) {
                return u;
            }
            return parent[u] = find(parent[u]);
        }
        void Union(int u, int v) {
            int u_p = find(u);
            int v_p = find(v);
            if (u_p == v_p)
                return;
            if (size[u_p] < size[v_p]) {
                parent[u_p] = v_p;
                size[v_p] += size[u_p];
            } else {
                parent[v_p] = u_p;
                size[u_p] += size[v_p];
            }
        }
        bool connected(int u, int v) { return find(u) == find(v); }
        void reset(int u) {
            parent[u] = u;
            size[u] = 1;
        }
    };

public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {
        DSU dsu(n);
        dsu.Union(0, firstPerson);
        sort(meetings.begin(), meetings.end(),
             [&](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });
        for (int i = 0; i < meetings.size(); i++) {
            int t = meetings[i][2];
            vector<int> people;
            int j = i;
            while (j < meetings.size() && meetings[j][2] == t) {
                dsu.Union(meetings[j][0], meetings[j][1]);
                people.push_back(meetings[j][0]);
                people.push_back(meetings[j][1]);
                j++;
            }
            for (int p : people) {
                if (!dsu.connected(0, p)) {
                    dsu.reset(p);
                }
            }
            i = j-1;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (dsu.connected(0, i))
                ans.push_back(i);
        }
        return ans;
    }
};
