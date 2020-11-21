#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;



template<typename M>
struct Calc_Cmb {
    const int MAX;
    vector<M> fac, finv, inv;

    Calc_Cmb (const int MAX_ = 1e7) : MAX(MAX_), fac(MAX, 1), finv(MAX, 1), inv(MAX, 1) {
        for(int i = 2; i < MAX; i++){
            fac[i] = fac[i-1]*i;
            inv[i] = mod-inv[mod%i]*(mod/i);
            finv[i] = finv[i-1]*inv[i];
        }
    }

    //Combination
    M C(const int n, const int k){
        if(n < k) return 0;
        if(n < 0 || k < 0) return 0;
        return fac[n]*finv[k]*finv[n-k];
    }
    //Permutation
    M P(const int n, const int k){
        if(n-k < 0 || k < 0) return 0;
        else return fac[n]*finv[n-k];
    }
};
