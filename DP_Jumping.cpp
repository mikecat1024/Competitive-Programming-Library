#include <bits/stdc++.h>
using namespace std;



template<typename M>
struct DP_Jumping {
    const long long INF = numeric_limits<long long>::max();
    const int h,w;
    vector<string> sur;
    vector<vector<M>> DP;
    vector<int> dy,dx;

    DP_Jumping (const int h_, const int w_, const vector<string> &sur_, const vector<int> &dy_, const vector<int> &dx_) 
    : h(h_), w(w_), sur(sur_), DP(h, vector<M>(w,0)), dy(dy_), dx(dx_) {}

    void Bulid(const pair<int,int> s, const int m = numeric_limits<int>::max()){
        M sum[dx.size()][h][w];
        DP[s.first][s.second] = 1;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(sur[i][j] == '#') continue;
                for(int k = 0; k < 3; k++){
                    if(i - dy[k] >= 0 && j - dx[k] >= 0){
                        sum[k][i][j] = sum[k][i-dy[k]][j-dx[k]] + DP[i-dy[k]][j-dx[k]];
                        if(i > m) sum[k][i][j] -= sum[k][i-(m+1)][j];
                        if(j > m) sum[k][i][j] -= sum[k][i][j-(m+1)];
                        DP[i][j] += sum[k][i][j];
                    }
                }
            }
        }
    }

};



int main(){
    return 0;
}