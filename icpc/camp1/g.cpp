#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C>& a) {
    int n = sz(a), L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R(2, 1);
    static vector<C> rt(2, 1); // (^ 10% f a s t e r i f double )
    for (static int k = 2; k < n; k *= 2) {
        R.resize(n); rt.resize(n);
        auto x = polar(1.0L, acos(-1.0L) / k);
        rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
    }
    vi rev(n);
    rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
            C z = rt[j+k] * a[i+j+k]; // (25% f a s t e r i f hand =r o l l e d )
            a[i + j + k] = a[i + j] - z;
            a[i + j] += z;
        }
}

vd conv(const vd& a, const vd& b) {
    if (a.empty() || b.empty()) return { } ;
    vd res(sz(a) + sz(b) - 1);
    int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
    vector<C> in(n), out(n);
    copy(all(a), begin(in));
    rep(i,0,sz(b)) in[i].imag(b[i]);
    fft(in);
    for (C& x : in) x *= x;
    rep(i,0,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
    fft(out);
    rep(i,0,sz(res)) res[i] = imag(out[i]) / (4 * n);
    return res;
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vi p(N + 1), q(Q);
    for (int i = 1; i <= N; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < Q; i++) {
        cin >> q[i];
    }

    map<int, vector<ll>> cycs; // components
    vector<bool> vis(N + 1);
    for (int i = 1; i <= N; i++) {
        // if not vis, add to new cyc
        // determine size
        // a = weights in cycle order
        // res = conv(a.R + pad, aa)
        if (vis[i]) {
            continue;
        }
        vector<int> nodes;
        nodes.push_back(i);
        vis[i] = true;
        int x = p[i];
        while (x != i) {
            vis[x] = true;
            nodes.push_back(x);
            x = p[x];
        }
        int n = nodes.size();
        vd a(2 * n), b(2 * n);
        for (int j = 0; j < n; j++) {
            a[j] = nodes[n - j - 1];
            b[j] = nodes[j];
            b[j + n] = nodes[j];
        }
        // cerr << "running FFT" << endl;
        vd res = conv(a, b);
        // for (double d : res) {
        //     cerr << d << " ";
        // }
        // cerr << endl;
        if (cycs.count(n) == 0) {
            cycs[n] = vector<ll>(n, 0);
        }
        for (int j = 0; j < n; j++) {
            cycs[n][j] += llround(res[n - 1 + j]);
        }
    }

    // cerr << "processing qs" << endl;

    // process qs
    for (int k : q) {
        ll ans = 0;
        for (const pair<const int, vector<ll>>& e : cycs) {
            ans += e.second[k % e.first];
        }
        cout << ans << endl;
    }
}
