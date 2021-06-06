#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        vector<char> v(N);
        for (int i = 0; i < N; i++) {
            cin >> v[i];
        }
        bool palin = true;
        int a = 0, b = 0;
        for (int i = 0; i < N; i++) {
            if (v[i] != v[N - i - 1])
                palin = false;
            if (v[i] == '0')
                a++;
            if (v[i] == '1' && v[N - i - 1] == '0')
                b++;
        }
        if (palin) {
            if (a == 1 || a % 2 == 0)
                cout << "BOB" << endl;
            else
                cout << "ALICE" << endl;
        } else {
            if (a == 2 && b == 1)
                cout << "DRAW" << endl;
            else
                cout << "ALICE" << endl;
        }

    }
}
