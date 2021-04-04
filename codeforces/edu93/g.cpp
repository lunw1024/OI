#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#include <cmath>
#include <complex>
using Complex = complex<double>;

int N;

void change(Complex a[], int len) {
    vector<int> rev(len);
    for (int i = 0; i < len; i++) {
        rev[i] = rev[i >> 1] >> 1;
        if (i & 1)
            rev[i] |= len >> 1;
    }
    for (int i = 0; i < len; i++) {
        if (i < rev[i])
            swap(a[i], a[rev[i]]);
    }
}

void fft(Complex a[], int len, int reverse) {
    change(a, len);
    for (int k = 2; k < len; k <<= 1) {
        Complex wn(cos())
    }
}

int main() {
    
}