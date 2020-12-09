#include <atcoder/all>
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
using namespace atcoder;

using pii = pair<int, int>;

double dist(pii a, pii b) {
    return sqrt((double)(a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int main() {
    int N;
    cin >> N;
    vector<pii> nails;
    for (int i = 1; i <= N; i++) {
        int x, y;
        cin >> x >> y;
        nails.push_back(make_pair(x, y));
    }
    vector<pair<double, pii>> allEdges;
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            allEdges.push_back(make_pair(dist(nails[i - 1], nails[j - 1]), make_pair(i, j)));
        }
        allEdges.push_back(make_pair(100 - nails[i - 1].second, make_pair(0, i)));
        allEdges.push_back(make_pair(nails[i - 1].second + 100, make_pair(i, N + 1)));
    }
    allEdges.push_back(make_pair(200, make_pair(0, N + 1)));
    sort(allEdges.begin(), allEdges.end());
    dsu d(N + 2);
    double ans = 0;
    for (pair<double, pii> e : allEdges) {
        double dis = e.first;
        int x = e.second.first, y = e.second.second;
        d.merge(x, y);
        ans = dis / 2;
        if (d.same(0, N + 1)) {
            break;
        }
    }
    cout << setprecision(8) << ans << endl;
}