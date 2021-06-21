#include <bits/stdc++.h>
using namespace std;



struct Bipartite {
    vector<bool> color, seen;
    vector<vector<int>> graph;

    Bipartite (const int N) : color(N), seen(N, false), graph(N) {}

    void Add (const int FROM, const int TO) {
        graph[FROM].push_back(TO);
        graph[TO].push_back(FROM);
    }

    // if graph is bipartite. this returns true.
    // FlAG is FROM's color
    bool Build (const int FROM, const bool FLAG = 0) {
        color[FROM] = FLAG;
        seen[FROM] = true;
        for(const int nxt : graph[FROM]){
            if(color[nxt] == FLAG) return false;
            else if(!seen[nxt]){
                if(!Build(nxt, !FLAG)) return false;
            }
        }
        return true;
    }  
};