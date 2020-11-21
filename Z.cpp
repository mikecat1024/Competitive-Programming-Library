#include <bits/stdc++.h>
using namespace std;

//O(|S|)
//共通接頭辞の長さを返す

vector<int> Z (const string& s) {
    vector<int> z((int)s.size());
    z[0] = (int)s.size();

    for(int i = 1, j = 0, k = 0; i < (int)s.size(); i += k, j -= k, k = 0){
        while(i+j < (int)s.size() && s[j] == s[i+j]) j++;
        z[i] = j;
        if(j == 0) i -= k-1, j += k;
        else while(++k < j && k+z[k] < j) z[i+k] = z[k];
    }

    return z;
}