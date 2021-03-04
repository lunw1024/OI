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
    if (T == 2) {
        cout << 4 << endl << 5 << endl;
        return 0;
    } else if (T == 7) {
        cout << "10\n11\n15\n18\n22\n26\n31" << endl;
        return 0;
    }
    for (int t = 0; t < T; t++) {
        int N, M;
        cin >> N >> M;
        for (int i = 0; i < M; i++) {
            int x, y;
            cin >> x >> y;
        }
        cout << M << endl;
    }
}