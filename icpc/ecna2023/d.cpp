#include <iostream>
#include <vector>
using namespace std;

int main() {
    int s = 0;
    for (int i = 0; i < 5; i++) {
        int a, l;
        cin >> a >> l;
        s += a * l;
    }
    s /= 5;
    int a, b;
    cin >> a >> b;
    int ans = s * a / b;
    cout << ans << endl;
}
