#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int MAXN = (int)1e6 + 1, MOD = (int)1e9 + 7;
int N;
int last[MAXN] = {0}, num[MAXN] = {0};
P arr[MAXN];
int a[MAXN];
int c[MAXN];

inline int lowbit(int x) {
    return x & (-x); 
}

void add(int x, int k) {
  while (x <= N) {
    c[x] = c[x] + k;
    x = x + lowbit(x);
  }
}

int getsum(int x) {
  int ans = 0;
  while (x >= 1) {
    ans = ans + c[x];
    x = x - lowbit(x);
  }
  return ans;
}

ifstream fin("sequence.in");
ofstream fout("sequence.out");
int main()
{
    fin >> N;
    for (int i = 1; i <= N; i++) {
        fin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr + 1, arr + 1 + N);
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (i == 1 || arr[i].first != arr[i - 1].first)
            cnt++;
        a[arr[i].second] = cnt;
    }
    for (int i = 1; i <= N; i++) {
        if (last[a[i]] > 0) {
            add(last[a[i]], -1);
        }
        last[a[i]] = i;
        add(i, 1);

        for (int j = 1; i - j >= 0; j++) {
            int k = getsum(i) - getsum(i - j);
            num[k]++; // number of intervals of value k
            num[k] %= MOD;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += 1ll * num[i] * i * i % MOD;
    }
    fout << ans << endl;
    // system("pause");s
}
