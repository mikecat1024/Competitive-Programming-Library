#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;



struct osa_k {
    vector<int> spf;

    //O(MAXloglogMAX)
    // if spf[i] < i, i is not prime number.
    osa_k (const int MAX = 1e7) : spf(MAX+1) {
        iota(spf.begin(), spf.end(), 0);
        for(long long i = 2; i * i <= MAX; i++){
            if(spf[i] == i){
                for(long long j = i * i; j <= MAX; j += i){
                    if(spf[j] == j) spf[j] = i;
                }
            }

        }
    }

    //O(logX)
    vector<int> Buildvector (int X) {
        vector<int> ret;
        while(X != 1){
            ret.push_back(spf[X]);
            X /= spf[X];
            // int tmp = spf[X];
            // while(tmp == spf[X]) X /= spf[X]; 
        }
        return ret;
    }

    //O((logX)^2)
    map<int,int> Buildmap (int X) {
        map<int,int> ret;
        while(X != 1){
            ret[spf[X]]++;
            X /= spf[X];
        } 
        return ret;
    }
    
};



int main(){

}