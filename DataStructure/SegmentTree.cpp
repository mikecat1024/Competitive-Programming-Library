#include <bits/stdc++.h>
using namespace std;


template<typename Monoid> struct SegmentTree {
    using F = function<Monoid(Monoid, Monoid)>;

private:
    F o;
    int length = 1;
    Monoid e;
    vector<Monoid> data;

    void init(const int N){
        while(length <= N) length <<= 1;
        data.assign(length << 1, e);
    }

public:
    SegmentTree(const int N, const F O, const Monoid E = 0) : o(O), e(E) { init(N); } 
    SegmentTree(const vector<Monoid> &VEC, const F O, const Monoid E = 0) : o(O), e(E) {
        init((int)VEC.size());
        for(int i = 0; i < (int)VEC.size(); i++) data[i+length] = VEC[i];
        for(int i = length-1; i > 0; i--) data[i] = o(data[i<<1], data[i<<1|1]);
    }

    Monoid operator [] (const int i) { return query(i, i+1); }

    // {K, X} -> data[K] = X
    void update(int K, const Monoid X){
        data[K+=length] = X;
        while(K >>= 1) data[K] = o(data[K<<1], data[K<<1|1]);
    }

    // {L, R} -> o(data[[L, R)]) 
    Monoid query(int L, int R){
        Monoid l = e, r = e;
        for(L += length, R += length; L < R; L >>= 1, R >>= 1){
            if(L & 1) l = o(l, data[L++]);
            if(R & 1) r = o(data[--R], r);
        }
        return o(l, r);
    }

    void print(const int N) {
        for(int i = 0; i < N; i++){
            cout << data[i + length] << ' ';
        }
        cout << '\n';
    }
};

void AOJ_RangeMinimumQuery(){
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A

    int n, q;
    cin >> n >> q;

    SegmentTree<int> tree(n, [](int a, int b){ return min(a, b); }, numeric_limits<int>::max());
    
    for(int i = 0; i < q; i++){
        int com, x, y;
        cin >> com >> x >> y;
        if(com == 0) tree.update(x, y);
        else cout << tree.query(x, y+1) << '\n';
    }
}

void LC_StaticRangeSum(){
    //https://judge.yosupo.jp/problem/static_range_sum

    int n, q;
    cin >> n >> q;

    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    SegmentTree<long long> tree(a, [](const long long a, const long long b){ return a + b; }, 0);

    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        cout << tree.query(l, r) << '\n';
    }
}

void AOJ_RangeSumQuery(){
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B

    int n, q;
    cin >> n >> q;

    SegmentTree<int> tree(n, [](const int a, const int b){ return a+b; }, 0);

    for(int i = 0; i < q; i++){
        int com, x, y;
        cin >> com >> x >> y;
        x--;
        if(com == 0) tree.update(x, y+tree[x]);
        else cout << tree.query(x, y) << '\n'; 
    }
}

void ABC185_F_RangeXorQuery(){
    //https://atcoder.jp/contests/abc185/tasks/abc185_f
    
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    SegmentTree<int> tree(a, [](const int a, const int b) { return a ^ b; }, 0);

    for(int i = 0; i < q; i++){
        int t, x, y;
        cin >> t >> x >> y;
        x--;
        if(t == 1) tree.update(x, y^tree[x]);
        else cout << tree.query(x, y) << '\n';
    }
}

void ABC186_F_RookonGrid(){
    //https://atcoder.jp/contests/abc186/tasks/abc186_f
    int h, w, m;
    cin >> h >> w >> m;

    vector<vector<int>> z(h);
    vector<int> wp(w, h);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        z[x].push_back(y);
        wp[y] = min(x, wp[y]);
    }

    for(int i = 0; i < h; i++){
        if(z[i].size() == 0) continue;
        sort(z[i].begin(), z[i].end());
    }

    long long ans = 0;
    for(int i = 0; i < w; i++){
        if(z[0].size() != 0 && i == z[0][0]) break;
        ans += wp[i];
    }

    SegmentTree<int> tree(w, [](const int a, const int b){return a+b;}, 0);
    if(z[0].size() != 0){
        for(int i = z[0][0]; i < w; i++){
            tree.update(i, 1);
        }
    }

    for(int i = 1; i < h; i++){
        if(z[i].size() == 0){
            ans += tree.query(0,w);
            continue;
        } else if(z[i][0] == 0) break;

        ans += tree.query(0, z[i][0]);

        for(int j = 0; j < (int) z[i].size(); j++){
            if(!tree[z[i][j]]) tree.update(z[i][j], 1);
        }
    }

    cout << ans << '\n';
}

void LC_PointAddRangeSum(){
    //https://judge.yosupo.jp/problem/point_add_range_sum

    int n, q;
    cin >> n >> q;

    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    SegmentTree<long long> tree(a, [](const long long a, const long long b){return a+b ;}, 0);

    for(int i = 0; i < q; i++){
        int t, x, y;
        cin >> t >> x >> y;
        if(t == 0) tree.update(x, y+tree[x]);
        else cout << tree.query(x, y) << '\n';
    }
}

void LC_StaticRMQ(){
    //https://judge.yosupo.jp/problem/staticrmq

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    SegmentTree<int> tree(a, [](const int a, const int b){return min(a, b);}, numeric_limits<int>::max());

    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        cout << tree.query(l, r) << '\n';
    }

}

int main () {
    LC_PointAddRangeSum();
}

