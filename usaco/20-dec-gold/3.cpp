#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;

int N;
vector<pii> pts;

bool comp(pii a, pii b) {
    return a.second < b.second;
}

int solve(bool transposed) {
    int res = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            vector<pii> arr;
            int x1 = pts[i].first, y1 = pts[i].second;
            int x2 = pts[j].first, y2 = pts[j].second;
            int len = x2 - x1 + 1;
            int ymax = min(y1, y2), ymin = max(y1, y2) - len + 1;

            if (ymax < ymin)
                continue;
            if (transposed && ymin == ymax) // not necessary, won't hurt
                continue;

            for (int k = 0; k < N; k++) {
                int xk = pts[k].first, yk = pts[k].second;
                if (x1 <= xk && xk <= x2 && ymin <= yk && yk < ymax + len)
                    arr.push_back(pts[k]);
            }
            sort(arr.begin(), arr.end(), comp);
            int l = 0, r = 0;
            int y = ymin;
            while (y <= ymax) {
                while (r + 1 < arr.size() && arr[r + 1].second <= y + len - 1)
                    r++;
                while (arr[l].second < y)
                    l++;
                if (transposed && arr[r].second - arr[l].second + 1 == len)
                    res--;
                res++;

                if (r + 1 < arr.size())
                    y = min(arr[l].second + 1, arr[r + 1].second - len + 1);
                else
                    y = arr[l].second + 1;
            }
        }
    }
    return res;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        pts.push_back(make_pair(x, y));
    }

    int ans = 1; // empty
    sort(pts.begin(), pts.end());
    ans += solve(false);
    for (int i = 0; i < N; i++)
        pts[i] = make_pair(pts[i].second, pts[i].first);
    sort(pts.begin(), pts.end());
    ans += solve(true);

    cout << ans << endl;
}

