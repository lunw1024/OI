#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <complex>
#include <cmath>

using namespace std;

typedef complex<double> Complex;

const double PI = acos(-1.0);

void butterfly(Complex y[], int len)
{
    int i, j, k;
    for (int i = 1, j = len / 2; i < len - 1; i++)
    {
        if (i < j)
            swap(y[i], y[j]);
        k = len / 2;
        while (j >= k)
        {
            j = j - k;
            k = k / 2;
        }
        if (j < k)
            j += k;
    }
}

void FFT(Complex y[], int len, int mode)
{
    butterfly(y, len);
    for (int h = 2; h <= len; h <<= 1)
    {
        Complex wn(cos(2 * PI / h), sin(mode * 2 * PI / h));
        for (int j = 0; j < len; j += h)
        {
            Complex w(1, 0);
            for (int k = j; k < j + h / 2; k++)
            {
                Complex u = y[k];
                Complex v = w * y[k + h / 2];
                y[k] = u + v;
                y[k + h / 2] = u - v;
                w = w * wn;
            }
        }
    }
    if (mode == -1)
    {
        for (int i = 0; i < len; i++)
        {
            y[i].real(y[i].real() / len);
        }
    }
}

Complex a[2097152], b[2097152];
int sum[2097152] = {0};
string s1, s2;
int main()
{
    cin >> s1 >> s2;
    int lena = s1.size(), lenb = s2.size();
    for (int i = 0; i < lena; i++)
    {
        a[i] = Complex(s1[lena - i - 1] - '0', 0);
    }
    for (int i = 0; i < lenb; i++)
    {
        b[i] = Complex(s2[lenb - i - 1] - '0', 0);
    }

    int len = 1;
    while (len < lena * 2 || len < lenb * 2)
    {
        len <<= 1;
    }
    // for (int i = lena; i < len; i++)
    // {
    //     a[i] = Complex(0, 0);
    // }
    // for (int i = lenb; i < len; i++)
    // {
    //     b[i] = Complex(0, 0);
    // }

    FFT(a, len, 1);
    FFT(b, len, 1);

    for (int i = 0; i < len; i++)
    {
        a[i] = a[i] * b[i];
    }

    FFT(a, len, -1);

    for (int i = 0; i < len; i++)
    {
        sum[i] = (int)(a[i].real() + 0.5);
    }
    for (int i = 0; i < len; i++)
    {
        sum[i + 1] += sum[i] / 10;
        sum[i] %= 10;
    }

    int p = len - 1;
    while (sum[p] == 0)
        p--;
    for (; p >= 0; p--)
    {
        cout << sum[p];
    }
    cout << endl;
    // system("pause");
}
