#include <bits/stdc++.h>
using namespace std;

template<typename T> struct EventSort {
    vector<tuple<T, bool, T>> event;
    vector<T> query, ans;

    EventSort (const int Q) : ans(Q) {}

    int operator [] (const int i) { return ans[i]; }

    //add event on X for [L,R)
    void AddEvent(const T L, const T R, const T X){
        event.push_back(make_tuple(L, true, X));
        event.push_back(make_tuple(R, false, X));
    }

    //add query on X
    void AddQuery(const T X){
        query.push_back(X);
    }

    void Build(){
        sort(event.begin(), event.end());
        sort(query.begin(), query.end());

        multiset<int> state;
        for(int i = 0, j = 0; i < (int)query.size(); i++){
            while(j < (int)event.size() && get<0>(event[j]) <= query[i]){
                if(get<1>(event[j])) state.insert(get<2>(event[j++])); // for example if you want to get the sum of state, you can change this area.
                else state.erase(state.find(get<2>(event[j++]))); // in this area, state is changing.
                // if(get<1>(event[j])) sum += get<2>(event[j++]); // this is a sample of sum.
                // else sum -= get<2>(event[j++]);
            }

            if(state.empty()) ans[i] = -1;
            else ans[i] = *state.begin(); //get minimum value in state.
        }
    }
};

int main () {

}

