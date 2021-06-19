#include <bits/stdc++.h>
using namespace std;

// O(|S||T|)
// {S, T} -> Longest Common Subsequence
template<typename V> string LCS(const V& S, const V& T){
    int s = S.size(), t = T.size(); 
    int dp[s+1][t+1] = {};
    V ret;

    for(int i = 0; i < s; i++){
        for(int j = 0; j < t; j++){
            if(S[i] == T[j]) dp[i+1][j+1] = dp[i][j] + 1;
            else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
        }
    }

    for(int k = dp[s][t]; k > 0; k--, s--, t--){
        while(s > 0 && dp[s][t] == dp[s-1][t]) s--;
        while(t > 0 && dp[s][t] == dp[s][t-1]) t--;
        ret.push_back(S[s-1]);
    }
    reverse(ret.begin(), ret.end());
    
    return ret;
}

void EDPC_F_LCS(){
    //https://atcoder.jp/contests/dp/tasks/dp_f
    string s, t;
    cin >> s >> t;
    cout << LCS(s, t) << endl;
}

int main(){
    EDPC_F_LCS();
}