#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

// euler sieve to find nth prime
struct Sieve {
    vector<int> isprime, prime, grundy;
    int n;
    Sieve(int n) {
        this->n = n;
        isprime.resize(n, true);
        grundy.resize(n);
        grundy[0] = 0;
        grundy[1] = 1;
        for (int i = 2; i < n; i++) {
            if (isprime[i]) {
                prime.push_back(i);
                grundy[i] = i == 2 ? 0 : int(prime.size());
            }
            for (int j : prime) {
                if (ll(i * j) >= n) {
                    break;
                }
                isprime[i * j] = false;
                grundy[i * j] = grundy[j];
                if (i % j == 0) {
                    break;
                }
            }
        }
    }
};


int main() {
    int T;
    cin >> T;
    Sieve sieve = Sieve(int(1e7) + 1);
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        int g = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            g = g ^ sieve.grundy[x];
        }
        cout << (g == 0 ? "Bob" : "Alice") << endl;
    }
}
