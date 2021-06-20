#include <bits/stdc++.h>
using namespace std;



// O(RlogR)
// {L, R} -> the number of pair (x, y) in [L, R)
 vector<long long> GCDConvolution (const int L, const int R) {
     vector<long long> cnt(R);
     for(int i = R-1; i > 1; i--){
         cnt[i] = (long long)((R-1)/i-(L-1)/i) * ((R-1)/i-(L-1)/i);
         for(int j = 2*i; j < R; j += i) cnt[i] -= cnt[j];
     }
     return cnt;
 }



 void ABC206_E_DivideBoth () {
    int l, r;
    cin >> l >> r;

    vector<long long> gcdcnt = GCDConvolution(l, r+1);
    long long ans = 0;

    for(int i = 2; i <= r; i++){
        if(i < l) ans += gcdcnt[i];
        else ans += gcdcnt[i] -2*(r/i) + 1;
    }

    cout << ans << endl;
 }

 int main () {
     ABC206_E_DivideBoth ();
 }