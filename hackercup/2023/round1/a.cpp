#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ifstream fin("data/here_comes_santa_claus_input.txt");
ofstream fout("data/out.txt");

int main() {
    ios::sync_with_stdio(false); fin.tie(0);
    int T;
    fin >> T;
    for (int t = 1; t <= T; t++) {
        fin >> N;
        vector<ll> a(N);
        for (int i = 0; i < N; i++) {
            fin >> a[i];
        }
        sort(a.begin(), a.end());
        double ans = 0;
        if (N == 5) {
            ans = double(max(a[4] + a[3] - a[2] - a[0], a[4] + a[2] - a[1] - a[0])) / 2;
        } else {
            ans = double(a[N - 1] + a[N - 2] - a[0] - a[1]) / 2.0;
        }
        fout << fixed << setprecision(8) << "Case #" << t << ": " << ans << endl;
    }
}
