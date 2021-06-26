#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

void count_sort(vector<int> &p, vector<int> &c) {
    int n = p.size();
    vector<int> cnt(n);
    for (int x : c) {
        cnt[x]++;
    }
    vector<int> np(n);
    vector<int> head(n);
    for (int i = 1; i < n; i++) {
        head[i] = head[i - 1] + cnt[i - 1];
    }
    for (int x : p) {
        np[head[c[x]]++] = x;
    }
    p = np;
}

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
        for (int i = 0; i < N; i++) {
            p[i] = (p[i] - (1 << k) + N) % N;
        }
        
        count_sort(p, c);

        vector<int> nc(N);
        nc[p[0]] = 0;
        for (int i = 1; i < N; i++) {
            pii x = {c[p[i]], c[(p[i] + (1 << k)) % N]}, y = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % N]};
            if (x == y) {
                nc[p[i]] = nc[p[i - 1]];
            } else {
                nc[p[i]] = nc[p[i - 1]] + 1;
            }
        }
        c = nc;
        k++;
    }
    
    for (int i = 0; i < N; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
}
