#include <atcoder/all>
#include <iostream>
using namespace atcoder;
using namespace std;

int main() {
    int N;
    string s;
    cin >> N >> s;
    vector<int> A(N + 1), G(N + 1), C(N + 1), T(N + 1);
    for (int i = 0; i < N; i++) {
        char ch = s[i];
        A[i + 1] = A[i];
        G[i + 1] = G[i];
        C[i + 1] = C[i];
        T[i + 1] = T[i]; 
        if (ch == 'A')
            A[i + 1]++;
        if (ch == 'G')
            G[i + 1]++;
        if (ch == 'C')
            C[i + 1]++;
        if (ch == 'T')
            T[i + 1]++;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (A[j] - A[i] == T[j] - T[i] && G[j] - G[i] == C[j] - C[i])
                ans++;
        }
    }
    cout << ans << endl;
}