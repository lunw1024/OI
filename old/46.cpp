#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <complex>
#include <cmath>
using namespace std;
typedef complex<double> Complex;

const double PI = acos(-1.0);
const int MAXN = 262145;

int N;
double q[MAXN] = {0}, g[MAXN] = {0}, qReversed[MAXN] = {0}, ans1[MAXN] = {0}, ans2[MAXN] = {0};

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

void wrapper(double a[], double b[], int len, double out[])
{
    Complex* temp1 = new Complex[len];
    Complex* temp2 = new Complex[len];

    for (int i = 0; i < N; i++)
    {
        temp1[i].real(a[i]);
        temp2[i].real(b[i]);
    }

    // for (int i = 0; i < N; i++)
    // {
    //     cout << fixed << temp1[i] << " ";
    // }
    // cout << endl;

    FFT(temp1, len, 1);
    FFT(temp2, len, 1);

    for (int i = 0; i < len; i++)
    {
        temp1[i] = temp1[i] * temp2[i];
    }

    FFT(temp1, len, -1);

    for (int i = 0; i < N; i++)
    {
        out[i] = temp1[i].real();
    }
    delete[] temp1;
    delete[] temp2;
}

int main()
{
    cin >> N;
    int len = 1;
    while (len < N * 2)
    {
        len <<= 1;
    }

    for (int i = 0; i < N; i++)
    {
        cin >> q[i];
        qReversed[N - i - 1] = q[i];
        g[i] = i == 0 ? 0.0 : 1.0 / i / i;
    }

    wrapper(q, g, len, ans1);
    wrapper(qReversed, g, len, ans2);

    for (int i = 0; i < N; i++)
    {
        // cout << fixed << "ans1[i] = " << ans1[i] << endl;
        cout << fixed << ans1[i] - ans2[N - i - 1] << endl;
    }
    // system("pause");
}
