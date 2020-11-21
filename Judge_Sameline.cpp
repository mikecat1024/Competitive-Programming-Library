#include <bits/stdc++.h>
using namespace std;



bool SameLine(pair<int,int> a, pair<int,int> b, pair<int,int> c){
    int r = (a.first-b.first)*(b.second-c.second);
    int l = (b.first-c.first)*(a.second-b.second);
    if(l == r) return true;
    else return false;
}