#include <bits/stdc++.h>
using namespace std;



template<typename M>
struct Doubling {
    private:   
    const long long INF = numeric_limits<long long>::max();//modintの時バグりそう
    const int n;
    const int LOG = (int)log2(INF);
    vector<vector<int>> next;
    vector<vector<M>> sum;

    public:
    Doubling(const int n_) : n(n_), next(LOG, vector<int>(n, -1)), sum(LOG, vector<M>(n, 0)) {}
    Doubling(const vector<int> vec) : n((int)vec.size()), next(LOG, vector<int>(n, -1)), sum(LOG, vector<M>(n, 0)) {
        for(int i = 0; i < n; i++) next[0][i] = vec[i];
    }

    void AddEdge(const int from, const int to, const M cost = 0){
        next[0][from] = to; sum[0][from] = cost;
    }
    
    //O(NlogN)
    void Build(){
        for(int k = 0; k+1 < LOG; k++){
            for(int i  = 0; i < n; i++){
                if(next[k][i] == -1) next[k+1][i] = -1;
                else{
                    next[k+1][i] = next[k][next[k][i]];
                    sum[k+1][i] = sum[k][i]+sum[k][next[k][i]];
                }
            }
        }
    }

    //O(logN)
    int IndexQuery(const int from, long long cnt){
        int ret = from;
        for(int k = 0; cnt > 0; k++, cnt >>= 1){
            if(cnt & 1){
                if(next[k][ret] == -1){
                    while(next[0][ret] >= 0) ret = next[0][ret];
                    return ret;
                } else ret = next[k][ret];
            }
        }
        return ret;
    }
    M SumQuery(const int from, long long cnt){
        int index = from;
        M ret = 0;
        for(int k = 0; cnt > 0; k++, cnt >>= 1){
            if(cnt & 1){
                ret += sum[k][index];
                index = next[k][index];
            }
        }
        return ret;
    }
};