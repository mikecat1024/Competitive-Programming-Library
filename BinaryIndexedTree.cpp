#include <bits/stdc++.h>
using namespace std;



template<typename T>
class BIT {
    const int n;
    vector<T> dt;

    public:
    BIT (const int n_) : n(n_+1), dt(n+1, 0) {}
    BIT (const vector<T> vec) : n((int)vec.size()), dt(n+1, 0) {
        for(int i = 0; i < n; i++) add(i,vec[i]);
    }

    T operator [] (int k) { return sum(k+1)-sum(k); }

    //0-indexed 普通に入れれるようにしといたでby過去の自分
    //O(logn)
    void add (const int i, const T x) {
        for(int k = i+1; k < n+1; k += k&-k) dt[k] += x;
    }

    //O(logn)
    T sum (const int i) {
        long long ret = 0;
        for(int k = i; k > 0; k -= k&-k) ret += dt[k];
        return ret;
    }
    T sum (const int a, const int b) {
        return sum(b)-sum(a);
    }

};
