#include <bits/stdc++.h>
using namespace std;



template<typename M>
struct WarshallFloyd {
    private:
    const long long INF = numeric_limits<long long>::max();
    int n;

    public:
    vector<vector<M>> dt;

    WarshallFloyd(const int n_) : n(n_), dt(n, vector<M>(n, INF)) {
        for(int i = 0; i < n; i++) dt[i][i] = 0;
    }

    void AddEdge(const int from, const int to, const M cost){
        dt[from][to] = cost;
    }

    void Build(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    dt[j][k] = min(dt[j][i]+dt[i][k], dt[j][k]);
                }
            }
        }
    }
};



int main(){
    return 0;
}