#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

ifstream fin("data/sum_41_chapter_1_input.txt");
ofstream fout("data/out.txt");
int main() {
    ios::sync_with_stdio(false); fin.tie(0);
    int T;
    fin >> T;
    for (int t = 1; t <= T; t++) {
        int P;
        fin >> P;
        for (int m = 41; m >= 2; m--) {
            int x = P;
            vector<int> a;
            int sum = 0;
            for (int i = m; i >= 2; i--) {
                while (P % i == 0) {
                    a.push_back(i);
                    P /= i;
                }
            }
        }
        for (int i = 2; i * i <= P; i++) {
            while (P % i == 0) {
                a.push_back(i);
                P /= i;
                sum += i;
            }
        }
        if (P > 1) {
            a.push_back(P);
            sum += P;
        }
        
        if (sum > 41) {
            fout << "Case #" << t << ": ";
            fout << -1 << endl;
        } else {
            for (int i = 0; i < 41 - sum; i++) {
                a.push_back(1);
            }
            fout << "Case #" << t << ": " << a.size() << " ";
            for (int x : a) {
                fout << x << " ";
            }
            fout << endl;
        }
    }
}
