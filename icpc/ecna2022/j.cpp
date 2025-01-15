#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<char, char>> check(vector<pair<char, char>> v) {
    vector<pair<char, char>> out;
    for (int i = v.size() - 1; i >= 3; i--) {
        if (v[i].first == v[i - 3].first) {
            for (int j = 0; j < i - 3; j++) {
                out.push_back(v[j]);
            }
            for (int j = i + 1; j < v.size(); j++) {
                out.push_back(v[j]);
            }
            return out;
        }
    }
    for (int i = v.size() - 1; i >= 3; i--) {
        if (v[i].second == v[i - 3].second) {
            for (int j = 0; j < i - 3; j++) {
                out.push_back(v[j]);
            }
            for (int j = i - 2; j < i; j++) {
                out.push_back(v[j]);
            }
            for (int j = i + 1; j < v.size(); j++) {
                out.push_back(v[j]);
            }
            return out;
        }
    }
    return v;
}

int main() {
    vector<pair<char, char>> v;
    for (int t = 0; t < 52; t++) {
        char a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
        // check
        while (true) {
            vector<pair<char, char>> v_ = check(v);
            if (v_.size() == v.size()) {
                break;
            }
            swap(v_, v);
        }
    }
    cout << v.size() << " ";
    for (pair<char, char> e : v) {
        cout << e.first << e.second << " ";
    }
    cout << endl;
}
