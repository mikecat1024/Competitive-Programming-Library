#include <bits/stdc++.h>
using namespace std;

template<typename T> struct WarshallFloyd {
    const T INF = numeric_limits<T>::max()/2;

private:
    vector<vector<T>> dt;

public:
    WarshallFloyd(const int N) : dt(N, vector<T>(N, INF)) {
        for(int i = 0; i < N; i++) dt[i][i] = 0;
    }

    //{i, j} -> distance of i to j
    T operator () (const int i, const int j) { return dt[i][j]; }

    void Add(const int FROM, const int TO, const T COST){
        dt[FROM][TO] = COST;
    }

    void Build(){
        for(int i = 0; i < (int)dt.size(); i++){
            for(int j = 0; j < (int)dt.size(); j++){
                for(int k = 0; k < (int)dt.size(); k++){
                    dt[j][k] = min(dt[j][i] + dt[i][k], dt[j][k]);
                }
            }
        }
    }
    // this use the vertex that the index is smaller than (<) R except for start and goal.
    // void Build(const int R){
    //     for(int i = 0; i < R; i++){
    //         for(int j = 0; j < (int)dt.size(); j++){
    //             for(int k = 0; k < (int)dt.size(); k++){
    //                 dt[j][k] = min(dt[j][i] + dt[i][k], dt[j][k]);
    //                 // if(dt[j][k] < INF) ans += dt[j][k]; // ABC208-D
    //             }
    //         }
    //     }
    // }

    void print () {
        for(int i = 0; i < n; i++){
            cout << i << "| ";
            for(int j = 0; j < n; j++){
                cout << dt[i][j] << " ";
            }
            cout << '\n';
        }
    }
};

void ABC143_E_TravelbyCar(){
    int n, m , l;
    cin >> n >> m >> l;
    WarshallFloyd<long long> table(n);
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        table.Add(a, b, c);
        table.Add(b, a, c);
    }

    table.Build();

    WarshallFloyd<int> ans(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(table(i,j) <= l){
                ans.Add(i, j, 1);
            }
        }
    }

    ans.Build();

    int q;
    cin >> q;
    vector<pair<int,int>> query(q);
    for(int i = 0; i < q; i++){
        cin >> query[i].first >> query[i].second;
        query[i].first--; query[i].second--;
    }

    for(int i = 0; i < q; i++){
        if(ans(query[i].first, query[i].second) == ans.INF) cout << -1 << endl;
        else cout << ans(query[i].first, query[i].second)-1 << endl;
    }
}

int main(){
    ABC143_E_TravelbyCar();
}