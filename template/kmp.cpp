#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string a, b;
int prefix[(int)1e6 + 1];

void preprocess(string s) {
    int n = s.length();
    for (int i = 1; i < n; i++) {
        int j = prefix[i - 1];
        while (j > 0 && s[i] != s[j])
            j = prefix[j - 1];
        if (s[i] == s[j])
            j++;
        prefix[i] = j;
    }
}

int main() {
    cin >> a >> b;
    preprocess(b);
    int j = 0;
    for (int i = 0; i < a.length(); i++) {
        while (j > 0 && a[i] != b[j])
            j = prefix[j - 1];
        if (a[i] == b[j])
            j++;
        if (j == b.length()) {
            cout << "find occurence in " << i << endl;
            j = prefix[j - 1];
        }
    }
}