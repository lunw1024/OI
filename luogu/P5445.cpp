#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = (int)3e5 + 1;
int N, Q;

struct BIT {
    int data[MAXN];
    inline int lowbit(int x) {
        return x & -x;
    }
    int query(int x) {
        int out = 0;
        while (x > 0) {
            x += out;
            x -= lowbit(x);
        }
    }
    void add(int x, int k) {
        while (x <= N) {
            data[x] += k;
            x += lowbit(x);
        }
    }
};

struct Node {
    int l, r, v, q = 0;
    Node(int l, int r, int v, int q = 0) {
        this->l = l;
        this->r = r;
        this->q = q;
    }
};

BIT bit;
set<pii> st;

int main() {
    cin >> N >> Q;
    int temp = 0;
    for (int i = 1; i <= N; i++) {
        char ch;
        cin >> ch;
        if (ch == '0') {
            if (temp != 0)
                st.insert(make_pair(temp, i - 1));
            temp = 0;
        } else {
            if (temp == 0)
                temp = i;
        }
    }

    for (int i = 1; i <= Q; i++) {
        string type;
        cin >> type;
        if (type == "toggle") {
            int x;
            cin >> x;
            auto it = st.lower_bound(make_pair(x, x));
            pii a = make_pair(0, 0), b = *it;
            if (it != st.begin()) {
                it--;
                a = *it;
            }
            if (a.first <= x && x <= a.second) {
                st.erase(a);

            }
        }
    }
}