#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int caseNo = 0; caseNo < T; caseNo++)
    {
        int N, M;
        cin >> N >> M;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (i == 0 && j == 1 && N * M % 2 == 0)
                {
                    cout << "B";
                    continue;
                }
                cout << ((i + j) % 2 == 0 ? "B" : "W");
            }
            cout << endl;
        }
    }
    // system("pause");
}