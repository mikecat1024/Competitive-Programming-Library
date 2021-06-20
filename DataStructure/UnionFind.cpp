#include <bits/stdc++.h>
using namespace std;



template<typename Abel> struct UnionFind {
private:
    struct Data {
        int rank; Abel weight;
        Data (const int rank, const Abel weight) : rank(rank), weight(weight) {}
    };

    vector<Data> data;

public:
    UnionFind (const int n, const Abel unit) : data(n, Data(-1, unit)) {}
    UnionFind (const int n) : UnionFind(n, 0) {}

    // {X} -> representative of G(X)
    int Find (const int X) {
        if(data[X].rank < 0) return X;
        int tmp = Find(data[X].rank);
        data[X].weight += data[data[X].rank].weight;
        return data[X].rank = tmp;
    }

    // {X, Y} -> if G(X) = G(Y) or not 
    bool Same (const int X, const int Y) {
        return Find(X) == Find(Y);
    }

    // {X, Y, W} -> marge G(X) and G(Y)
    bool Unite (int X, int Y, Abel W) {
        W += Weight(X)-Weight(Y);
        if((X = Find(X)) == (Y = Find(Y))) return false;
        if(data[X].rank > data[Y].rank) swap(X, Y), W = -W;
        data[X].rank += data[Y].rank;
        data[Y] = Data(X, W);
        return true;
    } bool Unite (const int X, const int Y) { return Unite(X, Y, 0); }

    // {X} -> |G(X)|
    int Size (const int X) {
        return -data[Find(X)].rank;
    }
    
    Abel Weight (const int X) {
        Find(X);
        return data[X].weight;
    }

    Abel Diff (const int X, const int Y) {
        return Weight(Y) - Weight(X);
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    //http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B

    int n, q;
    cin >> n >> q;

    UnionFind<int> tree(n);
    vector<string> ans;

    for(int i = 0; i < q; i++){
        int type, x, y;
        cin >> type >> x >> y;
        if(type == 0){
            int z; cin >> z;
            tree.Unite(x, y, z);
        } else if(tree.Find(x) == tree.Find(y)){
            ans.push_back(to_string(tree.Diff(x, y)));
        } else ans.push_back("?");
    }

    for(auto p:ans) cout << p << endl;
}