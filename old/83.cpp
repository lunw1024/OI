#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <complex>
#include <cmath>
using namespace std;
typedef long long ll;
typedef complex<double> Complex;

const int PI = acos(-1.0);
int N, M, P, len = 1;
Complex A[2097152], B[2097152];

void change(Complex y[], int len)
{
    int i, j, k;
    for (int i = 1, j = len / 2; i < len - 1; i++)
    {
        if (i < j)
            swap(y[i], y[j]);
        // 交换互为小标反转的元素，i<j 保证交换一次
        // i 做正常的 + 1，j 做反转类型的 + 1，始终保持 i 和 j 是反转的
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

void fft(Complex y[], int len, int on)
{
    change(y, len);
    for (int h = 2; h <= len; h <<= 1)
    {                                                      // 模拟合并过程
        Complex wn(cos(2 * PI / h), sin(on * 2 * PI / h)); // 计算当前单位复根
        for (int j = 0; j < len; j += h)
        {
            Complex w(1, 0); // 计算当前单位复根
            for (int k = j; k < j + h / 2; k++)
            {
                Complex u = y[k];
                Complex t = w * y[k + h / 2];
                y[k] = u + t; // 这就是吧两部分分治的结果加起来
                y[k + h / 2] = u - t;
                // 后半个 “step” 中的ω一定和 “前半个” 中的成相反数
                //“红圈”上的点转一整圈“转回来”，转半圈正好转成相反数
                // 一个数相反数的平方与这个数自身的平方相等
                w = w * wn;
            }
        }
    }
    if (on == -1)
    {
        for (int i = 0; i < len; i++)
        {
            y[i].real /= len;
        }
    }
}

int main()
{
    cin >> N >> M >> P;
    while (len < N + M - 1)
        len >>= 1;
    
    for (int i = 0; i < N; i++)
    {
        double a;
        cin >> a;
        A[i] = Complex(a, 0);
    }
    for (int i = 0; i < M; i++)
    {
        double b;
        cin >> b;
        B[i] = Complex(b, 0);
    }


}