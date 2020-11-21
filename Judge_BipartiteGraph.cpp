#include <bits/stdc++.h>
using namespace std;

//計算量O(NM)
//1,-1で色分け

vector<int> color;
bool Bipartite(const vector<vector<int>> &v, int now, int now_color = 1) {
    color[now] = now_color;
    for(int nxt : v[now]){
        if(color[nxt] == now_color) return false;
        else if(color[nxt] == 0){
            if(!Bipartite(v, nxt, -now_color)) return false; 
        } 
    }
    return true;
}