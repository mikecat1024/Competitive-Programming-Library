#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;



//{{A_n}} -> Σ_{i = 0}^{N-1}Σ_{j = i+1}^{N} A_i xor A_j (mod mod)
long long XorSum (vector<long long>& A){
    long long powers[63], ret = 0; powers[0] = 1; powers[1] = 2;
    for(int i = 1; i < 62; i++) powers[i+1] = 2 * powers[i] % mod; 

    for(int i = 0; i < 63; i++){
        long long bit = 0;
        for(int j = 0; j < (int)A.size(); j++) if(A[j] >> i & 1) bit++;
        ret += powers[i] * (bit * ((int)A.size() - bit) % mod) %mod;
        ret %= mod;
    }
    return ret;
}



int main(){

}