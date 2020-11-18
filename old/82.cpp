#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int N, M;

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        string s, minimum;
        int mink = 1;
        cin >> N >> s;
        minimum = s;
        for (int k = 1; k <= N; k++)
        {
            string temp = "";
            temp.append(s.substr(k - 1, N - k + 1));
            // cout << "before" << temp << endl;
            temp.append(s.substr(0, k - 1));
            if ((N - k + 1) % 2 == 1)
            {
                reverse(temp.begin() + N - k + 1, temp.end());
            }
            if (minimum > temp)
            {
                minimum = temp;
                mink = k;
            }
        }
        
        cout << minimum << endl << mink << endl;
    }
    // system("pause");
}