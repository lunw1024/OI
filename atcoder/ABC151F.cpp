#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
typedef pair<double, double> P;

const int MAXN = 50;
const double EPS = 1e-8;
int N;
P arr[MAXN];

P operator+(const P& a, const P& b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

P operator-(const P& a, const P& b) {
    return make_pair(a.first - b.first, a.second - b.second);
}

P operator/(const P& a, double b) {
    return make_pair(a.first / b, a.second / b);
}

P operator*(const P& a, double b) {
    return make_pair(a.first * b, a.second * b);
}

double len(const P& a) {
    return sqrt(a.first * a.first + a.second * a.second);
}

bool check(double r) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            P a = arr[i], b = arr[j];
            P mid = (a + b) / 2;
            P h = (a - b);
            if (len(h) > 2 * r + EPS)
                continue;
            swap(h.first, h.second);
            h.second = -h.second;
            double x2 = h.first * h.first, y2 = h.second * h.second;
            h = h / len(h) * sqrt(r * r - x2 / 4 - y2 / 4);
            P c[2] = {mid + h, mid - h};
            for (int k = 0; k <= 1; k++) {
                bool flag = true;
                for (int l = 0; l < N; l++) {
                    if (len(arr[l] - c[k]) > r + EPS) {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i].first >> arr[i].second;

    double l = 0, r = 800;
    while (r - l > 1e-7) {
        double mid = (r + l) / 2;
        // cout << "check r = " << mid << endl;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << setiosflags(ios::fixed) << setprecision(8) << r << endl;
}