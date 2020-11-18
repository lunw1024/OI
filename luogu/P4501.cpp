#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = (int)2e5 + 1, MAXK = (int)2e5 + 1;
int N, M, K, log[MAXK];
int arr[MAXN], dist[MAXK];
int st1[MAXK][18], st2[MAXK][18], idx[MAXK];
vector<int> sources;

void st_init() {
    sort(sources.begin(), sources.end());
    for (int i = 1; i <= K; i++) {
        idx[sources[i]] = i;
        st1[i][0] = dist[sources[i]] - arr[sources[i]];
        st2[i][0] = dist[sources[i]] - (arr[N] - arr[sources[i]]);
    }
    for (int k = 1; k <= log[K]; k++) {
        for (int i = 1; i <= K; i++) {
            st1[i][k] = min(st1[i][k - 1], st1[i + (1<<k-1)][k - 1]);
            st2[i][k] = min(st2[i][k - 1], st2[i + (1<<k-1)][k - 1]);
        }
    }
}

int queryl(int pos, int rad) {
    int len = rad * 2 + 1;
    return st1[]
}

int solve() {
    st_init();
    for (int i = 1; i <= K; i++) {
        // left
        int l = 1, r = sources[i];
        while (l <= r) {
            int mid = (l + r) / 2;
            int rad = sources[i] - mid - 1;
            if (queryl(mid, rad) < dist[sources[i]] + sources[i] - mid) {

            }
        }
        // right
    }
}

int main() {
    cin >> N >> M;

    // log[]
    for (int i = 0; i <= 17; i++)
        log[1<<i] = i;
    for (int i = 1; i < MAXK; i++)
        if (log[i] == 0)
            log[i] = log[i - 1];

    // input   
    for (int i = 2; i <= N; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    for (int i = 1; i <= M; i++) {
        cin >> K;
        for (int j = 1; j <= K; j++) {
            int p, l;
            cin >> p >> l;
            dist[p] = l; // only sources are meaningful
            sources.push_back(p);
        }
        cout << solve() << endl;
    }
}