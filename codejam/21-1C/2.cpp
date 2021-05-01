#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll INF = 1234567891011121314;
ll Y;
vector<ll> arr;

void preprocess() {
    for (int i = 1; i <= 999999; i++) {
        string s = to_string(i);
        for (int j = i + 1; s.size() <= 18; j++) {
            s += to_string(j);
            if (s.size() <= 18)
                arr.push_back(stoll(s));
        }
    }
    arr.push_back(1234567891011121314);
    sort(arr.begin(), arr.end());
}

ll two(ll y) {
    string s = to_string(y);
    if (s.size() <= 1)
        return INF;
    string s1 = s.substr(0, s.size() / 2), s2 = s.substr(s.size() / 2, s.size() - s.size() / 2);
    ll n1 = stoll(s1), n2 = stoll(s2);
    // cerr << s1 << " + " << s2 << " " << n1 << " " << n2 << endl;
    if (s1.size() == s2.size()) {
        if (n2 < n1 + 1) {
            return stoll(to_string(n1) + to_string(n1 + 1));
        } else {
            return stoll(to_string(n1 + 1) + to_string(n1 + 2));
        }
    } else if (s1.size() + 1 == s2.size()) {
        ll x = pow(10, s2.size() - 1);
        ll c1 = stoll(to_string(x - 1) + to_string(x));
        if (c1 > y) {
            return c1;
        }
        return stoll(to_string(x) + to_string(x + 1));
    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    preprocess();
    for (int t = 1; t <= T; t++) {
        cin >> Y;
        ll ans1 = *upper_bound(arr.begin(), arr.end(), Y);
        ll ans2 = two(Y);
        cout << "Case #" << t << ": " << min(ans1, ans2) << endl;
    }
}