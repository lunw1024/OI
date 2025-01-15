#include <iostream>
#include <vector>
#include <set>
using namespace std;

template<class T> int sgn(T x) {
    return (x > 0) - (x < 0);
}

template<class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
    bool operator<(const P p) const {
        return tie(x, y) < tie(p.x, p.y);
    }
    bool operator==(P p) const {
        return tie(x, y) == tie(p.x, p.y);
    }
    P operator+ (P p) const {
        return P(x + p.x, y + p.y);
    }
    P operator- (P p) const {
        return P(x - p.x, y - p.y);
    }
    P operator* (T d) const {
        return P(x * d, y * d);
    }
    P operator/ (T d) const {
        return P(x / d, y / d);
    }
    T dot(P p) const {
        return x * p.x + y * p.y;
    }
    T cross(P p) const {
        return x * p.y - y * p.x;
    }
    T cross(P a, P b) const {
        return (a-*this).cross(b-*this);
    }
};

template<class P> bool onSegment(P s, P e, P p) {
    return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

template<class P> vector<P> segInter(P a, P b, P c, P d) {
    auto oa = c.cross(d, a), ob = c.cross(d, b), oc = a.cross(b, c), od = a.cross(b, d);
    if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0) {
        return {(a * ob - b * oa) / (ob - oa)};
    }
    set<P> s;
    if (onSegment<Point<double>>(c, d, a)) s.insert(a);
    if (onSegment<Point<double>>(c, d, b)) s.insert(b);
    if (onSegment<Point<double>>(a, b, c)) s.insert(c);
    if (onSegment<Point<double>>(a, b, d)) s.insert(d);
    return {begin(s), end(s)};
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        double x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        Point<double> a(x1, y1), b(x2, y2), c(x3, y3), d(x4, y4);
        vector<Point<double>> result = segInter<Point<double>>(a, b, c, d);
        cout << (result.empty() ? "NO" : "YES") << endl;
    }
}
