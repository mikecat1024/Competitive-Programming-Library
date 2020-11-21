#include <bits/stdc++.h>
using namespace std;



template<typename T>
struct Dijkstra {
    private:
    struct Edge {
        int to; T cost;
        Edge (int to, T cost) : to(to), cost(cost) {}

        bool operator<(const Edge &right) const{ return cost > right.cost; } 
    };

    const T INF = numeric_limits<T>::max();
    vector<T> dt;
    vector<int> rt;
    vector<vector<Edge>> Graph;

    public:
    Dijkstra (int n) : Graph(n) {}

    T operator [] (int k) const{ return dt[k]; };

    void AddEdge (int from, int to, T cost) {
        Graph[from].push_back(Edge(to, cost));
    }

    void Build (int s) {
        int n = Graph.size();
        priority_queue<Edge> pque;
        dt.assign(n, INF); rt.assign(n, -1);
        dt[s] = 0;
        pque.push(Edge(s,dt[s]));
        while(!pque.empty()){
            Edge now = pque.top(); pque.pop();
            if(dt[now.to] < now.cost) continue;
            for(Edge nxt : Graph[now.to]){
                if(dt[nxt.to] > now.cost+nxt.cost){
                    dt[nxt.to] = now.cost+nxt.cost;
                    rt[nxt.to] = now.to;
                    pque.push(Edge(nxt.to,dt[nxt.to]));
                }
            }
        }
    }

    vector<int> Path (int to) {
        vector<int> route;
        if(rt[to] < 0) return route;
        while(~to){
            route.push_back(to);
            to = rt[to];
        }
        reverse(route.begin(), route.end());
        return route;
    }
};



int main(){} 