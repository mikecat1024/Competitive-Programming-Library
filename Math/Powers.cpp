#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;


//{X, N} -> X^N (mod mod)
// if you  want to get inverse element of A, do Powers(A, M-2) (it is required M is prime number)
long long Powers (long long X, long long N) {
    long long E[62], ret = 1; E[0] = X;
    for(int i = 1; i < 62; i++) E[i] = E[i-1] * E[i-1] % mod;
    for(int i = 62; i >= 0; i--) if(N & (1LL << i)) ret *= E[i], ret %= mod;
    return ret;
}