#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

struct Sieve {
    int n;
    vector<int> isprime, prime;
    Sieve(int n) {
        this->n = n;
        isprime.resize(n, true);
        for (int i = 2; i < n; i++) {
            if (isprime[i]) {
                prime.push_back(i);
            }
            for (int j : prime) {
                if (1ll * i * j >= n)
                    break;
                isprime[i * j] = false;
                if (i % j == 0)
                    break;
            }
        }
    }
};

int main() {
    cin >> N;
    Sieve sieve(N + 1);
    int ans = 0;
    for (int i = 2; i <= N; i++) {
        if (i % 2 != 0 && i % 3 != 0 && i % 5 != 0 && !sieve.isprime[i])
            ans++;
    }
    cout << ans << endl;
}