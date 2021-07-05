#include <bits/stdc++.h>
using namespace std;



template<typename INT> struct SurfaceSearch {
private:
    vector<tuple<INT, INT, INT>> event;
    vector<tuple<INT, INT, int>> query;
    vector<INT> seen;

    template <typename Abel> struct BIT {
    private:
        int n;
        vector<Abel> data;

    public:
        BIT (const int N) : n(N+1), data(N+1, 0) {}

        void Add(const int i, const Abel X) {
            for(int k = i + 1; k < n; k += k & -k) data[k-1] += X;
        }
        Abel Sum(int R) {
            Abel ret = data[R-1];
            while(R > 0) ret += data[(R -= R & -R)-1];
            return ret;
        }
        Abel Sum(const int L, const int R) {
            return Sum(R) - Sum(L);
        }
        Abel Lower_bound(Abel w){
            Abel ret = 0; int k = 1;
            while(k < n) k <<= 1;
            for(int i = k; i > 0; i >>= 1){
                if(ret + i < n && data[ret+i-1] < w) w -= data[(ret += i)-1];
            }
            return w > 0 ? ret : 0;
        }
        Abel Upper_bound(const Abel w){
            return lower_bound(w + 1);
        }
        void debug(){
        for(int i = 0; i < n - 1; i++) cout << Sum(i, i+1) << ' ';
        cout << endl;
    }
    };

public:
    //add event on X for [L,R)
    void AddEvent(const INT L, const INT R, const INT X = 1){
        event.push_back(make_tuple(L, R, X));
        seen.push_back(R);
    }

    //add query on X
    void AddQuery(const INT L, const INT R, const int ID = 0){
        query.push_back(make_tuple(L, R, ID));
        seen.push_back(R);
    }

    vector<INT> Build(){ // 左下　イコール含む
        sort(seen.begin(), seen.end()); // O((M+N)log(M+N))
        seen.erase(unique(seen.begin(), seen.end()), seen.end());
        BIT<INT> tree((int)(seen.size())); 
        sort(event.begin(), event.end()/*, greater<tuple<INT, INT, INT>>()*/);
        sort(query.begin(), query.end()/*, greater<tuple<INT, INT, int>>()*/);

        cout << "seen" << endl;
        for(int i = 0; i < (int)seen.size(); i++){
            cout << seen[i] << " ";
        }
        cout << endl;

        cout << "event" << endl;
        for(int i = 0; i < (int)event.size(); i++){
            // cout << get<1>(event[i]) << " ";
            get<1>(event[i]) = seen.end() - lower_bound(seen.begin(), seen.end(), get<1>(event[i])) - 1;
            // get<1>(event[i]) = lower_bound(seen.begin(), seen.end(), get<1>(event[i])) - seen.begin();
            cout << get<1>(event[i]) << " ";
        }
        cout << endl;
        cout << "query" << endl;
        for(int i = 0; i < (int)query.size(); i++){
            // cout << get<1>(query[i]) << " ";
            get<1>(query[i]) = seen.end() - lower_bound(seen.begin(), seen.end(), get<1>(query[i])) - 1;
            // get<1>(query[i]) = lower_bound(seen.begin(), seen.end(), get<1>(query[i])) - seen.begin();
            cout << get<1>(query[i]) << " ";
        }
        cout << endl;

        vector<INT> ret((int)query.size());
        for(int i = 0, j = 0; i < (int)query.size(); i++){
            // while(j < (int)event.size() && get<0>(event[j]) >= get<0>(query[i])){
            //     tree.Add(get<1>(event[j]), get<2>(event[j]));
            //     cout << "!!!" << get<1>(event[j]) << " " << get<2>(event[j]) << endl;
            //     j++;
            // }
            while(j < (int)event.size() && get<0>(event[j]) <= get<0>(query[i])){
                tree.Add(get<1>(event[j]), get<2>(event[j]));
                cout << "!!!" << get<1>(event[j]) << " " << get<2>(event[j]) << endl;
                j++;
            }
            ret[get<2>(query[i])] = tree.Sum(get<1>(query[i])+1);
            tree.debug();
        }
        
        return ret;
    }
};

int main () {
    int n, m;
    cin >> n >> m;
    int q;
    cin >> q;

    SurfaceSearch<int> SS;
    for(int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        SS.AddEvent(l, r);
    }


    for(int i = 0; i < q; i++){
        int p, q;
        cin >> p >> q;
        SS.AddQuery(p, q, i);
    }

    vector<int> ans = SS.Build();

    for(int i = 0; i < q; i++){
        cout << ans[i] << endl;
    }
}

