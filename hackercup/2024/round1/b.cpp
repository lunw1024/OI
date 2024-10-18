#include <iostream>
#include <vector>

using namespace std;

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
                if (1ll * i * j >= n) {
                    break;
                }
                isprime[i * j] = false;
                if (i % j == 0) {
                    break;
                }
            }
        }
    }
};

int main() {
    const int MAXN = 10000000;
    Sieve sieve(MAXN + 1); // up to N

    int T;
    cin >> T;
    for (int task = 1; task <= T; task++) {
        int N;
        cin >> N;
        int ans = 0;
        for (int i = 1; i < sieve.prime.size(); i++) {
            int p = sieve.prime[i];
            if (p > N) {
                break;
            }
            if (p - sieve.prime[i - 1] == 2) {
                ans++;
            }
        }
        if (N >= 5) {
            ans++; // 2
        }
        cout << "Case #" << task << ": " << ans << endl;
    }
    
}
