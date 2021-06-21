#include <bits/stdc++.h>
using namespace std;


//calculate distance from root to each vertex in dt
template <typename T> struct TreeDistance {
    struct Edge {
        int id; T cost;
        Edge (const int ID, const T COST) : id(ID), cost(COST) {}
    };
    vector<T> dt; 
    vector<vector<Edge>> graph;

    TreeDistance (const int N) : dt(N, 0), graph(N) {}

    T operator [] (const int i) { return dt[i]; }
 
    void Add (const int FROM, const int TO, const T COST){
        graph[FROM].push_back(Edge(TO, COST));
        graph[TO].push_back(Edge(FROM, COST));
    }

    void Build (const int FROM = 0, const int ROOT = -1, T COST = 0) {
        dt[FROM] = COST;

        for(Edge nxt : graph[FROM]){
            if(nxt.id == ROOT) continue;
            // COST += nxt.cost; 
            COST ^= nxt.cost;
            Build(nxt.id, FROM, COST);
            // COST -= nxt.cost; 
            COST ^= nxt.cost;
        }
    }
};

void ABC201_E_XorDistances() {
    static const long long mod = 1e9+7;

    int n; cin >> n;
    TreeDistance<long long> tree(n);

    for(int i = 0; i < n - 1; i++){
        long long u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        tree.Add(u, v, w);
    }

    tree.Build();

    long long powers[63]; powers[0] = 1; powers[1] = 2;
    for(int i = 1; i < 62; i++) powers[i+1] = 2 * powers[i] % mod; 

    long long ans = 0;

    for(int i = 0; i < 63; i++){
        long long bit = 0;
        for(int j = 0; j < n; j++) if(tree.dt[j] >> i & 1) bit++;
        ans += powers[i] * (bit * (n - bit) % mod + mod) %mod;
        ans %= mod;
    }

    cout << ans << endl;
}


int main(){
    ABC201_E_XorDistances();
}