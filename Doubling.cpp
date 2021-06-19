#include <bits/stdc++.h>
using namespace std;

template<typename T> struct Doubling {
    static const long long INF = numeric_limits<long long>::max();

private:
    const int logn, n;
    vector<vector<int>> id;
    vector<vector<T>> sum;

public:
    Doubling(const int N, const int LOGN = (int)log2(INF)): logn(LOGN+1), n(N), id(logn, vector<int>(n)),  sum(logn, vector<T>(n, 0)) {}

    // cost is FROM's
    void Add(const int FROM, const int TO, const T COST = 0){
        id[0][FROM] = TO; sum[0][FROM] = COST;
    }

    void Build(){
        for(int k = 0; k+1 < logn; k++){
            for(int i  = 0; i < n; i++){
                if(id[k][i] < 0) id[k+1][i] = -1;
                else id[k+1][i] = id[k][id[k][i]], sum[k+1][i] = sum[k][i] + sum[k][id[k][i]];
            }
        }
    }

    int IdQuery(int FROM, long long X){
        for(int k = 0; X > 0; k++, X >>= 1) if(X & 1) FROM = id[k][FROM];
        return FROM;
    }
    T SumQuery(int FROM, long long X){
        T ret = 0;
        for(int k = 0; X > 0; k++, X >>= 1) if(X & 1) ret += sum[k][FROM], FROM = id[k][FROM];
        return ret;
    }

};

void ABC167_D_Teleporter(){
    // https://atcoder.jp/contests/abc167/tasks/abc167_d
    int n;
    long long k;
    cin >> n >> k;
    vector<int> a(n);

    Doubling<long long> table(n);

    for(int i = 0; i < n; i++){
        int a; cin >> a; a--;
        table.Add(i, a);
    }

    table.Build();

    cout << table.IdQuery(0, k)+1 << endl;
}

void ABC179_E_SequenceSum(){
    //https://atcoder.jp/contests/abc179/tasks/abc179_e
    long long n,x,m;
    cin >> n >> x >> m;

    Doubling<long long> table(m);
    long long y = x;

    for(int i = 0; i < m; i++, y = y*y%m){
        table.Add(y % m, y * y % m, y % m);
    }
 
    table.Build();
 
    cout << table.SumQuery(x, n) << endl;
}

int main(){ 
    ABC179_E_SequenceSum();
}