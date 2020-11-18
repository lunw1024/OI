#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;

int N;

int main() {
    int T;
    cin >> T;
    for (int caseNo = 1; caseNo <= T; caseNo++) {
        cin >> N;
        cout << (int)round(pow(2, N / 2)) * 2 - 2 << endl;
    }
    // system("pause");
}