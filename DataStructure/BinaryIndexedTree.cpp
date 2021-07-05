#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;

template <typename Abel> struct BIT {
private:
    int n;
    vector<Abel> data;

public:
    BIT (const int N) : n(N+1), data(N+1, 0) {}

    // O(logN)
    // {i, X} -> add X at vec[i]
    void Add(const int i, const Abel X) {
        for(int k = i + 1; k < n; k += k & -k) data[k-1] += X;
    }
    // {R} -> sum of [0, R)
    Abel Sum(int R) {
        Abel ret = data[R-1];
        while(R > 0){
            ret += data[(R -= R & -R)-1];
        }
        return ret;
    }
    // {L, R} -> sum of [L, R)
    Abel Sum(const int L, const int R) {
        return Sum(R) - Sum(L);
    }
    // this needs all values in data are positive
    Abel Lower_bound(Abel w){
        Abel ret = 0; int k = 1;
        while(k < n) k <<= 1;
        for(int i = k; i > 0; i >>= 1){
            if(ret + i < n && data[ret+i-1] < w){
                w -= data[(ret += i)-1];
            }
        }
        return w > 0 ? ret : 0;
    }
    Abel Upper_bound(const Abel w){
        return lower_bound(w + 1);
    }

    void debug(){
        for(int i = 0; i < n - 1; i++) cout << Sum(i, i+1) << ' ';
        cout << endl;
    }
};

struct Xor {
        int x;
        Xor(int x_) : x(x_) {} 
        Xor operator - (const Xor& other) const { return Xor(x ^ other.x); }
        Xor operator += (const Xor& other) { x ^= other.x; return *this; }
};

void ABC185_F_RangeXorQuery(){
    //https://atcoder.jp/contests/abc185/tasks/abc185_f
    int n, q;
    cin >> n >> q;
    BIT<Xor> tree(n);

    for(int i = 0; i < n; i++){
        int a; cin >> a;
        tree.Add(i, Xor(a));
    }

    for(int i = 0; i < q; i++){
        int t,x,y;
        cin >> t >> x >> y;
        x--;
        if(t == 1) tree.Add(x,Xor(y));
        else cout << tree.Sum(x, y).x << '\n';
    }
}

void ARC033_C_DataStructure(){
    //https://atcoder.jp/contests/arc033/tasks/arc033_3

    int q;
    cin >> q;
    BIT<int> tree(200000);

    for(int i = 0; i < q; i++){
        int t, x;
        cin >> t >> x;
        if(t == 1) tree.Add(x-1, 1);
        else{
            int ans = tree.Lower_bound(x)+1;
            cout << ans << '\n';
            tree.Add(ans-1, -1);
        }
    }
}

void LC_StaticRangeSum(){
    //https://judge.yosupo.jp/problem/static_range_sum

    int n, q;
    cin >> n >> q;

    BIT<long long> tree(n);

    for(int i = 0; i < n; i++){
        int a; cin >> a;
        tree.Add(i, a);
    }

    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        cout << tree.Sum(l, r) << '\n';
    }
}

void LC_PointAddRangeSum(){
    //https://judge.yosupo.jp/problem/point_add_range_sum

    int n, q;
    cin >> n >> q;
    
    BIT<long long> tree(n);

    for(int i = 0; i < n; i++){
        int a; cin >> a;
        tree.Add(i, a);
    }

    for(int i = 0; i < q; i++){
        int t, x, y;
        cin >> t >> x >> y;
        if(t == 0) tree.Add(x, y);
        else cout << tree.Sum(x, y) << '\n';
    }
}


int main(){
    BIT<int> tree(4);
    tree.Add(3, 1);
    tree.Add(2, 1);
    tree.Add(0, 1);
    tree.debug();
}