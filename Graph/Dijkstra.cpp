#include <bits/stdc++.h>
using namespace std;

template<typename T> struct Dijkstra {
    const T INF = numeric_limits<T>::max();

private:
    struct Edge {
        int id; T cost;
        Edge (int TO, T COST) : id(TO), cost(COST) {}
        bool operator < (const Edge &right) const{ return cost > right.cost; } 
    };
    
    vector<vector<Edge>> graph;
    vector<T> dt; vector<int> rt;

public:
    const T inf = INF;

    Dijkstra (const int N) : graph(N), rt(N, -1) {}

    T operator [] (const int i) { return dt[i]; };

    vector<int> Path (const int FROM, int TO) {
        if(rt[TO] == -1) return {-1};
        vector<int> ret = {TO};
        while(TO != FROM) ret.push_back(TO = rt[TO]);
        reverse(ret.begin(), ret.end());
        return ret;
    }

    inline void Add (const int FROM, const int TO, const T COST) {
        graph[FROM].push_back(Edge(TO, COST));
    }

    //O(ElogV)
    void Build (const int FROM) {
        dt.resize((int)graph.size(), INF);
        dt[FROM] = 0;

        priority_queue<Edge> que;
        que.push(Edge(FROM, dt[FROM]));

        while(!que.empty()){
            const Edge now = que.top(); que.pop();
            if(dt[now.id] < now.cost) continue;
            for(const Edge nxt : graph[now.id]){
                if(dt[nxt.id] > now.cost + nxt.cost){
                    dt[nxt.id] = now.cost + nxt.cost;
                    rt[nxt.id] = now.id;
                    que.push(Edge(nxt.id, dt[nxt.id]));
                }
            }
        }
    }

    void print (const int FROM, const int TO) {
        for(auto p : Path(FROM, TO)) cout << p << ' ';
        cout << '\n';
    }
};

void LC_ShortestPath(){
    //https://judge.yosupo.jp/problem/shortest_path
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    Dijkstra<long long> graph(n);

    for(int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph.Add(a, b, c);
    }

    graph.Build(s);
    vector<int> path = graph.Path(s,t);

    if(graph[t] == graph.inf) cout << -1 << endl;
    else {
        cout << graph[t] << " " << path.size()-1 << endl;
        for(int i = 0; i < path.size()-1; i++){
            cout << path[i] << " " << path[i+1] << endl;
        }
    }
}

int main () {
    LC_ShortestPath();
}