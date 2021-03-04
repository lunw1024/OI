#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll INF = 9223372036854775807ll;
int N;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, x, y);
    ll t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
}

int main() {
    int T;
    cin >> T;
    for (int caseNo = 0; caseNo < T; caseNo++) {
        ll X, Y, P, Q, ans = INF;
        cin >> X >> Y >> P >> Q;
        for (ll a = 0; a < Y; a++) {
            for (ll b = 0; b < Q; b++) {
                // solve (2X + 2Y)n - (P + Q)m == P + b - X - a
                ll n = 0, m = 0;
                ll rhs = P + b - X - a;
                ll gcd = exgcd(2*X + 2*Y, -P - Q, n, m);
                ll absgcd = abs(gcd);
                if (rhs % gcd != 0)
                    continue;
                n *= rhs / gcd;
                n = (n % ((P+Q)/absgcd) + ((P+Q)/absgcd)) % ((P+Q)/absgcd);
                ans = min(ans, (2*X + 2*Y) * n + X + a);
            }
        }
        if (ans == INF)
            cout << "infinity" << endl;
        else
            cout << ans << endl;
    }
}