#include<bits/stdc++.h>

using namespace std;

int main()
{   
    int n;
    cin >> n;
    long long v;
    cin >> v;
    queue<long long> q;
    map<long long, int> dist;
    dist[v] = 0;
    q.push(v);
    while(!q.empty())
    {
        long long k = q.front();
        q.pop();
        string s = to_string(k);
        if(s.size() == n)
        {
            cout << dist[k] << endl;
            return 0;
        }
        for(auto x : s)
        {
            if(x == '0') continue;
            long long w = k * int(x - '0');
            if(!dist.count(w))
            {
                dist[w] = dist[k] + 1;
                q.push(w);
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
