#include <iostream>
#include <vector>
#include <set>

using namespace std;

int dfs(int u, vector<vector<int>>& children, vector<set<string>>& topics, vector<set<string>>& known, set<string>& ans) {
    vector<int> indices;
    int largest = 0, argmax = u;
    for (int v : children.at(u)) {
        int idx = dfs(v, children, topics, known, ans);
        indices.push_back(idx);
        int sz = known.at(idx).size();
        if (sz > largest) {
            largest = sz;
            argmax = idx;
        }
    }
    // check ans candidates
    vector<string> to_rm;
    if (children.at(u).size() > 1) {
        vector<string> to_del;
        for (string t : ans) {
            int cnt = 0;
            for (int idx : indices) {
                cnt += known.at(idx).count(t) == 0;
                if (cnt == 2) {
                    to_del.push_back(t);
                    break;
                } 
            }
            if (cnt == 1) {
                to_rm.push_back(t);
            }
        }
        for (string t : to_del) {
            // cerr << "removing " << t << " from ans\n";
            ans.erase(t);
        }
    }
    
    // small to large merging
    for (int idx : indices) {
        if (idx == argmax) {
            continue;
        }
        known.at(argmax).insert(known.at(idx).begin(), known.at(idx).end());
    }
    // remove missed topics
    for (string t : to_rm) {
        known.at(argmax).erase(t);
    }
    // also insert current topics
    for (string t : topics.at(u)) {
        known.at(argmax).insert(t);
    }
    // cerr << u << ": ";
    // for (string t : known.at(argmax)) {
    //     cerr << t << " ";
    // }
    // cerr << endl;
    return argmax;
}

int main() {
    int T;
    cin >> T;
    for (int task = 1; task <= T; task++) {
        int N;
        cin >> N;
        vector<vector<int>> children(N);
        for (int i = 1; i < N; i++) {
            int p;
            cin >> p;
            p--;
            children[p].push_back(i);
        }
        vector<set<string>> topics(N);
        set<string> ans;
        for (int i = 0; i < N; i++) {
            int M;
            cin >> M;
            for (int j = 0; j < M; j++) {
                string s;
                cin >> s;
                topics[i].insert(s);
                ans.insert(s);
            }
        }
        vector<set<string>> known(N);
        int idx = dfs(0, children, topics, known, ans);
        vector<string> to_del;
        for (string t : ans) {
            if (known.at(idx).count(t) == 0) {
                to_del.push_back(t);
            }
        }
        for (string t : to_del) {
            ans.erase(t);
        }
        
        cout << "Case #" << task << ": " << ans.size() << endl;
    }
}
