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

inline int read()
{
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}

Complex a[2097152], b[2097152];
int ans[2097152] = {0};
int main()
{
    int lena = read(), lenb = read();
    lena++, lenb++;
    for (int i = 0; i < lena; i++)
    {
        int temp = read();
        a[i] = Complex(temp, 0);
    }
    for (int i = 0; i < lenb; i++)
    {
        int temp = read();
        b[i] = Complex(temp, 0);
    }

    int len = 1;
    while (len < lena + lenb - 1)
    {
        len <<= 1;
    }

    FFT(a, len, 1);
    FFT(b, len, 1);

    for (int i = 0; i < len; i++)
    {
        a[i] = a[i] * b[i];
    }

    FFT(a, len, -1);

    for (int i = 0; i < len; i++)
    {
        ans[i] = (int)(a[i].real() + 0.5);
    }

    for (int i = 0; i < lena + lenb - 1; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    // system("pause");
}
