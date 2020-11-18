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
int a1[MAXN] = {0}, twice[MAXN] = {0}, twice3[MAXN] = {0}, thrice[MAXN] = {0}, a2[MAXN] = {0}, a3[MAXN] = {0}, ans[MAXN] = {0};

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

void wrapper(int a[], int b[], int len, int out[])
{
    Complex* temp1 = new Complex[len];
    Complex* temp2 = new Complex[len];

    for (int i = 0; i < len; i++)
    {
        temp1[i].real((double)a[i]);
        temp2[i].real((double)b[i]);
        
    }

    FFT(temp1, len, 1);
    FFT(temp2, len, 1);

    for (int i = 0; i < len; i++)
    {
        temp1[i] = temp1[i] * temp2[i];
    }

    FFT(temp1, len, -1);

    for (int i = 0; i < len; i++)
    {
        out[i] = (int)(temp1[i].real() + 0.5);
    }
    delete[] temp1;
    delete[] temp2;
}

int main()
{
    cin >> N;
    int len = 262144;

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        a1[temp]++;
        twice[temp * 2]++;
        thrice[temp * 3]++;
    }

    wrapper(a1, a1, len, a2);
    wrapper(a1, a2, len, a3);
    wrapper(twice, a1, len, twice3);

    for (int i = 0; i < MAXN; i++)
    {
        ans[i] = a1[i] + (a2[i] - twice[i]) / 2 + (a3[i] - 3 * twice3[i] + 2 * thrice[i]) / 6;
        if (ans[i] > 0)
        {
            cout << i << " " << ans[i] << "\n";
        }
        else if (ans[i] < 0)
        {
            cout << "error" << endl;
        }
    }
    // system("pause");
}
