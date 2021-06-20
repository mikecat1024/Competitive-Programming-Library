#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;



const int CMAX = 1e7;
long long fac[CMAX], finv[CMAX], inv[CMAX];
long long FAC(const int i){
    if(fac[i]) return fac[i];
    else if(i == 0 || i == 1) return fac[i] = 1;
    else return fac[i] = FAC(i-1) * i % mod;  
}
long long INV(const int i){
    if(inv[i]) return inv[i];
    else if(i == 1) return inv[i] = 1;
    else return inv[i] = mod - INV(mod%i) * (mod / i) % mod;
}
long long FINV(const int i){
    if(finv[i]) return finv[i];
    else if(i == 0 || i == 1) return finv[i] = 1;
    else return finv[i] = FINV(i-1) * INV(i) % mod;
}

long long COM(const int n, const int k) {
    if(n < k) return 0;
    if(n < 0 || k < 0) return -1;
    return FAC(n) * (FINV(k) * FINV(n-k) % mod) % mod;
}



int main(){

}