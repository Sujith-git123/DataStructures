#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    if (n < 2 * k) {
        cout << "1 1";
        return 0;
    }
    vector<long long> pre;
    long long s = 0;
    for (int i = 0; i < n; i++) {
        s += nums[i];
        if (i >= k) s -= nums[i - k];
        if (i >= k - 1) pre.push_back(s);
    }

    int m = pre.size(); 
    vector<int> bestIdx(m);
    bestIdx[m - 1] = m - 1;

    for (int i = m - 2; i >= 0; i--) {
        if (pre[i] >= pre[bestIdx[i + 1]])
            bestIdx[i] = i;
        else
            bestIdx[i] = bestIdx[i + 1];
    }

    long long bestSum = -1;
    int a = -1, b = -1;

    for (int i = 0; i + k < m; i++) {
        int j = bestIdx[i + k];
        long long cur = pre[i] + pre[j];
        if (cur > bestSum) {
            bestSum = cur;
            a = i;
            b = j;
        }
    }

    cout << a + 1 << " " << b + 1;
    return 0;
}
