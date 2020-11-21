#include <bits/stdc++.h>
using namespace std;



template<typename T>
struct BFS_Multiple {
    private:
    const T INF = numeric_limits<T>::max();

    struct Edge { 
        int v,id;
        Edge (int v_, int id_) : v(v_), id(id_) {}
    };

    vector<vector<int>> graph;
    vector<vector<T>> dt;
    vector<vector<Edge>> rt;

    public:
    BFS_Multiple (const int n_, const int k_ = 1) : graph(n_), dt(n_, vector<T>(k_, INF)), rt(n_, vector<Edge>(k_)) {}

    T operator [] (int n_) { return dt[n_][0]; } 

    void AddEdge(int from, int to){
        graph[from].push_back(to);
    }

    //O(V+H)?
    void Build(const int s, const int k_ = 1){
        queue<Edge> que;
        que.push(Edge(s,0));
        dt[s][0] = 0;
        while(!que.empty()){
            Edge now = que.front(); que.pop();
            for(int u:graph[now.v]){
                Edge nxt(u, (now.id+1)%k_);
                if(dt[nxt.v][nxt.id] > dt[now.v][now.id]+1){
                    dt[nxt.v][nxt.id] = dt[now.v][now.id]+1;
                    rt[nxt.v][nxt.id] = now;
                    que.push(nxt);
                }
            }
        }
    }

    vector<int> Path(const int from, const int to){
        vector<int> ret;
        ret.push_back(to);
        Edge bef(to,0);
        while(bef.v != from || bef.id != 0){
            bef = rt[bef.v][bef.id];
            ret.push_back(bef.v);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};



int main(){
    return 0;
}