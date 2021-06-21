#include <bits/stdc++.h>
using namespace std;


template<typename T> struct TreeDiamiter {
private:
    struct Edge { 
        int to; T cost;
        Edge (int TO, T COST) : to(TO), cost(COST) {}
    };

    vector<vector<Edge>> graph;

    pair<T, int> dfs (int FROM, int ROOT = -1, T DEPTH = 0){
        pair<T, int> ret = make_pair(DEPTH, FROM);
        for(auto nxt : graph[FROM]){
            if(nxt.to == ROOT) continue;
            ret = max(ret, dfs(nxt.to, FROM, DEPTH + nxt.cost));
        }
        return ret;
    }
    
public:
    TreeDiamiter (int N) : graph(N) {}

    void Add (int FROM, int TO, T COST = 1) {
        graph[FROM].push_back(Edge(TO, COST));
        graph[TO].push_back(Edge(FROM, COST));
    }

    T Diamiter () {
        return dfs(dfs(0).second).first;
    }
};

void Typical90_C_LongestCircularRoad() {
    // https://atcoder.jp/contests/typical90/tasks/typical90_c
    int n; cin >> n;
    TreeDiamiter<int> tree(n);

    for(int i = 0; i < n - 1; i++){
        int a, b; 
        cin >> a >> b;
        a--; b--;
        tree.Add(a, b);
    }

    cout << tree.Diamiter() + 1 << endl;

}

int main(){
    Typical90_C_LongestCircularRoad();
}