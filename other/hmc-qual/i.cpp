#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

struct Point {
    ll x, y;
    Point(ll x = 0, ll y = 0) {
        this->x = x;
        this->y = y;
    }
    inline void print() {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    bool operator<(Point p) {
        return y == p.y ? x < p.x : y < p.y;
    }

    Point operator+(Point p) {
        return Point(x + p.x, y + p.y);
    }

    Point operator-(Point p) {
        return Point(x - p.x, y - p.y);
    }
}

