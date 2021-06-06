#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

int main() {
    string s;
    cin >> s;
    s += "$";
    N = s.size();
    vector<int> p(N), c(N);
    vector<pair<char, int>> a(N);
    for (int i = 0; i < N; i++) {
        a[i] = make_pair(s[i], i);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < N; i++) {
        p[i] = a[i].second;
    }
    c[p[0]] = 0;
    for (int i = 1; i < N; i++) {
        if (a[i].first == a[i - 1].first) {
            c[p[i]] = c[p[i - 1]];
        } else {
            c[p[i]] = c[p[i - 1]] + 1;
        }
    }
    int k = 0;
    while ((1 << k) < N) {
        vector<pair<pii, int>> a(N);
        for (int i = 0; i < N; i++) {
            a[i] = make_pair(make_pair(c[i], c[(i + (1 << k)) % N]), i);
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < N; i++) {
            p[i] = a[i].second;
        }
        c[p[0]] = 0;
        for (int i = 1; i < N; i++) {
            if (a[i].first == a[i - 1].first) {
                c[p[i]] = c[p[i - 1]];
            } else {
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
        k++;
    }
    
    for (int i = 0; i < N; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
}
