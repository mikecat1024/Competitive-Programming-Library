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

    int Find (const int x) {
        if(data[x].rank < 0) return x;
        int tmp = Find(data[x].rank);
        data[x].weight += data[data[x].rank].weight;
        return data[x].rank = tmp;
    }

    bool Same (const int x, const int y) {
        return Find(x) == Find(y);
    }

    bool Unite (int x, int y, Abel w) {
        w += Weight(x)-Weight(y);
        if((x = Find(x)) == (y = Find(y))) return false;
        if(data[x].rank > data[y].rank) swap(x, y), w = -w;
        data[x].rank += data[y].rank;
        data[y] = Data(x, w);
        return true;
    } bool Unite (const int x, const int y) { return Unite(x, y, 0); }

    int Size (const int x) {
        return -data[Find(x)].rank;
    }
    
    Abel Weight (const int x) {
        Find(x);
        return data[x].weight;
    }

    Abel Diff (const int x, const int y) {
        return Weight(y) - Weight(x);
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