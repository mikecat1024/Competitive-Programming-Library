#include <bits/stdc++.h>
using namespace std;



struct UnionFind{
    private:
    vector<int> E;

    public:
    UnionFind(int n) : E(n,-1) {}

    int find(int x){
        if(E[x] < 0) return x;
        else return E[x] = find(E[x]);
    }

    bool unite(int x, int y){
        int rx = find(x), ry = find(y);
        if(rx == ry) return false;
        if(E[rx] > E[ry]) swap(rx,ry);
        E[rx] += E[ry];
        E[ry] = rx;
        return true;
    }

    bool same(int x, int y){
        if(find(x) == find(y)) return true;
        else return false;
    }

    int size(int x){
        return -E[find(x)];
    }
};



int main(){
    return 0;
}