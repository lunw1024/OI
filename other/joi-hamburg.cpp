#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

struct Box
{
    int x1, y1, x2, y2;
    Box(int x1, int y1, int x2, int y2)
    {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }
};

int N, K;
// vector<Box> boxes;

// bool intersect(Box a, Box b)
// {
//     return 
// }

int main()
{
    cin >> N >> K;
    int l, r, u, d;
    for (int i = 0; i < N; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        l = max(l, x1), r = min(r, x2);
        d = max(d, y1), u = min(u, y2);
    }

    if (K == 1)
    {
        cout << l << " " << d << endl;
    }
    // system("pause");
}