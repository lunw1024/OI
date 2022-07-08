#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int N, K;

int main() {
    cin >> N >> K;
    multiset<int> r, s;
    int naive = 0, optimal = 0;
    for (int i = 0; i < K; i++) {
        r.insert(0);
        s.insert(0);
    }
    for (int i = 0; i < N; i++) {
        int t, l;
        cin >> t >> l;
        // naive
        if (*(r.begin()) <= t) {
            r.erase(r.begin());
            r.insert(t + l);
            naive++;
        }
        // optimal
        if (*(s.begin()) <= t) {
            s.erase(s.begin());
            s.insert(t + l);
            optimal++;
        } else if (*(s.rbegin()) > t + l) {
            s.erase(prev(s.end()));
            s.insert(t + l);
        }
        // cout << optimal << " - " << naive << endl;
        cout << optimal - naive << endl;
    }
}
