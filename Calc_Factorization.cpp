#include <bits/stdc++.h>
using namespace std;



const int Max = 1e7;
vector<int> mps(Max+1);

//O(NloglogN)
void MpsInit(){
    for(int i = 0; i <= Max; i++) mps[i] = i;
    for(long long i = 2; i*i <= Max; i++){
        if(mps[i] == i){
            for(long long j = i*i; j <= Max; j += i){
                if(mps[j] == j) mps[j] = i;
            }
        }
    }
}
//O(logN)
vector<int> PrimeFactorization(int n){
    vector<int> ret;
    while(n != 1){
        ret.push_back(mps[n]);
        n /= mps[n];
    }
    return ret;
}

//O(√N)
template<typename T>
vector<T> Diviser(T x){
    vector<T> ret;
    for(T i = 1; i*i <= x; i++){
        if(x%i == 0){
            ret.push_back(i);
            if(x/i != i) ret.push_back(x/i);
        }
    }
    sort(ret.begin(),ret.end());
    return ret;
}

//O(√N)
template<typename T>
vector<T> PrimeDiviser(T x){
    vector<T> ret;
    for(T i = 2; i*i <= x; i++){
        if(x%i == 0){
            while(x%i == 0){
                ret.push_back(i);
                x /= i;
            }
        }
    }
    if(x != 1) ret.push_back(x);
    return ret;
}