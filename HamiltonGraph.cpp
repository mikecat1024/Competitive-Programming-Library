#include <bits/stdc++.h>
using namespace std;

//計算量O(2^M*N^2),O(N)
//三角不等式が成り立つ場合に全ての頂点を一度*以上*訪れる最短経路およびその距離
//いつかちゃんと整備する
template<typename T>
class HamiltonGraph {
    const T INF = numeric_limits<T>::max();
    int n;
    T M;
    vector<vector<T>> DP, rt;

    public:
    vector<vector<T>> dt;
    vector<int> path;

    HamiltonGraph (const int n_) : n(n_), M(1ll<<n_) {
        dt.assign(n_, vector<T>(n_, INF));
    }

    T Build (int s, int g = -1) {
        DP.assign(M, vector<T>(n, INF));
        rt.assign(M, vector<T>(n, -1));
        DP[1<<s][s] = 0;
        for(ll i = 0; i < M; i++){
            for(int j = 0; j < n; j++){
                if(i & (1ll<<j)){
                    for(int k = 0; k < n; k++){
                        if(DP[i][j] != INF && DP[i|(1ll<<k)][k] > DP[i][j]+dt[j][k]){
                            DP[i|(1ll<<k)][k] = DP[i][j]+dt[j][k];
                            rt[i|(1ll<<k)][k] = j;
                        }
                    }
                }
            }
        }
        if(g < 0) g = min_element(DP[M-1].begin(), DP[M-1].end())-DP[M-1].begin();
        return DP[M-1][g];
    }

    void Path (int s = 0, int g = -1) {
        path.clear();
        if(g < 0) g = min_element(DP[M-1].begin(), DP[M-1].end())-DP[M-1].begin();
        T m = M-1;
        int now, nxt; now = nxt = g;
        if(s == g){
            path.push_back(g);
            now = nxt = rt[m][g];
        }
        while(m != (1<<s) || now != s){
            path.push_back(now);
            now = rt[m][now];
            m ^= (1<<nxt);
            nxt = now;
        }
        path.push_back(now);
        reverse(path.begin(), path.end());
    }
};
