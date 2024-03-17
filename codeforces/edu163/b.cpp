#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int m = int(1e9);
    bool ok = true;
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] <= m) {
        m = a[i];
      } else {
        if (a[i] >= 10 && a[i] / 10 <= a[i] % 10) {
          m = a[i] / 10;
        } else {
          ok = false;
        }
      }
    }
    cout << (ok ? "YES" : "NO") << endl;
  }  
}
