#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, A, B, C;

int main() {
    int T;
    cin >> T;
    for (int caseNo = 1; caseNo <= T; caseNo++) {
        cin >> N >> A >> B >> C;
        cout << "Case #" << caseNo << ": ";
        if (A + B - C > N || N > 1 && A == 1 && B == 1) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        vector<int> v;
        A -= C, B -= C;
        for (int i = 0; i < A; i++)
            v.push_back(N - 1);
        for (int i = 0; i < C; i++)
            v.push_back(N);
        for (int i = 0; i < B; i++)
            v.push_back(N - 1);
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
            if (i == 0) {
                for (int i = 0; i < N - A - B - C; i++)
                    cout << N - 2 << " ";
            }
        }
        cout << endl;
    }
}