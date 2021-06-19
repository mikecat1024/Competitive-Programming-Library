#include <bits/stdc++.h>
using namespace std;

template<typename T> struct BellmanFord {
    const T INF = numeric_limits<T>::max()/2;

private:
    struct Edge {
        int id; T cost;
        Edge (int TO, T COST) : id(TO), cost(COST) {}
    };
    
    vector<vector<Edge>> graph;
    vector<T> dt; vector<int> rt;
    vector<bool> reach, seen;
    
    void reachable(const int now){
        if(seen[now]) return;
        seen[now] = true;
        for(const Edge nxt : graph[now]) reachable(nxt.id); 
    }

public:
    bool loop = false;

    BellmanFord (const int N) : graph(N), dt(N, INF), rt(N, -1), reach(N, true), seen(N, false) {}

    T operator [] (const int i) { return dt[i]; }

    vector<int> Path (const int FROM, int TO) {
        if(rt[TO] == -1) return {-1};
        vector<int> ret = {TO};
        while(TO != FROM) ret.push_back(TO = rt[TO]);
        reverse(ret.begin(), ret.end());
        return ret;
    }

    void Add (const int FROM, const int TO, const T COST) {
        graph[FROM].push_back(Edge(TO, COST));
    }
    
    //O(VE)
    void Build (const int FROM){
        dt[FROM] = 0;
        for(int i = 0; i < (int)graph.size(); i++){
            bool update = false;
            for(int now = 0; now < (int)graph.size(); now++){    
                if(!reach[now]) continue;
                for(const Edge nxt : graph[now]){
                    if(!reach[nxt.id] or dt[now] == INF) continue;
                    if(dt[nxt.id] > dt[now] + nxt.cost){
                        dt[nxt.id] = dt[now] + nxt.cost;
                        rt[nxt.id] = now;
                        update = true;
                        if(i == (int)graph.size() - 1) loop = true;
                    }
                }    
            }
            if(!update) break;
        }
    }
    //if you know the goal, you should do this.
    //if the graph have loop, the value of *cout*ed can be wrong.
    void Build (const int FROM, const int TO){  
        for(int i = 0; i < (int)graph.size(); i++){
            fill(seen.begin(), seen.end(), false);
            reachable(i);
            reach[i] = seen[TO];
        }
        Build(FROM);
    }

    void print (const int FROM, const int TO) {
        for(auto p : Path(FROM, TO)) cout << p << ' ';
        cout << '\n';
    }
};

void ABC061_D_ScoreAttack(){
    //https://atcoder.jp/contests/abc061/tasks/abc061_d
    int n, m;
    cin >> n >> m;

    BellmanFord<long long> graph(n);
    for(int i = 0; i < m; i++){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--; b--;
        graph.Add(a, b, -c);
    }

    graph.Build(0, n-1);

    // graph.print(0, n-1);

    if(graph.loop) cout << "inf" << endl;
    else cout << -graph[n-1] << endl;

}

void ABC137_E_CoinsRespawn(){
    //https://atcoder.jp/contests/abc137/tasks/abc137_e
    int n, m, p;
    cin >> n >> m >> p;

    BellmanFord<int> graph(n);

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        graph.Add(a, b, -(c-p));
    }

    graph.Build(0, n-1);

    if(graph.loop) cout << -1 << endl;
    else cout << max(-graph[n-1],0) << endl;
}

int main(){
    ABC137_E_CoinsRespawn();
}