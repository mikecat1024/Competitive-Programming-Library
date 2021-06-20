#include <bits/stdc++.h>
using namespace std;



const int CMAX = 67;
long long COMBINATION[CMAX][CMAX]; bool NOinit = true;
//{N, K} -> iom(N, K) (1 <= N, K <= 66)
long long COM (const int N, int K) {
    if(NOinit){
        for(int i = 0; i < CMAX; i++){
            for(int j = 0; j < CMAX; j++) COMBINATION[i][j] = -1;
        }
        NOinit = false;
    }
    if(N < K) return -1;
    else if(K == 0 || N == K) return 1;
    else if(COMBINATION[N][min(K,N-K)] >= 0) return COMBINATION[N][min(K,N-K)];
    else return COMBINATION[N][K] = COM(N - 1, K - 1) + COM(N - 1, K);
}



int main(){

}