#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct BIT {
    vector<int> data;
    BIT(int size) {
        data.resize(size);
    }
    inline int lowbit(int x) {
        return x & -x;
    }
    int query(int x) {
        int out = 0;
        while (x > 0) {
            out += data[x];
            x -= lowbit(x);
        }
        return out;
    }
    void add(int x, int k) {
        while (x < data.size()) {
            data[x] += k;
            x += lowbit(x);
        }
    }
};

bool comp(pii a, pii b) {
    return a.second < b.second;
}

bool comp2(pair<int, pii> a, pair<int, pii> b) {
    return a.second.second < b.second.second;
}

int N, Q;
vector<int> arr;

int main() {
    cin >> N >> Q;
    arr.resize(N + 2);
    stack<pii> vis;
    vector<pii> intervals; 
    vis.push(make_pair(0, 0));
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        while (vis.top().second > arr[i]) {
            vis.pop();
        }
        if (vis.top().second == arr[i]) {
            intervals.push_back(make_pair(vis.top().first, i));
            vis.pop();
        }
        vis.push(make_pair(i, arr[i]));
    }

    // 2D partial order, offline
    vector<pair<int, pii>> queries;
    vector<int> ans(Q);
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        queries.push_back(make_pair(i, make_pair(l, r)));
    }
    sort(intervals.begin(), intervals.end(), comp);
    sort(queries.begin(), queries.end(), comp2);
    BIT sum(N + 2);
    int p = 0;
    for (int i = 0; i < Q; i++) {
        pii q = queries[i].second;
        while (p < intervals.size() && intervals[p].second <= q.second) {
            sum.add(intervals[p].first, 1);
            p++;
        }
        ans[queries[i].first] = (q.second - q.first + 1) - (sum.query(q.second) - sum.query(q.first - 1));
    }
    for (int i = 0; i < Q; i++) {
        cout << ans[i] << endl;
    }
}