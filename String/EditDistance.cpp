#include <bits/stdc++.h>
using namespace std;

const int DELETE_COST = 1, INSERT_COST = 1, CHANGE_COST = 1;
template<typename V> long long EditDistance (const V& S, const V& T) {
    long long dp[(int)S.size()+1][(int)T.size()+1];
    for(int i = 0; i <= (int)S.size(); i++) dp[i][0] = i;
    for(int j = 0; j <= (int)T.size(); j++) dp[0][j] = j;
    for(int i = 1; i <= (int)S.size(); i++){
        for(int j = 1; j <= (int)T.size(); j++){
            int del = dp[i-1][j] + DELETE_COST;
            int ins = dp[i][j-1] + INSERT_COST;
            int cha = dp[i-1][j-1] + (S[i-1] != T[j-1])*CHANGE_COST;
            dp[i][j] = min({del, ins, cha});
        }
    }

    return dp[(int)S.size()][(int)T.size()];
}

void ABC185_E_SequenceMatching(){
    int n, m;
    cin >> n >> m;
    vector<int> s(n),t(m);

    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < m; i++) cin >> t[i];

    cout << EditDistance(s,t) << endl;
}

int main(){
    ABC185_E_SequenceMatching();
}