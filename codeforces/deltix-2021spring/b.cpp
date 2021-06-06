#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; i++)
            cin >> a[i];
        cout << N / 2 * 6 << endl;
        for (int i = 1; i <= N; i += 2) {
            cout << "1 " << i << " " << i + 1 << endl;
            cout << "2 " << i << " " << i + 1 << endl;
            cout << "2 " << i << " " << i + 1 << endl;
            cout << "1 " << i << " " << i + 1 << endl;
            cout << "2 " << i << " " << i + 1 << endl;
            cout << "2 " << i << " " << i + 1 << endl;
        }
    }
}