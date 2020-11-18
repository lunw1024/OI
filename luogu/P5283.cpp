#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

int N, K;
int trie[32 * 5 * (int)1e5][2], size[32 * 5 * (int)1e5], cnt = 0;
priority_queue<pair<ll, int> > heap;
ll arr[5 * (int)1e5 + 1];
int nth[5 * (int)1e5 + 1];

void insert(ll x) {
    int p = 0;
    for (int i = 31; i >= 0; i--) {
        if (trie[p][(x>>i) & 1] > 0)
            p = trie[p][(x>>i) & 1];
        else
            p = trie[p][(x>>i) & 1] = ++cnt;
        size[p] += 1; // size of subtree
    }
}

// kth largest in trie
ll query(ll x, int k) {
    ll out = 0;
    int p = 0;
    for (int i = 31; i >= 0; i--) {
        int big = (x>>i) & 1 ^ 1;
        // cout << p << " size-big: " << trie[p][big] << endl;
        if (size[trie[p][big]] >= k) {
            p = trie[p][big];
            out += 1ll << i;
        }
        else {
            k -= size[trie[p][big]];
            p = trie[p][big ^ 1];
        }
    }
    return out;
}

int main() {
    cin >> N >> K;
    insert(0ll);
    for (int i = 1; i <= N; i++) {
        ll temp;
        cin >> temp;
        arr[i] = arr[i - 1] ^ temp;
        // cout << "insert " << arr[i] << endl;
        insert(arr[i]);
    }
    for (int i = 0; i <= N; i++) {
        heap.push(make_pair(query(arr[i], 1), i));
        nth[i] = 1;
        // cout << "push heap " << query(arr[i], 1) << endl;
    }
    ll ans = 0;
    for (int i = 0; i < 2 * K; i++) {
        int idx = heap.top().second;
        ans += heap.top().first;
        heap.pop();
        if (nth[idx] < N)
            heap.push(make_pair(query(arr[idx], ++nth[idx]), idx));
    }
    if (ans % 2 == 1)
        while (true);
    cout << ans / 2 << endl;
}
