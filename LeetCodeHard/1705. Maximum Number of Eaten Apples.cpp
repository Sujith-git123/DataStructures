class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size();
        int count = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (int i = 0; i < n; i++) {
            while (!pq.empty() && pq.top().first <= i)
                pq.pop();
            if (apples[i] != 0) {
                int ex = i + days[i];
                pq.push({ex, apples[i]});
            }
            if (pq.empty())
                continue;
            int app = pq.top().second;
            int d = pq.top().first;
            count++;
            app--;
            pq.pop();
            if (app != 0) {
                pq.push({d, app});
            }
        }
        int day = n;
        while (!pq.empty()) {
            while (!pq.empty() && pq.top().first <= day)
                pq.pop();
            if (pq.empty())
                continue;
            int app = pq.top().second;
            int d = pq.top().first;
            count++;
            app--;
            pq.pop();
            if (app != 0) {
                pq.push({d, app});
            }
            day++;
        }
        return count;
    }
};
