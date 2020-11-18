#include "swap.h"

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = (int)1e5 + 1, INF = (int)1e9 + 1;
vector<pii> edges[MAXN];
int task = 0;
int min2, min3, maxw = 0;
bool isRing = true;
int dist[MAXN];
int indegree[MAXN];

void init(int N, int M, std::vector<int> U, std::vector<int> V, std::vector<int> W) {
    for (int i = 0; i < M; i++) {
        edges[U[i]].push_back(make_pair(V[i], W[i]));
        edges[V[i]].push_back(make_pair(U[i], W[i]));
        indegree[U[i]]++;
        indegree[V[i]]++;
    }
    // check task 1
    bool flag = true;
    for (int i = 0; i < N; i++) {
        if (indegree[i] > 2)
            flag = false;
        if (indegree[i] != 2)
            isRing = false;
    }
    if (flag) {
        task = 1;
        for (int w : W)
            maxw = max(maxw, w);
        return;
    }

    // check task 2
    flag = true;
    for (int u : U) {
        if (u != 0)
            flag = false;
    }
    if (flag) {
        for (int i = 0; i < N; i++)
            dist[V[i]] = W[i];
        sort(W.begin(), W.end());
        min3 = W[2], min2 = W[1];
        task = 2;
        return;
    }
    
    // check task 5
    // if (M == N - 1) {
    //     task = 5;
    //     return;
    // }

    // task 4
    task = 4;
    return;
}

int vis[MAXN], top = 1, x, y;
bool viable = false, notDirect = false;
bool dfs(int u, int thresh, int target) {
    vis[u] = top;
    if (u == target)
        return true;

    for (pii e : edges[u]) {
        if (vis[e.first] == top || e.second > thresh)
            continue;
        int v = e.first, w = e.second;

        // workaround
        if (notDirect && u == x && v == y)
            continue;
        if (u == x && v == y) {
            if (notDirect)
                continue;
            else {
                notDirect = true;
                return true; // vis[Y] = ok
            }
        }

        if (dfs(v, thresh, target)) {
            return true;
        }
    }
    return false;
}

bool dfs_3(int u, int thresh) {
    vis[u] = top;
    int ind = 0;
    for (pii e : edges[u])
        if (e.second <= thresh)
            ind++;
    if (ind >= 3) {
        viable = true;
        return true;
    }
    for (pii e : edges[u]) {
        if (vis[e.first] == top || e.second > thresh)
            continue;
        int v = e.first, w = e.second;
        if (dfs_3(v, thresh)) {
            return true;
        }
    }
    return false;
}

int getMinimumFuelCapacity(int X, int Y) {
    x = X, y = Y;
    if (task == 1) {
        return isRing ? maxw : -1;
    } else if (task == 2) {
        if (X == 0) {
            return max(min3, dist[Y]);
        } else {
            return max(min3, max(dist[X], dist[Y]));
        }
    } else if (task == 4) {
        int l = 0, r = INF;
        while (l <= r) {
            int mid = (l + r) / 2;
            viable = false, notDirect = false;
            // ring
            bool connected = dfs(X, mid, Y); // one route
            if (connected) {
                // reuse vis
                vis[Y] = top - 1;
                if (dfs(X, mid, Y)) { // find another route
                    viable = true;
                }
            }
            top++;
            // 3 branches
            if (connected)
                dfs_3(X, mid);
            top++;

            if (viable)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l >= INF ? -1 : l;
    }
    return 0;
}
