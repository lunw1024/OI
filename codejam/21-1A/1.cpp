#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

vector<int> tovec(ll x) {
    vector<int> ret;
    while (x > 0) {
        ret.push_back(x % 10);
        x /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

void addone(vector<int>& v) {
    reverse(v.begin(), v.end());
    v[0] += 1;
    for (int i = 0; i < v.size() - 1; i++) {
        v[i + 1] += v[0] / 10;
        v[0] %= 10;
    }
    if (v.back() >= 10) {
        v.push_back(v.back() / 10);
        v[v.size() - 2] %= 10;
    }
    reverse(v.begin(), v.end());
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        int ans = 0;
        vector<int> prev, x;
        for (int i = 0; i < N; i++) {
            ll temp;
            cin >> temp;
            x = tovec(temp);
            bool small = false, big = x.size() > prev.size();
            for (int j = 0; !big && j < min(x.size(), prev.size()); j++) {
                if (x[j] > prev[j]) {
                    big = true;
                    break;
                }
                if (x[j] < prev[j]) {
                    small = true;
                    break;
                }
            }
            if (small) {
                while (x.size() <= prev.size())
                    x.push_back(0), ans++;
            } else if (big) {
                while (x.size() < prev.size())
                    x.push_back(0), ans++;
            } else {
                for (int j = x.size(); j < prev.size(); j++) {
                    x.push_back(prev[j]), ans++;
                }
            }

            prev = x;
            addone(prev);
            for (int i : x) {
                cerr << i;
            }
            cerr << " ";
        }
        cerr << endl;
        cout << "Case #" << t << ": " << ans << endl;
    }
}