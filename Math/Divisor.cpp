#include <bits/stdc++.h>
using namespace std;



//O(\sqrt{X})
//{X} -> the list of divisor of X (from 1 to X)
template<typename T> vector<T> Divisor (T X) {
    vector<T> ret; stack<T> big;

    for(long long i = 1; i * i <= X; i++){
        if(X % i == 0){
            ret.push_back(i);
            if(X != i * i) big.push(X / i);
        }
    }
    while(!big.empty()){
        ret.push_back(big.top());
        big.pop();
    }

    return ret;
}