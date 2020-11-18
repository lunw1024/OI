#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <set>
using namespace std;

struct Ele
{
    int l, r;
    bool operator <(const Ele &o)const
    {
        return r < o.l;
    }
};

int N;
set<Ele> s;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        char ch;
        cin >> ch;
        if (ch == 'A')
        {
            int l, r, cnt = 0;
            cin >> l >> r;
            Ele temp = (Ele){l, r};
            set<Ele>::iterator it=s.find(temp);
            while(it != s.end())
            {
                s.erase(it);
                it=s.find(temp);
                cnt++;
            }
            s.insert(temp);
            cout << cnt << endl;
        }
        else
        {
            cout << s.size() << endl;
        }
        
    }
    // system("pause");
}