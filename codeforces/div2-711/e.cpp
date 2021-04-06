#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

bool query(int x, int y) {
    cout << "? " << x << " " << y << endl;
    string s;
    cin >> s;
    return s == "Yes";
}

int main() {
    cin >> N;
    vector<int> K(N + 1);
    vector<pair<int, pii>> arr;
    for (int i = 1; i <= N; i++) {
        cin >> K[i];
    }
    for (int i = 1; i <= N - 1; i++) {
        for (int j = i + 1; j <= N; j++) {
            arr.push_back(make_pair(abs(K[i] - K[j]), make_pair(i, j)));
        }
    }
    sort(arr.begin(), arr.end(), greater<pair<int, pii>>());
    int ansx = 0, ansy = 0;
    for (auto e : arr) {
        int x = e.second.first, y = e.second.second;
        if (K[x] > K[y])
            swap(x, y);
        if (query(y, x)) {
            ansx = x, ansy = y;
            break;
        }
    }
    cout << "! " << ansx << " " << ansy << endl;
}