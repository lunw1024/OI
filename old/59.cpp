#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INV10 = 700000005;
string s;
int n, len;
bool allMul = true;
int head = 0, plusPos = 0, numCnt = 1, addCnt = 0;
vector<int> number[1000000];
vector<char> oper;
vector<pair<ll, ll> > coef;

inline bool isOperator(char ch)
{
    return ch == '+' || ch == '*';
}

ll inv(ll a, int x = MOD - 2)
{
    ll out = 1;
    while (x > 0)
    {
        if (x & 1)
            out = (out * a) % MOD;
        a = (a * a) % MOD;
        x >>= 1;
    }
    return out;
}

ll get_value(int idx)
{
    ll out = 0;
    for (int i = 0; i < number[idx].size(); i++)
    {
        out = (out * 10 + number[idx][i]) % MOD;
    }
    return out;
}

int main()
{
    cin >> s;
    len = s.size();
    for (head = 1; head < len; head++)
    {
        if (isOperator(s[head - 1]))
        {
            break;
        }
    }

    int prev = head;
    for (int i = head; i < len + head; i++)
    {
        if (isOperator(s[i % len]))
        {
            if (s[i % len] == '+')
            {
                allMul = false;
                addCnt++;
                plusPos = oper.size();
            }
            
            oper.push_back(s[i % len]);
            numCnt++;
        }
        else
        {
            number[numCnt - 1].push_back(s[i % len] - '0');
        }
    }
    numCnt--;

    ll ans = 0;
    if (numCnt == 0)
    {
        ll sum = 0;
        for (int i = 0; i < number[0].size(); i++)
        {
            sum += number[0][i];
        }

        ll base = 1;
        for (int i = 0; i < number[0].size(); i++)
        {
            ans = (ans + base * sum) % MOD;
            base = (base * 10) % MOD;
        }
    }
    else if (!allMul)
    {
        // preprocess coefficients
        for (int i = 0; i < numCnt; i++)
            coef.push_back(make_pair(1, 1));

        ll leftCo = 1, rightCo = 1;
        // calc leftCo
        for (int i = plusPos + 1; i < plusPos + 1 + numCnt; i++)
        {
            int idx = (i + numCnt) % numCnt;
            coef[idx].first = leftCo;
            if (oper[idx] == '*')
                leftCo = (leftCo * get_value(idx)) % MOD;
            else
                leftCo = 1;
        }
        // calc rightCo
        for (int i = plusPos + numCnt; i >= plusPos + 1; i--)
        {
            int idx = (i + numCnt) % numCnt;
            coef[idx].second = rightCo;
            if (oper[(idx - 1 + numCnt) % numCnt] == '*')
                rightCo = (rightCo * get_value(idx)) % MOD;
            else
                rightCo = 1;
        }

        for (int i = 0; i < numCnt; i++)
        {
            // left part
            ll temp = 0;
            for (int j = 0; j < number[i].size() - 1; j++)
            {
                temp = (temp * 10 + number[i][j]) % MOD;
                ans = (ans + temp * coef[i].first) % MOD;
                // cout << "left: ans += " << temp * coef[i].first << endl;

            }

            // right part
            temp = 0;
            int base = 1;
            for (int j = number[i].size() - 1; j >= 1; j--)
            {
                temp = (temp + number[i][j] * base) % MOD;
                ans = (ans + temp * coef[i].second) % MOD;
                base = (base * 10) % MOD;
                // cout << "right: ans += " << temp * coef[i].second << endl;
            }
        }

        // compete contribution
        int temp = 1;
        for (int i = plusPos + 1; i < plusPos + 1 + numCnt; i++)
        {
            int idx = (i + numCnt) % numCnt;
            temp = (temp * get_value(idx)) % MOD;
            if (oper[idx] == '+')
            {
                ans = (ans + temp * (addCnt - 1)) % MOD;
                // cout << "complete: ans += " << temp * (addCnt - 1) << endl; 
                temp = 1;
            }
        }
    }
    else // all mul
    {
        // cout << "yes" << endl;
        ll basis = 1;
        for (int i = 0; i < numCnt; i++)
        {
            basis = (basis * get_value(i)) % MOD;
        }

        for (int i = 0; i < numCnt; i++)
        {
            // left part
            ll l = 0, r = 0, base = 1, res = 0;
            vector<int> ls, rs;
            for (int j = 0; j < number[i].size() - 1; j++)
            {
                l = (l * 10 + number[i][j]) % MOD;
                r = (r + number[i][number[i].size() - 1 - j] * base) % MOD;
                base = (base * 10) % MOD;
                ls.push_back(l), rs.push_back(r);
            }

            for (int j = 0; j < number[i].size() - 1; j++)
            {
                res = (res + ls[j] * rs[rs.size() - 1 - j]) % MOD;
            }

            ans = (ans + (basis * inv(get_value(i)) % MOD) * res) % MOD;
            // cout << "ans += " << (basis * inv(get_value(i)) % MOD) * res << endl;
        }

    }
    

    cout << ans << endl;
    // system("pause");
}