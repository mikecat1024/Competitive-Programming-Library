#include <bits/stdc++.h>
using namespace std;

//O(|S|)
// {S} -> length of the longest common prefix
//if vector[i] is 2, S.substr(0,2) = S.substr(i,2)
vector<int> Zalgorithm (const string& S) {
    vector<int> z((int)S.size()); z[0] = (int)S.size();

    for(int i = 1, j = 0, k = 0; i < (int)S.size(); i += k, j -= k, k = 0){
        while(i+j < (int)S.size() && S[j] == S[i+j]) j++;
        z[i] = j;
        if(j == 0) i -= k-1, j += k;
        else while(++k < j && k+z[k] < j) z[i+k] = z[k];
    }

    return z;
}

void ABC141_E_WhoSaysaPun(){
    int n; string S;
    cin >> n >> S;
    vector<vector<int>> can(n);
    int ans = 0;

    for(int i = 0; i < n; i++){
        string t = S.substr(i);
        can[i] = Zalgorithm(t);
        for(int j = 1; j < (int)can[i].size(); j++){
            if(j >= can[i][j]) ans = max(ans,can[i][j]);
        }
    }
    cout << ans << endl;
}

int main(){}