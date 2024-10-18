#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) x.size()

#define f first
#define s second

const int PRIME = 1e9 + 7;


const int K = 26;

struct Vertex {
    int next[K];
    bool output = false;

    Vertex() {
        fill(begin(next), end(next), -1);
    }
};


void add_string_backward(string const& s, vector<Vertex>& trie) {
    int v = 0;
    for(int i = sz(s) - 1; i >= 0; i--){
        int c = s[i] - 'a';
        // int c = ch - 'a';
        if (trie[v].next[c] == -1) {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[c];
    }
    trie[v].output = true;
}

int query_string_backward(string const& s, vector<Vertex>& trie){
    // count how many trie matches, if you reverse s

}



pii findBounds(vector<string>& strings, string& startsWith){
    // find all elements in strings that start with startsWith
    // you can assume strings is sorted
    int lo = 0;
    int hi = sz(strings);



}


void getAnswer(vector<string>& strings, vector<string>& queryPref, vector<string>& querySuff, string& startWith, vector<Vertex>& trie, set<int>& usedStringIdx, vi& queryIdx, vi& ans){
    pii lohi = findBounds(queryPref, startWith);

    for(int i = lohi.f; i < lohi.s; i++){
        if(queryPref[i] == startWith){
            continue;
        }
        vector<Vertex> newTrie(1);
        set<int> newUsedStringIdx;
        getAnswer(strings, queryPref, querySuff, queryPref[i], newTrie, newUsedStringIdx, queryIdx, ans);

        if(sz(newTrie) > sz(trie)){
            swap(newTrie, trie);
            swap(newUsedStringIdx, usedStringIdx);
        }

        // merge newTrie into trie
        for(auto idx: newUsedStringIdx){
            add_string_backward(strings[idx], trie);
            usedStringIdx.insert(idx);
        }
    }

    pii strLoHi = findBounds(strings, startWith);
    for(int i = strLoHi.f; i < strLoHi.s; i++){
        if(usedStringIdx.count(i) == 0){
            add_string_backward(strings[i], trie);
            usedStringIdx.insert(i);
        }
    }

    for(int i = lohi.f; i < lohi.s; i++){
        if(queryPref[i] != startWith){
            continue;
        }
        ans[queryIdx[i]] = query_string_backward(querySuff[i], trie);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n, q;
    cin >> n >> q;
    vector<string> strings(n);
    for(int i = 0; i < n; i++){
        cin >> strings[i];
    }
    sort(all(strings));
    vector<string> queries(n);
    vector<pair<pair<string, string>, int>> queryPrefSuff(n);
    for(int i = 0; i < q; i++){
        string query;
        cin >> query;
        int idx = -1;
        for(int j = 0; j < sz(query); j++){
            if(query[j] == '*'){
                idx = j;
                break;
            }
        }
        queryPrefSuff[i].f.f = query.substr(0, idx);
        queryPrefSuff[i].f.s = query.substr(idx+1, sz(query) - idx);
        queryPrefSuff[i].s = i;
    }
    sort(all(queryPrefSuff));
    vector<string> realPref(n);
    vector<string> realSuff(n);
    vi realIdx(n);
    for(int i = 0; i < q; i++){
        realPref[i] = queryPrefSuff[i].f.f;
        realSuff[i] = queryPrefSuff[i].f.s;
        realIdx[i] = queryPrefSuff[i].s;
    }

    vector<Vertex> trie(1);
    set<int> usedStringIdx;
    vi ans(q);
    string start = "";

    getAnswer(strings, realPref, realSuff, start, trie, usedStringIdx, realIdx, ans);
    for(auto el: ans){
        cout << el << '\n';
    }
}
